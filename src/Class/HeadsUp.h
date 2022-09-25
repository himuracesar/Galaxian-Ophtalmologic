#pragma once
#ifndef HEADS_UP_H
#define HEADS_UP_H

#include "DogEngine/Core/DogStdafx.h"
#include "DogEngine/Core/DogError.h"

#include "DogEngine/RenderEngine/DOGCOLOR.h"
#include "DogEngine/RenderEngine/OpenGL/Sprite.h"
#include "DogEngine/RenderEngine/OpenGL/TextSDL.h"

#include "XMLParser.h"

class HeadsUp
{
	public:
		HeadsUp();
		~HeadsUp();

		DOGvoid Init();
		DOGvoid Update(DOGfloat elapsedTime);
		DOGvoid Render();

		DOGvoid SetPlayerName(string name);
		DOGvoid SetPoints(DOGint points);
		DOGvoid SetHighScore(DOGint highScore);
		DOGvoid SetNivel(DOGint nivel);
		DOGvoid SetVidas(DOGint vidas);
		DOGvoid SetColor(DOGCOLOR& c);
		DOGvoid LostLife();
		DOGvoid Save();
		DOGvoid SetGameOver(DOGbool b);
		DOGvoid SetIDSession(DOGint id);

		string GetPlayerName();

		DOGint GetPoints();
		DOGint GetHighScore();
		DOGint GetNivel();
		DOGint GetVidas();
		DOGint GetIDSession();

		DOGCOLOR& GetColor();

		DOGbool IsGameOver();

	private:
		string playerName;

		DOGint points;
		DOGint highScore;
		DOGint nivel;
		DOGint vidas;
		DOGint IDSession;
		
		DOGbool gameOver;

		TextSDL* pText;
		TextSDL* pScore;
		TextSDL* pNivel;

		stringstream ss;

		DOGCOLOR color;

		vector<Sprite*> vVidas;

		unique_ptr<XMLParser> pXml;
};

#endif