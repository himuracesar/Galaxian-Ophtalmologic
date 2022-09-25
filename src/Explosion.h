#pragma once
#ifndef EXPLOSION_PARTICLE_GALAXIAN_H
#define EXPLOSION_PARTICLE_GALAXIAN_H

#include "DogEngine/Core/DogStdafx.h"

#include "DogEngine/RenderEngine/UtilsGraphics.h"
#include "DogEngine/RenderEngine/OpenGL/ParticleSystemGL.h"

class Explosion : public ParticleSystemGL
{
	public:
		Explosion(const string& vertexShaderName,
			const string& fragmentShaderName,
			const string& textureName,
			const DOGVECTOR3& acceleration,
			//const DOGAABB& box,
			DOGint maxNumParticles,
			DOGfloat timePerParticle)
			: ParticleSystemGL(vertexShaderName, fragmentShaderName, textureName, acceleration, maxNumParticles, timePerParticle)
		{}

		void InitParticle(DOGPARTICLE& dp);
};

#endif