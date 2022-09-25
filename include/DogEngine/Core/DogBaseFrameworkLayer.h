#pragma once
#ifndef DOG_BASE_FRAMEWORK_LAYER_H
#define DOG_BASE_FRAMEWORK_LAYER_H

#include "DogError.h"
#include "DogGame.h"
#include "DogStdafx.h"

/**
* Clase Base para definir el API gráfica que será implementada
* @author César Himura
*/
class DogBaseFrameworkLayer
{
	public:
		DogBaseFrameworkLayer() { pDogGame = NULL; }
		virtual ~DogBaseFrameworkLayer() {};

		virtual DOGRESULT Init(DOGchar* name, DOGushort width, DOGushort height, DOGbool fullscreen, DOGint inputType) = 0;
		virtual DOGvoid Update() = 0;
		virtual DOGvoid Render() = 0;
		virtual DOGvoid Resize(DOGushort width, DOGushort height) = 0;
		virtual DOGvoid Input() = 0;
		virtual DOGvoid ToogleFullScreen(DOGushort width, DOGushort height) = 0;

		virtual DOGfloat GetFPS() = 0;

		DOGvoid SetDogGame(DogGame *pDogGame);
		DOGvoid SetWidth(DOGushort width);
		DOGvoid SetHeight(DOGushort height);
		DOGvoid SetWindowedScreen(DOGbool windowed);
		DOGvoid SetName(DOGchar *name);
		
		DOGushort GetWidth();
		DOGushort GetHeight();

		DOGbool IsWindowedScreen();

		DOGchar* GetName();

		DogGame* GetDogGame();

	private:
		DogGame* pDogGame;

		DOGushort width;
		DOGushort height;

		DOGbool windowed;

		DOGchar *name;
};

#endif