#pragma once

#ifndef DOG_STDAFX_H
#define DOG_STDAFX_H

#define CRTDBG_MAP_ALLOC

#pragma comment(lib, "SDL2_ttf.lib")

#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <stdarg.h>
#include <stdint.h>
#include <crtdbg.h>
#include <math.h>
#include <atlbase.h>

#include <string>
#include <sstream>
#include <iostream>
#include <ctime>
#include <fstream>
#include <memory>
#include <vector>
#include <cstring>

//Librerias de SDL2
#include "SDL2/SDL.h"
#include <SDL2/SDL_image.h>
#include "SDL2/SDL_ttf.h"
#include <SDL2/SDL_mixer.h>

//OpenGL
#include "OpenGL.h"
#include <dinput.h>

using namespace std;

// Useful macros
#define DOG_SAFE_RELEASE(x) if( x ) { (x)->Release(); (x) = NULL; }
#define DOG_SAFE_DELETE(x) if( x ) { delete(x); (x) = NULL; }
#define DOG_SAFE_DELETE_ARRAY(x) if( x ) { delete [] (x); (x) = NULL; }

//Tipos de datos Dog
typedef void DOGvoid;
typedef int DOGint;
typedef unsigned int DOGuint;
typedef short DOGshort;
typedef unsigned short DOGushort;
typedef float DOGfloat;
typedef double DOGdouble;
typedef long DOGlong;
typedef bool DOGbool;
typedef char DOGchar;
typedef __int64 DOGint64;
typedef __int32 DOGint32;
typedef __int16 DOGint16;
typedef __int8 DOGint8;
typedef DOGint DOGBOOL;
typedef unsigned char DOGuint8;

//Definiciones para crear los input layout (vertex declarations)
#define POSITION 0x00000001
#define POSITION_COLOR 0x00000002
#define POSITION_COLOR_TEXTURED 0x00000003
#define POSITION_NORMAL_TEXTURED 0x00000004
#define POSITION_TETURED 0x00000005
#define POSITION_2_TEXTURED 0x00000006
#define POSITION_NORMAL_COLOR 0x00000007

//Definiciones para levantar un contexto del modulo de INPUT
#define DIREC_INPUT_8 0x00000001

#endif