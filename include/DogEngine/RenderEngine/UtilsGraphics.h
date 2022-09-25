#pragma once
#ifndef UTILS_GRAPHICS_H
#define UTILS_GRAPHICS_H

#include "DOGCOLOR.h"
#include "OpenGL/Sprite.h"
#include "../Core/DogMath.h"

/**
* Contiene la información de input del Mouse
*
* @param x Coordenada en X cuando se hace clic en la pantalla
* @param y Coordenada en Y cuando se hace clic en la pantalla
* @param xDelta Desplazamiento en X por el mouse
* @param yDelta Desplazamiento en Y por el mouse
* @param zDelta Desplazamiento en Z por el mouse
* @param pMouseButtons Botones que fueron apretados por el mouse en un frame
*/
typedef struct DOG_INPUT_MOUSE
{
	DOGlong x;
	DOGlong y;
	DOGlong xDelta;
	DOGlong yDelta;
	DOGlong zDelta;
	DOGBOOL* pMouseButtons;
}DOG_INPUT_MOUSE;

/**
* Descriptor para crear un cubo
*
* @param type Tipo Vertice con el que sera construido el cubo
* @param width Ancho del cubo (x)
* @param height Alto del cubo (y)
* @param deep Profundidad del cubo (z)
* @param c Color del cubo
*/
typedef struct DOG_CUBE_DESCRIPTOR
{
	DOGint type;
	DOGfloat width; 
	DOGfloat height; 
	DOGfloat depth;
	DOGCOLOR* color;
}DOG_SHAPE;

/**
* Descriptor para la creacion del grid
*
* @param type Son las caracteristicas del vertice con las que sera construido el grid
* @param numVertRows Numero de vertices para las filas
* @param numVertCols Numero de vertices para las columnas
* @param deltaX Separacion de los vertices en el eje X
* @param deltaZ Separacion de los vertices en el eje Z
* @param center Es la coordenada que fungira como centro del grid (pivote)
* @param texScale Escala para generar las coordenadas para la textura
* @param color Color con el que sera construido el grid
*/
typedef struct DOG_GRID_DESCRIPTOR
{
	DOGint type;
	DOGint numVertRows;
	DOGint numVertCols; 
	DOGfloat deltaX;
	DOGfloat deltaZ;
	DOGVECTOR3* center;
	DOGfloat texScale;
	DOGCOLOR* color;
}DOG_GRID_DESCRIPTOR;

/**
* Descriptor para la creacion del cilindro
* 
* @param type Son las caracteristicas del vertice con las que sera construido el cilindro
* @param bottomRadius Es el radio de la base del cilindro
* @param topRadius Es el radio de la tapa del cilindro
* @param sliceCount Numero de "rebanadas" o vertices que contendra cada anillo del cilindro
* @param stackCount Es el numero de pila que conformaran el cilindro cada pila esta formada por 1 anillos
* @param color Color con el se creara el cilindro
*/
typedef struct DOG_CYLINDER_DESCRIPTOR
{
	DOGint type;
	DOGfloat bottomRadius; 
	DOGfloat topRadius; 
	DOGfloat height; 
	DOGuint sliceCount; 
	DOGuint stackCount;
	DOGCOLOR* color;
}DOG_CYLINDER_DESCRIPTOR;

/**
* Descriptor para la creacion de la esfera
*
* @param type Son las caracteristicas del vertice con las que sera construido la esfera
* @param radius Es el radio de la base de la esfera
* @param sliceCount Numero de "rebanadas" o vertices que contendra cada anillo de la esfera
* @param stackCount Es el numero de pila que conformaran la esfera cada pila esta formada por 1 anillos
* @param color Color con el se creara la esfera
*/
typedef struct DOG_SPHERE_DESCRIPTOR
{
	DOGint type;
	DOGfloat radius;
	DOGuint sliceCount;
	DOGuint stackCount;
	DOGCOLOR* color;
}DOG_SPHERE_DESCRIPTOR;

/**
* Descriptor para la creacion de la geoesfera
*
* @param type Son las caracteristicas del vertice con las que sera construido la esfera
* @param radius Es el radio de la base de la esfera
* @param numSubdivision Numero de subdivisiones con las que la esfera sera teselada
* @param color Color con el se creara la esfera
*/
typedef struct DOG_GEOSPHERE_DESCRIPTOR
{
	DOGint type;
	DOGfloat radius;
	DOGuint numSubdivisions;
	DOGCOLOR* color;
}DOG_GEOSPHERE_DESCRIPTOR;

typedef struct DOGPARTICLE
{
	public:
		DOGPARTICLE();
		DOGPARTICLE(const DOGPARTICLE& dp) {};
		//DOGPARTICLE(const DOGPARTICLE* dp) {};

		DOGVECTOR3  position;
		DOGVECTOR3  velocity;
		float       size; // In pixels.
		float       initialTime;
		float       lifeTime;
		float       mass;
		DOGCOLOR    color;
		float angle;
}DOGPARTICLE;

typedef struct DOGTILE
{
public:
	DOGTILE() {};

	DOGVECTOR3 position;
	int idTile;
	bool collisionable;
	int idTileset;
}DOGTILE;

typedef struct COLLISION
{
	int idTypeCollision;
	Sprite *sp1;
	Sprite *sp2;
}COLLISION;


typedef struct DOGTILESET
{
	int firstTile;
	string image;
	//unsigned int texture;
	GLuint texture;
	int height;
	int width;
	int rows;
	int cols;
	int tileHeight;
	int tileWidth;
}DOGTILESET;

typedef struct DOGPOINT
{
	int x;
	int y;
	float distance;
	string id;
}DOGPOINT;

typedef struct COLLISION_2D_MAP
{
	DOGPOINT dp;
	int typeCollision;
}COLLISION_2D_MAP;


#endif