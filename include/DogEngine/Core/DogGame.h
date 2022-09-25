#pragma once
#ifndef DOG_GAME_H
#define DOG_GAME_H

#include "DogStdafx.h"

#include "../RenderEngine/UtilsGraphics.h"

/**
* Clase abstracta para crear un juego. Es como una plantilla. 
* La clase DogGame gestiona los estados del juego
*
* @author César Himura
* @version 1.0
*/
class DogGame
{
	public:
		DogGame();
		virtual ~DogGame();

		virtual DOGvoid Init() = 0;
		virtual DOGvoid Update(DOGfloat elapsedTime) = 0;
		virtual DOGvoid Render() = 0;
		virtual DOGvoid Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime) = 0;
		virtual DOGvoid Release();

		DOGvoid SetWidth(DOGushort width);
		DOGvoid SetHeight(DOGushort height);

		DOGushort GetWidth();
		DOGushort GetHeight();

	private:
		DOGushort width;
		DOGushort height;
};

#endif