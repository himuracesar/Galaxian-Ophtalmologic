#include "Welcome.h"

Welcome::Welcome()
{
	pWelcome = DOGNULL;
	pName = DOGNULL;
	pInstruccions = DOGNULL;
	pInstruccions2 = DOGNULL;
	pCamera = DOGNULL;
	pPrompt = DOGNULL;
	renderPrompt = false;
	timer = 0.0f;
}

Welcome::~Welcome()
{
	Release();
}

DOGvoid Welcome::Release()
{
	
}

DOGRESULT Welcome::Init()
{
	cout << "Init Welcome" << endl;

	//nextGameState = GALAXIAN_STATE_WELCOME;

	pCamera = new Camera2D(0.0f, GetWidth(), GetHeight(), 0.0f, -1.0f, 1.0f);
	pCamera->SetInvertY(true);

	DOGSCENE->SetActiveCamera(pCamera);

	pWelcome = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf"));
	pWelcome->SetSize(60);
	pWelcome->SetFlipV(true);

	pInstruccions = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf"));
	pInstruccions->SetSize(40);
	pInstruccions->SetFlipV(true);

	pInstruccions2 = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf"));
	pInstruccions2->SetSize(40);
	pInstruccions2->SetFlipV(true);

	pName = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf"));
	pName->SetSize(55);
	pName->SetFlipV(true);

	pPrompt = unique_ptr<Sprite>(new Sprite("glx/img/prompt.png", 8, 64));
	pPrompt->TranslateAbs(GetWidth() / 2.0f, GetHeight() / 2.0 + 20.0f, 0.0f);

	state = STATE_POWERED_BY;

	pPrint = unique_ptr<Sprite>(new Sprite("glx/img/Huella.png", 128, 128));
	pPrint->SetColor(DOGCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
	pPrint->TranslateAbs(GetWidth() / 2.0f, GetHeight() / 2.0f, 0.0f);
	//pPrint->TranslateAbs(100.0f, 100.0f, 0.0f);

	timer = t = 0.0f;

	return DOG_OK;
}

DOGvoid Welcome::Update(DOGfloat elapsedTime)
{
	if (state == STATE_POWERED_BY)
	{
		timer += elapsedTime;
		pPrint->Update(elapsedTime);

		DOGfloat alpha = timer / 5.0f;

		//pPrint->SetColor(DOGCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		if (alpha >= 1.0f)
		{
			pPrint->SetColor(DOGCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
			t += elapsedTime;
			if (t >= 4.0f)
				state = STATE_NAME;
		}
		else
		{
			pPrint->SetColor(DOGCOLOR(1.0f, 1.0f, 1.0f, alpha));
		}
	}

	if (state == STATE_NAME)
	{
		pWelcome->Update(elapsedTime);
		pInstruccions->Update(elapsedTime);
		pInstruccions2->Update(elapsedTime);
		pName->Update(elapsedTime);
		pPrompt->Update(elapsedTime);

		timer += elapsedTime;
		if (timer >= 0.5f)
		{
			timer = 0.0f;
			renderPrompt = !renderPrompt;
		}

		if (name.size() > 0)
			pPrompt->TranslateAbs(pName->GetXPosition() + pName->GetWidth(), pName->GetYPosition() + 20.0f, 0.0f);
	}
}

DOGvoid Welcome::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	if (state == STATE_POWERED_BY)
	{
		pPrint->Render();
	}

	if (state == STATE_NAME)
	{
		pWelcome->Render("BIENVENIDO", GetWidth() / 2.0 - pWelcome->GetWidth() / 2.0f, 10.0f, RED);
		pInstruccions->Render("Escribe tu nombre y presiona", 50.0f, 80.0f, WHITE);
		pInstruccions2->Render("ENTER para continuar", 50.0f, 150.0f, WHITE);

		if (name.size() > 0)
			pName->Render(name, GetWidth() / 2.0 - pName->GetWidth() / 2.0f, 400.0f, YELLOW);

		if (renderPrompt)
			pPrompt->Render();
	}

	OPENGLRENDERER->SwapGLBuffers();
}

DOGvoid Welcome::Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime)
{
	if (pPressedKeys[DIK_0])
	{
		(*pLockKeys).push_back(DIK_0);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "0";
	}

	if (pPressedKeys[DIK_1])
	{
		(*pLockKeys).push_back(DIK_1);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "1";
	}

	if (pPressedKeys[DIK_2])
	{
		(*pLockKeys).push_back(DIK_2);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "2";
	}

	if (pPressedKeys[DIK_3])
	{
		(*pLockKeys).push_back(DIK_3);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "3";
	}

	if (pPressedKeys[DIK_4])
	{
		(*pLockKeys).push_back(DIK_4);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "4";
	}

	if (pPressedKeys[DIK_5])
	{
		(*pLockKeys).push_back(DIK_5);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "5";
	}

	if (pPressedKeys[DIK_6])
	{
		(*pLockKeys).push_back(DIK_6);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "6";
	}

	if (pPressedKeys[DIK_7])
	{
		(*pLockKeys).push_back(DIK_7);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "7";
	}

	if (pPressedKeys[DIK_8])
	{
		(*pLockKeys).push_back(DIK_8);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "8";
	}

	if (pPressedKeys[DIK_9])
	{
		(*pLockKeys).push_back(DIK_9);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "9";
	}

	if (pPressedKeys[DIK_A])
	{
		(*pLockKeys).push_back(DIK_A);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "A";
	}

	if (pPressedKeys[DIK_B])
	{
		(*pLockKeys).push_back(DIK_B);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "B";
	}

	if (pPressedKeys[DIK_C])
	{
		(*pLockKeys).push_back(DIK_C);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "C";
	}

	if (pPressedKeys[DIK_D])
	{
		(*pLockKeys).push_back(DIK_D);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "D";
	}

	if (pPressedKeys[DIK_E])
	{
		(*pLockKeys).push_back(DIK_E);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "E";
	}

	if (pPressedKeys[DIK_F])
	{
		(*pLockKeys).push_back(DIK_F);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "F";
	}

	if (pPressedKeys[DIK_G])
	{
		(*pLockKeys).push_back(DIK_G);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "G";
	}

	if (pPressedKeys[DIK_H])
	{
		(*pLockKeys).push_back(DIK_H);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "H";
	}

	if (pPressedKeys[DIK_I])
	{
		(*pLockKeys).push_back(DIK_I);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "I";
	}

	if (pPressedKeys[DIK_J])
	{
		(*pLockKeys).push_back(DIK_J);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "J";
	}

	if (pPressedKeys[DIK_K])
	{
		(*pLockKeys).push_back(DIK_K);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "K";
	}

	if (pPressedKeys[DIK_L])
	{
		(*pLockKeys).push_back(DIK_L);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "L";
	}

	if (pPressedKeys[DIK_M])
	{
		(*pLockKeys).push_back(DIK_M);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "M";
	}

	if (pPressedKeys[DIK_N])
	{
		(*pLockKeys).push_back(DIK_N);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "N";
	}

	if (pPressedKeys[DIK_O])
	{
		(*pLockKeys).push_back(DIK_O);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "O";
	}

	if (pPressedKeys[DIK_P])
	{
		(*pLockKeys).push_back(DIK_P);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "P";
	}

	if (pPressedKeys[DIK_Q])
	{
		(*pLockKeys).push_back(DIK_Q);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "Q";
	}

	if (pPressedKeys[DIK_R])
	{
		(*pLockKeys).push_back(DIK_R);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "R";
	}

	if (pPressedKeys[DIK_S])
	{
		(*pLockKeys).push_back(DIK_S);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "S";
	}

	if (pPressedKeys[DIK_T])
	{
		(*pLockKeys).push_back(DIK_T);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "T";
	}

	if (pPressedKeys[DIK_U])
	{
		(*pLockKeys).push_back(DIK_U);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "U";
	}

	if (pPressedKeys[DIK_V])
	{
		(*pLockKeys).push_back(DIK_V);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "V";
	}

	if (pPressedKeys[DIK_W])
	{
		(*pLockKeys).push_back(DIK_W);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "W";
	}

	if (pPressedKeys[DIK_X])
	{
		(*pLockKeys).push_back(DIK_X);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "X";
	}

	if (pPressedKeys[DIK_Y])
	{
		(*pLockKeys).push_back(DIK_Y);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "Y";
	}

	if (pPressedKeys[DIK_Z])
	{
		(*pLockKeys).push_back(DIK_Z);
		if (name.size() < LIMIT_SIZE_NAME)
			name += "Z";
	}

	if (pPressedKeys[DIK_BACK])
	{
		(*pLockKeys).push_back(DIK_BACK);
		if (name.size() > 0)
			name = name.substr(0, name.size() - 1);
		if (name.size() == 0)
			name = "";
	}

	if (pPressedKeys[DIK_RETURN] || pPressedKeys[DIK_NUMPADENTER])
	{
		(*pLockKeys).push_back(DIK_RETURN);
		(*pLockKeys).push_back(DIK_NUMPADENTER);
		//cout << "ENTER" << endl;

		if (name.size() > 0)
		{
			DOGint id = DOGRandomNumber(1, 10000);

			unique_ptr<HeadsUp> pHeads = unique_ptr<HeadsUp>(new HeadsUp());
			pHeads->SetPlayerName(name);
			pHeads->SetVidas(2);
			pHeads->SetNivel(1);
			pHeads->SetPoints(0);
			pHeads->SetIDSession(id);
			pHeads->Save();

			SetNextGameState(GALAXIAN_STATE_NIVEL1);
		}
	}
}