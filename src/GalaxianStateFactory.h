#pragma once
#ifndef GALAXIAN_STATE_FACTORY_H
#define GALAXIAN_STATE_FACTORY_H

#include "DogEngine/Core/DogBaseApp.h"
#include "DogEngine/Core/DogGameStateFactory.h"

#include "ScoresScreen.h"
#include "States.h"
#include "Welcome.h"
#include "Nivel1.h"
#include "Nivel2.h"
#include "Nivel3.h"
#include "Nivel4.h"
#include "Nivel5.h"
#include "Nivel6.h"
#include "Nivel7.h"
#include "Nivel8.h"

class GalaxianStateFactory : public DogGameStateFactory
{
	public:
		GalaxianStateFactory();
		~GalaxianStateFactory();

		DOGvoid Release();

		DogBaseApp* GetGameState(DOGint gameState);
};

#endif