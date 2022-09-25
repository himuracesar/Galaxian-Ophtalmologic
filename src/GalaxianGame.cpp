#include "GalaxianGame.h"

GalaxianGame::GalaxianGame()
{
	pApp = DOGNULL;
	pStateFactory = DOGNULL;
}

GalaxianGame::~GalaxianGame()
{
	Release();
}

DOGvoid GalaxianGame::Init()
{
	cout << "GalaxianGame::Init" << endl;

	pStateFactory = new GalaxianStateFactory();

	pApp = new Welcome();
	pApp->SetWidthAndHeight(GetWidth(), GetHeight());
	pApp->Init();
	pApp->SetNextGameState(-1);
}

DOGvoid GalaxianGame::Release()
{
	DOG_SAFE_DELETE(pApp);
}

DOGvoid GalaxianGame::Update(DOGfloat elapsedTime)
{
	pApp->Update(elapsedTime);

	DOGint s = pApp->GetNextGameState();
	if (pApp->GetNextGameState() > -1)
	{
		DOGint nextGameState = pApp->GetNextGameState();
		DOG_SAFE_DELETE(pApp);

		pApp = pStateFactory->GetGameState(nextGameState);

		pApp->SetNextGameState(-1);
		pApp->SetWidthAndHeight(GetWidth(), GetHeight());
		pApp->Init();
	}
}

DOGvoid GalaxianGame::Render()
{
	pApp->Render();
}

DOGvoid GalaxianGame::Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime)
{
	pApp->Input(dim, pPressedKeys, pLockKeys, elapsedTime);
}