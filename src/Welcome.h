#pragma once
#ifndef WELCOME_H
#define WELCOME_H

#include "DogEngine/Core/DogBaseApp.h"
#include "DogEngine/Core/DogStdafx.h"

#include "DogEngine/RenderEngine/Camera2D.h"
#include "DogEngine/RenderEngine/OpenGL/OpenGLRenderer.h"
#include "DogEngine/RenderEngine/OpenGL/Sprite.h"
#include "DogEngine/RenderEngine/OpenGL/TextSDL.h"

#include "States.h"
#include "Class/HeadsUp.h"

#define LIMIT_SIZE_NAME 7
#define STATE_POWERED_BY 100
#define STATE_NAME 101

class Welcome : public DogBaseApp
{
	public:
		Welcome();
		virtual ~Welcome();

		virtual DOGRESULT Init();
		virtual DOGvoid	  Release();
		virtual DOGvoid	  Update(DOGfloat elapsedTime);
		virtual DOGvoid	  Render();
		virtual DOGvoid   Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime);

	private:
		Camera2D* pCamera;
		unique_ptr<TextSDL> pWelcome;
		unique_ptr<TextSDL> pName;
		unique_ptr<TextSDL> pInstruccions;
		unique_ptr<TextSDL> pInstruccions2;

		unique_ptr<Sprite> pPrompt;
		unique_ptr<Sprite> pPrint;
	
		string name;

		DOGbool renderPrompt;

		DOGfloat timer;
		DOGfloat t;

		DOGint state;
};

#endif