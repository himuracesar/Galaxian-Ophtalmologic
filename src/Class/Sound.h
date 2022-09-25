#pragma once
#ifndef SOUND_H
#define SOUND_H

//#define ACTIVE_SOUND

#include "DogEngine/Core/DogStdafx.h"

class Sound
{
	public:
		Sound();
		virtual ~Sound();

		DOGvoid Release();
		DOGvoid Init();
		DOGvoid PlayMusic();
		DOGvoid PlayExplosion();
		DOGvoid PlayBullet();

	private:
		Mix_Music* pMusic;
		Mix_Chunk* pShot;
		Mix_Chunk* pExplosionSound;
};

#endif