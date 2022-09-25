#pragma once
#ifndef SCORES_SCREEN_H
#define SOCRES_SCREEN_H

#include "DogEngine/Core/DogBaseApp.h"
#include "DogEngine/Core/DogStdafx.h"

#include "DogEngine/RenderEngine/Camera2D.h"
#include "DogEngine/RenderEngine/OpenGL/OpenGLRenderer.h"
#include "DogEngine/RenderEngine/OpenGL/Sprite.h"
#include "DogEngine/RenderEngine/OpenGL/TextSDL.h"

#include "Class/XMLParser.h"
#include "Class/Scores.h"
#include "States.h"

#define SIZE_TITLES 25
#define SIZE_ELEMENTS 15
#define LAST_LEVEL 1

class ScoresScreen : public DogBaseApp
{
	public:
		ScoresScreen();
		virtual ~ScoresScreen();

		virtual DOGRESULT Init();
		virtual DOGvoid	  Release();
		virtual DOGvoid	  Update(DOGfloat elapsedTime);
		virtual DOGvoid	  Render();
		virtual DOGvoid   Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime);

	private:
		Camera2D* pCamera;

		unique_ptr<TextSDL> pTitleName;
		unique_ptr<TextSDL> pTitleLevel;
		unique_ptr<TextSDL> pTitleScore;
		unique_ptr<TextSDL> pName;
		unique_ptr<TextSDL> pLevel;
		unique_ptr<TextSDL> pScore;

		vector<SCORE> v;

		DOGint state;

		DOGbool gameOver;
};

#endif