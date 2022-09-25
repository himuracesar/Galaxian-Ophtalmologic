#pragma once
#ifndef DOG_GAME_STATE_FACTORY_H
#define DOG_GAME_STATE_FACTORY_H

#include "DogBaseApp.h"

/**
* Clase abstracta que genera los estados de un juego (game states)
*
* @author Cesar Himura
* @version 1.0
*/
class DogGameStateFactory
{
	public:
		DogGameStateFactory();
		virtual ~DogGameStateFactory();

		virtual DogBaseApp* GetGameState(DOGint gameState) = 0;
		virtual DOGvoid Release() = 0;
};

#endif