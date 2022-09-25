#pragma once
#ifndef Enemy_H
#define	Enemy_H

#include "DogEngine/RenderEngine/OpenGL/Sprite.h"

#define SHOOT 0.4
#define ID_BULLET_ENEMY 1002

class Enemy
{
	public:
		Enemy();
		Enemy(string path, DOGint w, DOGint h);
		~Enemy();

		DOGvoid Update(DOGfloat elapsedTime);
		DOGvoid Render();
		DOGvoid Release();
		DOGvoid SetKamikaze(DOGbool b);
		DOGvoid SetXOriginal(DOGfloat x);
		DOGvoid SetYOriginal(DOGfloat y);
		DOGvoid SetVx(DOGfloat v);
		DOGvoid SetVy(DOGfloat v);
		DOGvoid Attack(DOGbool);
		DOGvoid Return();
		DOGvoid SetHeight(DOGint h);
		//DOGvoid SetBulletCollisionable(DOGbool b);
		DOGvoid SetFire(DOGbool b);
		DOGvoid SetLevel(DOGint level);
		DOGvoid SetXPlayer(DOGfloat xPlayer);

		DOGbool IsKamikaze();
		//DOGbool IsBulletCollisionable();
		DOGbool IsFire();

		Sprite* GetSprite();
		//Sprite* GetBullet();

	private:
		DOGbool kamikaze;
		DOGbool attacking, returning;
		DOGbool bulletCollisionable;
		DOGbool d;

		Sprite* pSprite;
		//Sprite* pBullet;

		DOGfloat xOriginal, xo;
		DOGfloat yOriginal, yo;
		DOGfloat vx, vy, xPlayer;
		DOGfloat shoot, fire;

		DOGint height;
		DOGint level;

		DOGvoid pattern1(DOGfloat elapsedTime);
		DOGvoid pattern2(DOGfloat elapsedTime);
};

#endif