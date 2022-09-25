#include "DogEngine/Core/OpenGLFrameworkLayer.h"
#include "DogEngine/Core/DogStdafx.h"

#include "Class/XMLParser.h"

//Juego de Galaxian
#include "GalaxianGame.h"

int _tmain(int argc, _TCHAR* argv[])
{
	#if defined(DEBUG) | defined(_DEBUG)
		_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG | _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_CRT_DF);
	#endif 

	_CrtDumpMemoryLeaks();

	DogGame *pDogGame;
	//pDogGame = new DogGameLauncher();
	pDogGame = new GalaxianGame();

	XMLParser* pXml = new XMLParser();
	pXml->Init("glx/xml/config.xml");

	DOGint w = pXml->GetDatai("/GALAXIAN/RESOLUCION/WIDTH_SCREEN");
	DOGint h = pXml->GetDatai("/GALAXIAN/RESOLUCION/HEIGHT_SCREEN");

	OpenGLFrameworkLayer *pFrame;
	pFrame = new OpenGLFrameworkLayer(pDogGame);
	DR(pFrame->Init("Galaxian", w, h, true, DIREC_INPUT_8));
	//DR(pFrame->Init("Dog Game Engine OpenGL", 1300, 700, true, DIREC_INPUT_8));

	DOG_SAFE_DELETE(pXml);

	pDogGame->Init();

	pFrame->Run();

	DOG_SAFE_DELETE(pDogGame);
	DOG_SAFE_DELETE(pFrame);

	return 0;
}