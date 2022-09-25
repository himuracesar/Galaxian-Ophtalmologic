#pragma once
#ifndef DOG_COLOR_H
#define DOG_COLOR_H

#include "../Core/DogMath.h"
#include "../Core/DogStdafx.h"

/**
* Estructura para manejar el vector de colores
*/
typedef struct DOGCOLOR
{
	public:
		DOGCOLOR() { r = g = b = a = 1.0f; };
		DOGCOLOR(DOGCOLOR&);
		DOGCOLOR(const DOGfloat* v) : r(v[0]), g(v[1]), b(v[2]), a(v[3]) {};
		DOGCOLOR(DOGfloat r, DOGfloat g, DOGfloat b, DOGfloat a) : r(r), g(g), b(b), a(a) {};
		DOGCOLOR& operator= (const DOGCOLOR& v);
		DOGCOLOR(const DOGCOLOR& color); //Copy Constructor

		DOGfloat r;
		DOGfloat g;
		DOGfloat b;
		DOGfloat a;
}DOGCOLOR;

const DOGCOLOR RED(1.0f, 0.0f, 0.0f, 1.0f);
const DOGCOLOR GREEN(0.0f, 1.0f, 0.0f, 1.0f);
const DOGCOLOR BLUE(0.0f, 0.0f, 1.0f, 1.0f);
const DOGCOLOR YELLOW(1.0f, 1.0f, 0.0f, 1.0f);
const DOGCOLOR CYAN(0.0f, 1.0f, 1.0f, 1.0f);
const DOGCOLOR MAGENTA(1.0f, 0.0f, 1.0f, 1.0f);
const DOGCOLOR BLACK(0.0f, 0.0f, 0.0f, 1.0f);
const DOGCOLOR WHITE(1.0f, 1.0f, 1.0f, 1.0f);

DOGCOLOR RandomColor();

DOGCOLOR RandomRGB(DOGfloat alpha);

#endif