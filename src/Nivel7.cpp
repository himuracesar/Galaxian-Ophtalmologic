#include "Nivel7.h"

Nivel7::Nivel7()
{
	ss.str("");
	pCamera = DOGNULL;
	pXml = DOGNULL;
	vxPlayer = vyBullet = velEnemy = seconds = timeToPlay = velEnemyBullet = 0.0f;
	troopCount = state = idBulletEnemy = 0;
	play = false;
	pPlayer = pBullet = DOGNULL;
	pEnemigos = DOGNULL; 
	pCollisionManager = DOGNULL;
	pExplosions = DOGNULL;
	pHeadsUp = DOGNULL;
	pText = DOGNULL;
	pASexplosion = DOGNULL;
	colorFondo = BLACK;
	pTextAdditional = DOGNULL;
	pScores = DOGNULL;
}

Nivel7::~Nivel7()
{
	Release();
}

DOGRESULT Nivel7::Init()
{
	cout << "init Nivel 7" << endl;

	pCamera = new Camera2D(0.0f, GetWidth(), GetHeight(), 0.0f, -1.0f, 1.0f);
	pCamera->SetInvertY(true);

	DOGSCENE->SetActiveCamera(pCamera);

	pXml = new XMLParser();
	pXml->Init("glx/xml/config.xml");

	colorFondo.r = pXml->GetDataf("/GALAXIAN/COLOR_FONDO/R");
	colorFondo.g = pXml->GetDataf("/GALAXIAN/COLOR_FONDO/G");
	colorFondo.b = pXml->GetDataf("/GALAXIAN/COLOR_FONDO/B");
	colorFondo.a = pXml->GetDataf("/GALAXIAN/COLOR_FONDO/A");

	pPlayer = new Sprite("glx/img/nave2.0.png", 66, 42);
	pPlayer->SetXPosition(GetWidth() / 2.0f);
	pPlayer->SetYPosition(GetHeight() - HEIGHT_MARGIN);
	pPlayer->SetId(ID_PLAYER);
	pPlayer->CreateBoundingCircle(pPlayer->GetWidth() / 2.0f, pPlayer->GetXPosition(), pPlayer->GetYPosition());
	pPlayer->SetCollisionable(true);
	/*pPlayer->SetRenderBounding(true);
	pPlayer->SetColorBounding(RED);*/

	vxPlayer = pXml->GetDataf("/GALAXIAN/VELOCITY_PLAYER");
	vyBullet = 1.5f;

	velEnemy = 0.5f;
	velEnemyBullet = 2.0f;

	idBulletEnemy = ID_BULLET_ENEMY;

	pBullet = DOGNULL;
	pASexplosion = DOGNULL;

	pHeadsUp = new HeadsUp();
	pHeadsUp->Init();
	pHeadsUp->SetNivel(7);
	pHeadsUp->SetColor(colorFondo);
	//pHeadsUp->SetVidas(2);

	//Colisiones 
	pCollisionManager = new CollisionManager();
	pCollisionManager->CreateCollisionGroup(PLAYER_GROUP);
	pCollisionManager->GetCollisionGroup(PLAYER_GROUP)->Add(pPlayer);

	pCollisionManager->CreateCollisionGroup(ENEMY_GROUP);

	troopCount = 1;
	if(GetWidth() > 1299)
		IniciaTropa(true);
	else
		IniciaTropa(false);

	pCollisionManager->AddCollisionRelation(RELATIONSHIP_PLAYER_ENEMY, PLAYER_GROUP, ENEMY_GROUP);

	pExplosions = new vector<ParticleSystemGL*>();

	CreateExplosion();

	srand(time(0));

	play = false;

	timeToPlay = 0.0f;
	seconds = 0.0f;

	/*pParticle = new ExplosionParticle("glx/fxgl/Explosion_VS.glsl", "glx/fxgl/Explosion_FS.glsl", "textures/NeGeo.png", DOGVECTOR3(150.0f, 100.0f, 0.0f), 100, 0.0f);
	pParticle->TranslateAbs(200.0f, 300.0f, 0.0f);
	pParticle->InitParticles();*/

	pText = new TextSDL("glx/fonts/PressStart2P.ttf");
	pText->SetSize(40);
	pText->SetFlipV(true);

	state = STATE_CHANGE_TROOP;

	pSound = unique_ptr<Sound>(new Sound());
	pSound->Init();
	pSound->PlayMusic();

	return DOG_OK;
}

DOGvoid Nivel7::Release()
{
	DOG_SAFE_DELETE(pPlayer);
	DOG_SAFE_DELETE(pCamera);
	DOG_SAFE_DELETE(pBullet);

	for (auto i = 0; i < pEnemigos->size(); i++)
	{
		DOG_SAFE_DELETE((*pEnemigos)[i]);
	}

	pEnemigos->clear();
	DOG_SAFE_DELETE(pEnemigos);
	DOG_SAFE_DELETE(pCollisionManager);

	if (pExplosions != DOGNULL)
	{
		for (auto iExplosion = 0; iExplosion < pExplosions->size(); iExplosion++)
		{
			DOG_SAFE_DELETE((*pExplosions)[iExplosion]);
		}
		pExplosions->clear();
		DOG_SAFE_DELETE(pExplosions);
	}

	DOG_SAFE_DELETE(pXml);
	DOG_SAFE_DELETE(pHeadsUp);
	DOG_SAFE_DELETE(pASexplosion);
	DOG_SAFE_DELETE(pText);
}

DOGvoid Nivel7::Update(DOGfloat elapsedTime)
{
	if (play)
	{
		//Actualiza el player
		pPlayer->Update(elapsedTime);

		//Actualiza la bala del enemigo
		if (pBullet != DOGNULL)
		{
			if (pBullet->GetYPosition() > 0.0f)
			{
				pBullet->Update(elapsedTime);
			}
			else
			{
				pCollisionManager->GetCollisionGroup(PLAYER_GROUP)->Delete(pBullet);
				DOG_SAFE_DELETE(pBullet);
			}
		}

		//actualiza enemigos
		for (auto iEnemy = 0; iEnemy < pEnemigos->size(); iEnemy++)
		{
			(*pEnemigos)[iEnemy]->Update(elapsedTime);
			if ((*pEnemigos)[iEnemy]->IsFire())
			{
				(*pEnemigos)[iEnemy]->SetFire(false);
				(*pEnemigos)[iEnemy]->SetXPlayer(pPlayer->GetXPosition());

				Sprite* ps = new Sprite("glx/img/bullet8x8.png", 8, 8);
				ps->SetXPosition((*pEnemigos)[iEnemy]->GetSprite()->GetXPosition());
				ps->SetYPosition((*pEnemigos)[iEnemy]->GetSprite()->GetYPosition() + (*pEnemigos)[iEnemy]->GetSprite()->GetHeight() / 2.0f);
				ps->SetVy(velEnemyBullet);
				ps->SetId(idBulletEnemy++);
				ps->SetCollisionable(true);
				ps->CreateBoundingCircle();

				pCollisionManager->GetCollisionGroup(ENEMY_GROUP)->Add(ps);

				vEnemyBullets.push_back(ps);

				pSound->PlayBullet();
			}
			
			//Cambia de estado al enemigo a que regrese
			if ((*pEnemigos)[iEnemy]->GetSprite()->GetYPosition() > GetHeight())
			{
				(*pEnemigos)[iEnemy]->Attack(false);
				(*pEnemigos)[iEnemy]->Return();
			}
		}

		//Se actualizan las balas de los enemigos
		for (auto iBullet = 0; iBullet < vEnemyBullets.size(); iBullet++)
		{
			vEnemyBullets[iBullet]->Update(elapsedTime);
			if (vEnemyBullets[iBullet]->GetYPosition() > GetHeight())
			{
				pCollisionManager->GetCollisionGroup(ENEMY_GROUP)->Delete(vEnemyBullets[iBullet]);
				DOG_SAFE_DELETE(vEnemyBullets[iBullet]);
				vEnemyBullets.erase(vEnemyBullets.begin() + iBullet);
			}
		}

		//Se evaluan las colisiones
		pCollisionManager->CheckCollisions();
 		if (pCollisionManager->GetCollisions() != DOGNULL)
		{
			//TODO Falta evaluar la colsion con el player
			for (auto iCollision = 0; iCollision < pCollisionManager->GetCollisions()->size(); iCollision++)
			{
				if ((*pCollisionManager->GetCollisions())[iCollision].sp1->GetIdCollisionGroup() == ENEMY_GROUP)
				{
					//Colision de nave enemiga
					if ((*pCollisionManager->GetCollisions())[iCollision].sp1->GetId() < ID_BULLET_ENEMY)
					{
						Explote((*pCollisionManager->GetCollisions())[iCollision].sp1->GetXPosition(),
							(*pCollisionManager->GetCollisions())[iCollision].sp1->GetYPosition(), 0.0f);
						//pCollisionManager->GetCollisionGroup(ENEMY_GROUP)->Delete((*pCollisionManager->GetCollisions())[iCollision].sp1);
						//DeleteEnemy((*pCollisionManager->GetCollisions())[iCollision].sp1->GetId());
						//DOG_SAFE_DELETE((*pCollisionManager->GetCollisions())[iCollision].sp1);
						pHeadsUp->SetPoints(pHeadsUp->GetPoints() + POINTS_KILL);
					}
					else
					{
						//colision de bala enemiga
						(*pCollisionManager->GetCollisions())[iCollision].sp1->SetDead(true);
					}
					pCollisionManager->GetCollisionGroup(ENEMY_GROUP)->Delete((*pCollisionManager->GetCollisions())[iCollision].sp1);
					DeleteEnemy((*pCollisionManager->GetCollisions())[iCollision].sp1->GetId());

					if ((*pCollisionManager->GetCollisions())[iCollision].sp2->GetId() == ID_BULLET_PLAYER)
					{
						pCollisionManager->GetCollisionGroup(PLAYER_GROUP)->Delete((*pCollisionManager->GetCollisions())[iCollision].sp2);
						//DOG_SAFE_DELETE((*pCollisionManager->GetCollisions())[iCollision].sp2);
						DOG_SAFE_DELETE(pBullet);
						//pBullet = DOGNULL;
					}
					else
					{
						//colision con la nave
						if (pASexplosion == DOGNULL)
						{
							pASexplosion = new AnimatedSprite("glx/img/explosion2.png", 4, 4, true);
							pASexplosion->TranslateAbs(pPlayer->GetXPosition(), pPlayer->GetYPosition(), 0.0f);
							pASexplosion->SetTotalLoopAnimation(1);
							pASexplosion->SetTimeAnimation(0.05f);

							state = STATE_REVENANT;
							timeToPlay = 0.0f;

							pPlayer->SetCollisionable(false);
						}
						CheckLifes();
					}

					pSound->PlayExplosion();
				}

				if ((*pCollisionManager->GetCollisions())[iCollision].sp2->GetIdCollisionGroup() == ENEMY_GROUP)
				{
					if ((*pCollisionManager->GetCollisions())[iCollision].sp2->GetId() < ID_BULLET_ENEMY)
					{
						Explote((*pCollisionManager->GetCollisions())[iCollision].sp2->GetXPosition(),
							(*pCollisionManager->GetCollisions())[iCollision].sp2->GetYPosition(), 0.0f);
						//pCollisionManager->GetCollisionGroup(ENEMY_GROUP)->Delete((*pCollisionManager->GetCollisions())[iCollision].sp2);
						//DeleteEnemy((*pCollisionManager->GetCollisions())[iCollision].sp2->GetId());
						//DOG_SAFE_DELETE((*pCollisionManager->GetCollisions())[iCollision].sp2);
						pHeadsUp->SetPoints(pHeadsUp->GetPoints() + POINTS_KILL);
					}
					else
					{
						(*pCollisionManager->GetCollisions())[iCollision].sp2->SetDead(true);
					}
					pCollisionManager->GetCollisionGroup(ENEMY_GROUP)->Delete((*pCollisionManager->GetCollisions())[iCollision].sp2);
					DeleteEnemy((*pCollisionManager->GetCollisions())[iCollision].sp2->GetId());

					if ((*pCollisionManager->GetCollisions())[iCollision].sp1->GetId() == ID_BULLET_PLAYER)
					{
						pCollisionManager->GetCollisionGroup(PLAYER_GROUP)->Delete((*pCollisionManager->GetCollisions())[iCollision].sp1);
						//DOG_SAFE_DELETE((*pCollisionManager->GetCollisions())[iCollision].sp1);
						DOG_SAFE_DELETE(pBullet);
						//pBullet = DOGNULL;
					}
					else
					{
						//Colision con la nave
						if (pASexplosion == DOGNULL)
						{
							pASexplosion = new AnimatedSprite("glx/img/explosion2.png", 4, 4, true);
							pASexplosion->TranslateAbs(pPlayer->GetXPosition(), pPlayer->GetYPosition(), 0.0f);
							pASexplosion->SetTotalLoopAnimation(1);
							pASexplosion->SetTimeAnimation(0.05f);

							state = STATE_REVENANT;
							timeToPlay = 0.0f;

							pPlayer->SetCollisionable(false);
						}
						CheckLifes();
					}
					pSound->PlayExplosion();
				}
			}
		}//if checkCollisions

		 //Explosions!
		for (auto iExplosion = 0; iExplosion < pExplosions->size(); iExplosion++)
		{
			if (!(*pExplosions)[iExplosion]->IsDead())
			{
				(*pExplosions)[iExplosion]->Update(elapsedTime);
			}
		}

		//pParticle->Update(elapsedTime);
		pHeadsUp->Update(elapsedTime);

		if (pEnemigos->empty() && troopCount < TROOPS)
		{
			if (CheckExplosionLive())
			{
				troopCount++;
				play = false;
				timeToPlay = 0.0f;
				if (GetWidth() > 1299)
					IniciaTropa(true);
				else
					IniciaTropa(false);
				state = STATE_CHANGE_TROOP;
			}
		}

		if (pEnemigos->empty() && troopCount == TROOPS) 
		{
			if (CheckExplosionLive())
			{
				play = false;
				state = STATE_FINISH;
			}
		}

		//Se elige un atacante
		if(!pEnemigos->empty())
		{
			seconds += elapsedTime;
			if (seconds >= ATTACK)
			{
				seconds = 0.0f;
				DOGint inx = 0;
				inx = DOGRandomNumber(0, pEnemigos->size() - 1);

				inx = inx < pEnemigos->size() ? inx : 0;
				(*pEnemigos)[inx]->SetVy(velEnemy);
				if ((*pEnemigos)[inx]->GetSprite()->GetXPosition() < GetWidth() / 2.0f)
				{
					(*pEnemigos)[inx]->SetVx(-velEnemy);
				}
				else
				{
					(*pEnemigos)[inx]->SetVx(velEnemy);
				}
				(*pEnemigos)[inx]->Attack(true);
			}
		}

		if (state == STATE_REVENANT)
		{
			seconds = 0.0f;
			timeToPlay += elapsedTime;
			if (timeToPlay >= 3.0f)
			{
				state = STATE_PLAY;
				pPlayer->SetXPosition(GetWidth() / 2.0f);
				pPlayer->SetCollisionable(true);
			}

			if (pASexplosion != DOGNULL)
			{
				pASexplosion->Update(elapsedTime);
				timeToPlay = 0.0f;
				if (!pASexplosion->IsAnimate())
				{
					DOG_SAFE_DELETE(pASexplosion);
				}
			}
		}//if STATE_REVENANT
	}//if play
	else
	{
		if (state != STATE_FINISH && state != STATE_GAME_OVER)
		{
			timeToPlay += elapsedTime;
			play = timeToPlay >= 3 ? true : false;
			state = play ? STATE_PLAY : state;

			/*pText->SetXPosition(GetWidth() / 2.0f - pText->GetWidth() / 2.0f);
			pText->SetYPosition(GetHeight() / 2.0f - pText->GetHeight() / 2.0f);*/
			//pText->SetYPosition(pPlayer->GetYPosition() - 400.0f);
		}
		pText->Update(elapsedTime);

		if (pTextAdditional != DOGNULL)
			pTextAdditional->Update(elapsedTime);
	}
}

DOGvoid Nivel7::Render() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(colorFondo.r, colorFondo.g, colorFondo.b, colorFondo.a);

	if(state != STATE_REVENANT)
		pPlayer->Render();

	if (pBullet != DOGNULL)
	{
		pBullet->Render();
	}

	for (auto iEnemy = 0; iEnemy < pEnemigos->size(); iEnemy++)
	{
		(*pEnemigos)[iEnemy]->Render();
	}

	for (auto iBullet = 0; iBullet < vEnemyBullets.size(); iBullet++)
	{
		vEnemyBullets[iBullet]->Render();
	}

	//Explosions!
	for (auto iExplosion = 0; iExplosion < pExplosions->size(); iExplosion++)
	{
		if (!(*pExplosions)[iExplosion]->IsDead())
		{
			(*pExplosions)[iExplosion]->Render();
		}
	}
	//pParticle->Render();
	pHeadsUp->Render();

	if (pASexplosion != DOGNULL)
		pASexplosion->Render();

	if (state == STATE_CHANGE_TROOP)
	{
		ss.str("");
		ss << "TROPA " << troopCount;
		pText->Render(ss.str(), GetWidth()/2.0f - pText->GetWidth()/3.0f, 
			GetHeight()/2.0f - pText->GetHeight()/2.0f, pHeadsUp->GetColor());
		//cout << pText->GetXPosition() << endl;
	}
	if (state == STATE_FINISH)
	{
		ss.str("");
		ss << "FELICIDADES";
		pText->Render(ss.str(), GetWidth() / 2.0f - pText->GetWidth() / 2.0f,
			GetHeight() / 2.0f - pText->GetHeight() / 2.0f, pHeadsUp->GetColor());

		if (pTextAdditional == DOGNULL)
		{
			pTextAdditional = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf"));
			pTextAdditional->SetSize(15);
			pTextAdditional->SetFlipV(true);
		}
		pTextAdditional->Render("Nivel Terminado. Presiona Enter", GetWidth() / 2.0f - pTextAdditional->GetWidth() / 2.0f,
			GetHeight() / 2.0f - pTextAdditional->GetHeight() / 2.0f + 50.0f, pHeadsUp->GetColor());
	}
	if (state == STATE_GAME_OVER)
	{
		ss.str("");
		ss << "GAME OVER";
		pText->Render(ss.str(), GetWidth() / 2.0f - pText->GetWidth() / 2.0f,
			GetHeight() / 2.0f - pText->GetHeight() / 2.0f, pHeadsUp->GetColor());
	}

	OPENGLRENDERER->SwapGLBuffers();
}

DOGvoid Nivel7::Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime)
{
	if (play && state == STATE_PLAY)
	{
		if (pPressedKeys[DIK_LEFT])
		{
			if (pPlayer->GetXPosition() - pPlayer->GetWidth() / 2.0f >= 0)
			{
				pPlayer->TranslateRel(-vxPlayer*elapsedTime, 0.0f, 0.0f);
			}
		}

		if (pPressedKeys[DIK_RIGHT])
		{
			if (pPlayer->GetXPosition() + pPlayer->GetWidth() / 2.0f <= GetWidth())
			{
				pPlayer->TranslateRel(vxPlayer*elapsedTime, 0.0f, 0.0f);
			}
		}

		if (pPressedKeys[DIK_SPACE])
		{
			(*pLockKeys).push_back(DIK_SPACE);
			if (pBullet == DOGNULL)
			{
				pBullet = new Sprite("glx/img/bullet8x8.png", 8, 8);
				pBullet->SetXPosition(pPlayer->GetXPosition());
				pBullet->SetYPosition(pPlayer->GetYPosition() - pPlayer->GetHeight() / 2.0f);
				pBullet->SetVy(-vyBullet);
				pBullet->SetId(ID_BULLET_PLAYER);
				pBullet->SetCollisionable(true);
				pBullet->CreateBoundingCircle();
				/*pBullet->SetColorBounding(RED);
				pBullet->SetRenderBounding(true);*/

				pCollisionManager->GetCollisionGroup(PLAYER_GROUP)->Add(pBullet);
				pSound->PlayBullet();
			}
		}

		/*if (dim.pMouseButtons[0])
		{
		pParticle->SetTime(0.0f);
		}*/
	}

	if (state == STATE_FINISH)
	{
		if (pPressedKeys[DIK_RETURN] || pPressedKeys[DIK_NUMPADENTER])
		{
			(*pLockKeys).push_back(DIK_RETURN);
			(*pLockKeys).push_back(DIK_NUMPADENTER);

			//pHeadsUp->SetNivel(pHeadsUp->GetNivel() + 1);
			pHeadsUp->SetGameOver(false);
			pHeadsUp->Save();

			if (pScores == DOGNULL)
			{
				pScores = unique_ptr<Scores>(new Scores());
				SCORE s;
				s.name = pHeadsUp->GetPlayerName();
				s.level = pHeadsUp->GetNivel();
				s.score = pHeadsUp->GetPoints();
				s.idSession = pHeadsUp->GetIDSession();
				pScores->UpdateScores(s);
				pScores->Save();

				SetNextGameState(GALAXIAN_STATE_SCORES);
			}
		}
	}//state STATE_FINISH

	if (state == STATE_GAME_OVER)
	{
		if (pPressedKeys[DIK_RETURN] || pPressedKeys[DIK_NUMPADENTER])
		{
			(*pLockKeys).push_back(DIK_RETURN);
			(*pLockKeys).push_back(DIK_NUMPADENTER);

			if (pScores == DOGNULL)
			{
				pHeadsUp->SetGameOver(true);
				pHeadsUp->Save();

				pScores = unique_ptr<Scores>(new Scores());
				SCORE s;
				s.name = pHeadsUp->GetPlayerName();
				s.level = pHeadsUp->GetNivel();
				s.score = pHeadsUp->GetPoints();
				s.idSession = pHeadsUp->GetIDSession();
				pScores->UpdateScores(s);
				pScores->Save();

				SetNextGameState(GALAXIAN_STATE_SCORES);
			}
		}
	}
}

DOGvoid Nivel7::IniciaTropa(DOGbool f)
{
	DOGfloat xEnemyArea = GetWidth() - (WIDTH_MARGIN * 2);
	DOGint nxEnemies = xEnemyArea / WIDTH_ENEMY;

	DOGfloat totalWidth = 1500.0f;

	while (totalWidth > xEnemyArea)
	{
		totalWidth = WIDTH_ENEMY * nxEnemies + X_SPACE_ENEMIES * (nxEnemies - 1);
		nxEnemies = totalWidth > xEnemyArea ? nxEnemies - 1 : nxEnemies;
	}

	DOGfloat xInitial = (xEnemyArea - totalWidth) / 2.0f;
	DOGfloat x = xInitial + WIDTH_MARGIN + WIDTH_ENEMY / 2.0f;

	DOGfloat yInitial = 100.0f;
	DOGfloat y = yInitial;// + HEIGHT_MARGIN + HEIGHT_ENEMY / 2.0f;

	DOGfloat yEnemyArea = GetHeight() - (HEIGHT_MARGIN * 2 + SPACE_PLAYER_AND_TROOP + pPlayer->GetHeight());
	DOGint nyEnemies = yEnemyArea / HEIGHT_ENEMY;

	DOGfloat totalHeight = 1500.0f;
	while (totalHeight > xEnemyArea)
	{
		totalHeight = HEIGHT_ENEMY * nyEnemies + Y_SPACE_ENEMIES * (nyEnemies - 1);
		nyEnemies = totalHeight > yEnemyArea ? nyEnemies - 1 : nyEnemies;
	}

	if (!f)
	{
		nxEnemies = DOGMin(nxEnemies, MAX_ENEMIES_X);
		totalWidth = WIDTH_ENEMY * nxEnemies + X_SPACE_ENEMIES * (nxEnemies - 1);
		xInitial = (xEnemyArea - totalWidth) / 2.0f;
		x = xInitial + WIDTH_MARGIN + WIDTH_ENEMY / 2.0f;

		nyEnemies = DOGMin(nyEnemies, MAX_ENEMIES_Y);
	}
	else
	{
		pXml->Init("glx/xml/troop7.xml");
		nxEnemies = pXml->GetDatai("/TROOP/COLS");
		nyEnemies = pXml->GetDatai("/TROOP/ROWS");

		totalWidth = WIDTH_ENEMY * nxEnemies + X_SPACE_ENEMIES * (nxEnemies - 1);
		xInitial = (xEnemyArea - totalWidth) / 2.0f;
		x = xInitial + WIDTH_MARGIN + WIDTH_ENEMY / 2.0f;
	}

	DOGint idEnemy = 0;

	pEnemigos = new vector<Enemy*>();

	stringstream ss;
	string enemy = "";
	for (auto row = 0; row < nyEnemies; row++)
	{
		if (f)
		{
			ss.str("");
			ss << "/TROOP/ROW";
			ss << (row + 1);
		}

		string s = ss.str();

		for (auto inx = 0; inx < nxEnemies; inx++)
		{
			if (f)
			{
				ss.str("");
				ss << s << "/COL" << (inx + 1);
				enemy = pXml->GetDatac(ss.str());
			}

			if (enemy == "E" || !f)
			{
				DOGint n = DOGRandomNumber(1, 4);

				Enemy* e = DOGNULL;
				switch (n)
				{
				case 1:
					e = new Enemy("glx/img/7/1.png", 13, 11);
					//e->CreateBoundingCircle(e->GetWidth()/2.0f, x, y);
					break;
				case 2:
					e = new Enemy("glx/img/7/2.png", 13, 11);
					//e->CreateBoundingCircle(e->GetWidth()/2.0f, x, y);
					break;
				case 3:
					e = new Enemy("glx/img/7/3.png", 11, 11);
					//e->CreateBoundingCircle(e->GetWidth()/2.0f, x, y);
					break;
				case 4:
					e = new Enemy("glx/img/7/4.png", 11, 11);
					//e->CreateBoundingBox();
					break;
				}
				e->GetSprite()->SetXPosition(x);
				e->GetSprite()->SetYPosition(y);
				e->SetXOriginal(x);
				e->SetYOriginal(y);
				e->GetSprite()->CreateBoundingCircle(e->GetSprite()->GetHeight() / 2.0f, e->GetSprite()->GetXPosition(), e->GetSprite()->GetYPosition());
				e->GetSprite()->SetId(idEnemy++);
				e->GetSprite()->SetCollisionable(true);
				e->SetHeight(GetHeight());
				e->SetLevel(7);
				/*e->GetSprite()->SetRenderBounding(true);
				e->GetSprite()->SetColorBounding(BLUE);*/

				pEnemigos->push_back(e);
			}//if enemy == 'E'

			x += X_SPACE_ENEMIES + WIDTH_ENEMY;
		}
		y += Y_SPACE_ENEMIES + HEIGHT_ENEMY;
		x = xInitial + WIDTH_MARGIN + WIDTH_ENEMY / 2.0f;
	}

	for (auto iElement = 0; iElement < pEnemigos->size(); iElement++)
	{
		pCollisionManager->GetCollisionGroup(ENEMY_GROUP)->Add((*pEnemigos)[iElement]->GetSprite());
	}
}

DOGvoid Nivel7::DeleteEnemy(DOGint id)
{
	for (auto iEnemy = 0; iEnemy < pEnemigos->size(); iEnemy++)
	{
		if ((*pEnemigos)[iEnemy]->GetSprite()->GetId() == id)
		{
			DOG_SAFE_DELETE((*pEnemigos)[iEnemy]);
			pEnemigos->erase(pEnemigos->begin() + iEnemy);
			break;
		}
	}
}

DOGvoid Nivel7::Explote(DOGfloat x, DOGfloat y, DOGfloat z)
{
	DOGbool free = false;
	for (auto iExplosion = 0; iExplosion < pExplosions->size(); iExplosion++)
	{
		if ((*pExplosions)[iExplosion]->IsDead())
		{
			(*pExplosions)[iExplosion]->TranslateAbs(x, y, z);
			//(*pExplosions)[iExplosion]->SetTime(0.0f);
			(*pExplosions)[iExplosion]->ReinitDeadParticles();
			free = true;
			break;
		}
	}

	if (!free)
	{
		CreateExplosion();
	}
}

DOGvoid Nivel7::CreateExplosion()
{
	ParticleSystemGL* pParticles = new Explosion("glx/fxgl/Explosion_VS.glsl", "glx/fxgl/Explosion_FS.glsl",
		"glx/img/NeGeo.png", DOGVECTOR3(450.0f, 450.0f, 0.0f), 250, 8.0f);
	pParticles->InitParticles();
	pParticles->TranslateAbs(-500.0f, -300.0f, 0.0f);

	pExplosions->push_back(pParticles);
}

DOGbool Nivel7::CheckExplosionLive()
{
	for (auto i = 0; i < pExplosions->size(); i++)
	{
		if (!(*pExplosions)[i]->IsDead())
		{
			return false;
		}
	}

	return true;
}

DOGvoid Nivel7::CheckLifes()
{
	pHeadsUp->LostLife();
	if (pHeadsUp->GetVidas() < 0)
	{
		play = false;
		state = STATE_GAME_OVER;
	}
}