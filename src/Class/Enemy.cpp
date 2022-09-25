#include "Enemy.h"

Enemy::Enemy()
{
	kamikaze = attacking = returning = bulletCollisionable = false;
	pSprite = DOGNULL;
	//pBullet = DOGNULL;
	xOriginal = xo = yOriginal = yo = height = 0;
	vx = vy = 0.0f;
	shoot = 0.0f;
	bulletCollisionable = d = false;
	fire = false;
	level = 0;
	xPlayer = 0.0f;
}

Enemy::Enemy(string path, DOGint w, DOGint h)
{
	pSprite = new Sprite(path, w, h);
	//pBullet = DOGNULL;
	kamikaze = false;
	xOriginal = yOriginal = xo = yo = 0.0f;
	attacking = returning = false;
	vx = vy = 0.0f;
	shoot = 0.0f;
	bulletCollisionable = d = false;
	height = 0;
	fire = false;
	level = 0;
	xPlayer = 0.0f;
}

Enemy::~Enemy()
{
	Release();
}

DOGvoid Enemy::Release()
{
	DOG_SAFE_DELETE(pSprite);
	//DOG_SAFE_DELETE(pBullet);
}

DOGvoid Enemy::Update(DOGfloat elapsedTime)
{
	pSprite->Update(elapsedTime);
	if (attacking)
	{
		if (level >= 2)
		{
			pattern2(elapsedTime);
		}
		else
		{
			pattern1(elapsedTime);
		}
		
		shoot += elapsedTime;
		fire = false;
		if (shoot >= SHOOT && pSprite->GetYPosition() <= (height - 200))
		{
			/*if (pBullet == DOGNULL)
			{
				pBullet = new Sprite("glx/img/bullet8x8.png", 16, 16);
				pBullet->SetXPosition(pSprite->GetXPosition());
				pBullet->SetYPosition(pSprite->GetYPosition() + pSprite->GetHeight());
				pBullet->SetVy(2.0f);
				pBullet->SetId(ID_BULLET_ENEMY);
				pBullet->SetCollisionable(true);
				pBullet->CreateBoundingCircle();
				bulletCollisionable = false;
			}*/
			fire = true;
			shoot = 0.0f;
		}
	}

	if (returning)
	{
		if (pSprite->GetYPosition() >= yOriginal)
		{
			pSprite->SetYPosition(yOriginal);
			pSprite->SetVy(0.0f);
			pSprite->SetVx(0.0f);
			returning = false;
		}
	}
}

DOGvoid Enemy::Render()
{
	pSprite->Render();
	
	/*if (pBullet != DOGNULL)
	{
		pBullet->Render();
	}*/
}

DOGvoid Enemy::SetKamikaze(DOGbool b)
{
	kamikaze = b;
}

DOGbool Enemy::IsKamikaze()
{
	return kamikaze;
}

Sprite* Enemy::GetSprite()
{
	return pSprite;
}

DOGvoid Enemy::SetXOriginal(DOGfloat x)
{
	xOriginal = xo = x;
}

DOGvoid Enemy::SetYOriginal(DOGfloat y)
{
	yOriginal = yo = y;
}

DOGvoid Enemy::SetVx(DOGfloat v)
{
	vx = v;
}

DOGvoid Enemy::SetVy(DOGfloat v)
{
	vy = v;
}

DOGvoid Enemy::Attack(DOGbool b)
{
	attacking = b;
	if (b)
	{
		pSprite->SetVx(vx);
		pSprite->SetVy(vy);
	}
	else
	{
		pSprite->SetVx(0.0f);
		pSprite->SetVy(0.0f);
	}
}

DOGvoid Enemy::pattern1(DOGfloat elapsedTime)
{
	DOGfloat d = (110 * 110);
	DOGfloat dx = abs(pSprite->GetXPosition() - xo);
	dx = dx * dx;
	DOGfloat dy = abs(pSprite->GetYPosition() - yo);
	dy = dy * dy;
	if (d <= dx + dy)
	{
		pSprite->SetVx(pSprite->GetVx() * -1);
		xo = pSprite->GetXPosition();
		yo = pSprite->GetYPosition();
		//cout << ".:CAMBIA::" << pSprite->GetVx() << endl;
	}
	/*pSprite->SetVx(vx * elapsedTime);
	pSprite->SetVy(vy * elapsedTime);*/
}

DOGvoid Enemy::pattern2(DOGfloat elapsedTime)
{
	if (!d)
	{
		DOGfloat dis = (110 * 110);
		DOGfloat dx = abs(pSprite->GetXPosition() - xo);
		dx = dx * dx;
		DOGfloat dy = abs(pSprite->GetYPosition() - yo);
		dy = dy * dy;
		if (dis <= dx + dy)
		{
			d = true;
			//cout << ".:CAMBIA::" << pSprite->GetVx() << endl;
			pSprite->SetVx(pSprite->GetVx() * -1);
			/*xo = pSprite->GetXPosition();
			yo = pSprite->GetYPosition();*/
			cout << d << endl;
		}
	}
	else
	{
		if (pSprite->GetVx() > 0)
		{
			if (pSprite->GetXPosition() >= (xPlayer + 50.0f))
			{
				pSprite->SetVx(pSprite->GetVx() * -1);
			}
		}
		else
		{
			if (pSprite->GetVx() < 0)
			{
				if (pSprite->GetXPosition() <= (xPlayer - 50.0f))
				{
					pSprite->SetVx(pSprite->GetVx() * -1);
				}
			}
		}
		/*DOGfloat dx = abs(xPlayer - pSprite->GetXPosition());
		if (dx >= 60.0f)
		{
			pSprite->SetVx(pSprite->GetVx() * -1);
			cout << pSprite->GetVx() << endl;
		}*/
	}
  }

DOGvoid Enemy::Return()
{
	returning = true;
	pSprite->SetXPosition(xOriginal);
	pSprite->SetYPosition(-5.0f);
	pSprite->SetVy(1.0f);
}

DOGvoid Enemy::SetHeight(DOGint h)
{
	height = h;
}

DOGvoid Enemy::SetFire(DOGbool b)
{
	fire = b;
}

DOGbool Enemy::IsFire()
{
	return fire;
}

DOGvoid Enemy::SetLevel(DOGint level)
{
	this->level = level;
}

DOGvoid Enemy::SetXPlayer(DOGfloat xPlayer)
{
	this->xPlayer = xPlayer;
}