#pragma once
#ifndef NIVEL_8_H	
#define NIVEL_8_H

#include "DogEngine/Common/CollisionGroup.h"
#include "DogEngine/Common/CollisionManager.h"

#include "DogEngine/Core/DogBaseApp.h"
#include "DogEngine/Core/DogSceneGraph.h"
#include "DogEngine/Core/OpenGLFrameworkLayer.h"
#include "DogEngine/Core/DogStdafx.h"

#include "DogEngine/RenderEngine/Camera2D.h"
#include "DogEngine/RenderEngine/DOGCOLOR.h"
#include "DogEngine/RenderEngine/OpenGL/AnimatedSprite.h"
#include "DogEngine/RenderEngine/OpenGL/Sprite.h"
#include "DogEngine/RenderEngine/OpenGL/TextSDL.h"

#include "Class/Enemy.h"
#include "Class/GlxCommons.h"
#include "Class/HeadsUp.h"
#include "Class/Scores.h"
#include "Class/Sound.h"
#include "Class/XMLParser.h"
#include "Explosion.h"
#include "States.h"

#define X_SPACE_ENEMIES 12 //Espacio en X entre los enemigos de la tropa
#define Y_SPACE_ENEMIES 6 //Espacio en Y entre los enemigos de la tropa
#define WIDTH_MARGIN 150
#define HEIGHT_MARGIN 60
#define SPACE_PLAYER_AND_TROOP 200
#define WIDTH_ENEMY 40
#define HEIGHT_ENEMY 15
#define MAX_ENEMIES_X 10
#define MAX_ENEMIES_Y 6
#define ID_PLAYER 1000
#define ID_BULLET_PLAYER 1001
#define ID_BULLET_ENEMY 100
#define PLAYER_GROUP 1
#define ENEMY_GROUP 2
#define RELATIONSHIP_PLAYER_ENEMY 1
#define TROOPS 2
#define ATTACK 1.5 //Tiempo en segundos para que un enemigo ataque
#define POINTS_KILL 20
//States
#define STATE_FINISH 1
#define STATE_CHANGE_TROOP 2
#define STATE_PLAY 3
#define STATE_GAME_OVER 4
#define STATE_REVENANT 5

class Nivel8 : public DogBaseApp
{
	public:
		Nivel8();
		virtual ~Nivel8();

		virtual DOGRESULT Init();
		virtual DOGvoid	  Release();
		virtual DOGvoid	  Update(DOGfloat elapsedTime);
		virtual DOGvoid	  Render();
		virtual DOGvoid   Input(DOG_INPUT_MOUSE dim, DOGBOOL* pPressedKeys, vector<DOGBOOL>* pLockKeys, DOGfloat elapsedTime);

	private:
		Camera2D* pCamera;

		DOGCOLOR colorFondo;

		DOGfloat vxPlayer;
		DOGfloat vyBullet;
		DOGfloat velEnemy;
		DOGfloat timeToPlay;
		DOGfloat seconds;
		DOGfloat velEnemyBullet;
		DOGint troopCount;
		DOGint state;
		DOGbool play;
		DOGint idBulletEnemy;

		Sprite* pPlayer;
		Sprite* pBullet;

		vector<Enemy*> *pEnemigos;
		vector<Sprite*> vEnemyBullets;

		CollisionManager* pCollisionManager;

		vector<ParticleSystemGL*>* pExplosions;
		//ParticleSystemGL* pParticle;

		XMLParser* pXml;
		HeadsUp* pHeadsUp;

		TextSDL* pText;

		stringstream ss;

		AnimatedSprite* pASexplosion;

		unique_ptr<Scores> pScores;

		//****** FUNCIONES *******
		DOGvoid IniciaTropa(DOGbool f);
		DOGvoid DeleteEnemy(DOGint id);
		DOGvoid Explote(DOGfloat x, DOGfloat y, DOGfloat z);
		DOGvoid CreateExplosion();
		DOGvoid CheckLifes();

		DOGbool CheckExplosionLive();

		unique_ptr<TextSDL> pTextAdditional;

		unique_ptr<Sound> pSound;
};

#endif