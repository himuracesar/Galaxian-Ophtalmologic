#pragma once
#ifndef DOG_BASE_APP_H
#define DOG_BASE_APP_H

#include "DogError.h"
#include "DogStdafx.h"

#include "../RenderEngine/UtilsGraphics.h"

/**
* Templetate para crear la aplicación base. Vendría siendo un estado del juego o aplicación
*
* @author Cesar Himura
*/
class DogBaseApp
{
	public:
		DogBaseApp();
		virtual ~DogBaseApp();

		virtual DOGRESULT Init() = 0;
		virtual DOGvoid	  Release() = 0;
		virtual DOGvoid	  Update(DOGfloat elapsedTime) = 0;
		virtual DOGvoid	  Render() = 0;
		virtual DOGvoid	  Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime) = 0;

		DOGvoid SetWidth(DOGushort width);
		DOGvoid SetHeight(DOGushort height);
		DOGvoid SetWidthAndHeight(DOGushort width, DOGushort height);
		DOGvoid SetNextGameState(DOGint nextGameState);

		DOGushort GetWidth();
		DOGushort GetHeight();

		DOGint GetNextGameState();

	private:
		DOGushort width;
		DOGushort height;

		DOGint nextGameState;
};

#endif
