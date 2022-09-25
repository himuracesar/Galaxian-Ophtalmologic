#include "ScoresScreen.h"

ScoresScreen::ScoresScreen()
{
	pCamera = DOGNULL;
	pTitleName = DOGNULL;
	pTitleLevel = DOGNULL;
	pTitleScore = DOGNULL;
	pName = DOGNULL;
	pLevel = DOGNULL;
	pScore = DOGNULL;

	state = 0;
}

ScoresScreen::~ScoresScreen()
{
	Release();
}

DOGvoid ScoresScreen::Release()
{
	DOG_SAFE_DELETE(pCamera);
}

DOGRESULT ScoresScreen::Init()
{
	pCamera = new Camera2D(0.0f, GetWidth(), GetHeight(), 0.0f, -1.0f, 1.0f);
	pCamera->SetInvertY(true);

	DOGSCENE->SetActiveCamera(pCamera);

	pTitleName = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf", 25));
	pTitleName->SetFlipV(true);

	pTitleLevel = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf", 25));
	pTitleLevel->SetFlipV(true);

	pTitleScore = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf", 25));
	pTitleScore->SetFlipV(true);

	pName = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf", 25));
	pName->SetFlipV(true);

	pLevel = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf", 25));
	pLevel->SetFlipV(true);

	pScore = unique_ptr<TextSDL>(new TextSDL("glx/fonts/PressStart2P.ttf", 25));
	pScore->SetFlipV(true);

	unique_ptr<Scores> pScores = unique_ptr<Scores>(new Scores());
	v = pScores->GetScores();

	unique_ptr<XMLParser> pXml = unique_ptr<XMLParser>(new XMLParser());
	pXml->Init("glx/xml/headsup.xml");
	state = pXml->GetDatai("/HEADSUP/LEVEL");

	pXml->Init("glx/xml/headsup.xml");
	if (pXml->GetDatai("/HEADSUP/GAME_OVER") == 1)
	{
		gameOver = true;
	}
	else
	{
		gameOver = false;
	}

	return DOG_OK;
}

DOGvoid ScoresScreen::Update(DOGfloat elapsedTime)
{
	pTitleName->Update(elapsedTime);
	pTitleLevel->Update(elapsedTime);
	pTitleScore->Update(elapsedTime);
	pName->Update(elapsedTime);
	pLevel->Update(elapsedTime);
	pScore->Update(elapsedTime);
}

DOGvoid ScoresScreen::Render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	pTitleName->Render("NOMBRE", 130.0f, 15.0f, RED);
	pTitleLevel->Render("NIVEL", 450.0f, 15.0f, RED);
	pTitleScore->Render("PUNTOS", 800.0f, 15.0f, RED);

	stringstream ss;
	DOGfloat y = 45.0f;
	for (auto iScore = 0; iScore < v.size(); iScore++)
	{
		pName->Render(v[iScore].name, 150.0, y, WHITE);
		ss.str("");
		ss << v[iScore].level;
		pLevel->Render(ss.str(), 500.0, y, WHITE);
		ss.str("");
		ss << v[iScore].score;
		pScore->Render(ss.str(), 850.0, y, WHITE);
		y += 40.0f;
	}

	OPENGLRENDERER->SwapGLBuffers();
}

DOGvoid ScoresScreen::Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime)
{
	if (pPressedKeys[DIK_RETURN] || pPressedKeys[DIK_NUMPADENTER])
	{
		(*pLockKeys).push_back(DIK_RETURN);
		(*pLockKeys).push_back(DIK_NUMPADENTER);

		if (!gameOver)
		{
			state++;
			if (state > LAST_LEVEL)
				SetNextGameState(GALAXIAN_STATE_NIVEL1);
			else
				SetNextGameState(state);
		}
	}
}