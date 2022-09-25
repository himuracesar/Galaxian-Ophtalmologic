#pragma once
#ifndef GALAXIAN_GAME_H
#define GALAXIAN_GAME_H

#include "DogEngine/Core/DogBaseApp.h"
#include "DogEngine/Core/DogError.h"
#include "DogEngine/Core/DogStdafx.h"
#include "DogEngine/Core/DogGame.h"

#include "GalaxianStateFactory.h"
#include "Welcome.h"
#include "ScoresScreen.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "Nivel5.h"
#include "Nivel6.h"

class GalaxianGame : public DogGame
{
	public:
		GalaxianGame();
		~GalaxianGame();

		virtual DOGvoid Init();
		virtual DOGvoid Update(DOGfloat elapsedTime);
		virtual DOGvoid Render();
		virtual DOGvoid Release();
		virtual DOGvoid Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime);

	private:
		DogBaseApp *pApp;

		GalaxianStateFactory* pStateFactory;
};

#endif
