#include "GalaxianStateFactory.h"

GalaxianStateFactory::GalaxianStateFactory()
{

}

GalaxianStateFactory::~GalaxianStateFactory()
{
	Release();
}

void GalaxianStateFactory::Release()
{

}

DogBaseApp* GalaxianStateFactory::GetGameState(DOGint gameState)
{
	switch (gameState)
	{
		case GALAXIAN_STATE_WELCOME:
			return new Welcome();
		break;
		case GALAXIAN_STATE_NIVEL1:
			return new Nivel1();
		break;
		case GALAXIAN_STATE_NIVEL2:
			return new Nivel2();
		break;
		case GALAXIAN_STATE_NIVEL3:
			return new Nivel3();
		break;
		case GALAXIAN_STATE_NIVEL4:
			return new Nivel4();
		break;
		case GALAXIAN_STATE_NIVEL5:
			return new Nivel5();
		break;
		case GALAXIAN_STATE_NIVEL6:
			return new Nivel6();
		break;
		case GALAXIAN_STATE_NIVEL7:
			return new Nivel7();
		break;
		case GALAXIAN_STATE_NIVEL8:
			return new Nivel8();
		break;
		case GALAXIAN_STATE_SCORES:
			return new ScoresScreen();
		break;
		default:
			return 0;
		break;
	}

	return 0;
}