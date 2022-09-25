#pragma once
#ifndef DOG_MATERIAL_H
#define DOG_MATERIAL_H

#include "../Core/DogStdafx.h"

#include "DOGCOLOR.h"

typedef struct DOGMATERIAL
{
	DOGCOLOR emissive;
	DOGCOLOR ambient;
	DOGCOLOR diffuse;
	DOGCOLOR specular;
	DOGfloat specularPower;
}DOGMATERIAL;

#endif
