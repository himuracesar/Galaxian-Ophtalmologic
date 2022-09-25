#include "Sound.h"

Sound::Sound()
{

}

Sound::~Sound()
{
	Release();
}

DOGvoid Sound::Release()
{
	Mix_HaltMusic();
	Mix_FreeMusic(pMusic);
	Mix_FreeChunk(pShot);
	Mix_FreeChunk(pExplosionSound);
}

DOGvoid Sound::Init()
{
	pMusic = Mix_LoadMUS("glx/sounds/music1.mid");

	Mix_VolumeMusic(70);

	pShot = Mix_LoadWAV("glx/sounds/laser_gun_shot.wav");
	pExplosionSound = Mix_LoadWAV("glx/sounds/bomb_explosion.wav");
}

DOGvoid Sound::PlayMusic()
{
	#ifdef ACTIVE_SOUND
		Mix_PlayMusic(pMusic, -1);
	#endif
}

DOGvoid Sound::PlayExplosion()
{
	#ifdef ACTIVE_SOUND
		Mix_PlayChannel(-1, pExplosionSound, 0);
	#endif
}

DOGvoid Sound::PlayBullet()
{
	#ifdef ACTIVE_SOUND
		Mix_PlayChannel(-1, pShot, 0);
	#endif
}