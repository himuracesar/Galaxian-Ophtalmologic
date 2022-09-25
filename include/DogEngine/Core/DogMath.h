#pragma once
//
//  DogMath.h
//  Dog Game Engine
//
//  Created by César Himura on 05/11/14.
//  Copyright (c) 2014 César Himura. All rights reserved.
//

#ifndef DOGMATH_H
#define DOGMATH_H

#include "DogStdafx.h"

#define DOG_PI    (3.141592654f)

/**
* Convierte un angulo en grados a radianes
*
* @param degree Angulo en grados
*/
#define DOGToRadian( degree ) ((degree) * (DOG_PI / 180.0f))

/**
* Convierte un angulo en radianes a grados
*
* @param radian  Angulo en radianes
*/
#define DOGToDegree( radian ) ((radian) * (180.0f / DOG_PI))

/**
* Determina el numero minimo de entre los 2 numeros enviados
*
* @param a Valor 1 a ser evualudo
* @param b Valor 2 a ser evaluado
*/
#define DOGMin(a, b)  (((a) < (b)) ? (a) : (b)) 

/**
* Determina el numero maximo de entre los 2 numeros enviados
*
* @param a Valor 1 a ser evualudo
* @param b Valor 2 a ser evaluado
*/
#define DOGMax(a, b)  (((a) > (b)) ? (a) : (b)) 

/**
* Genera un numero random en el intervalo inclusivo de [from, to]. El valor generado siempre sera entero
*
* @param from Limite inferior del intervalo
* @param to Limite superior del intervalo
*/
#define DOGRandomNumber(from, to) (DOGMin(rand() % to + from, RAND_MAX))

/**************************************************************
* VECTOR 3D
***************************************************************/

/**
* Estructura que almacena la información a un vector 3D
*/
typedef struct DOGVECTOR3
{
	public:
		DOGVECTOR3() { x = y = z = 0.0f; };
		DOGVECTOR3(DOGVECTOR3&);
		DOGVECTOR3(const DOGfloat* v) : x(v[0]), y(v[1]), z(v[2]) {};
		DOGVECTOR3(DOGfloat x, DOGfloat y, DOGfloat z) : x(x), y(y), z(z) {};

		DOGfloat x;
		DOGfloat y;
		DOGfloat z;

		DOGVECTOR3& operator += (const DOGVECTOR3&);
		DOGVECTOR3& operator -= (const DOGVECTOR3&);
		DOGVECTOR3& operator *= (const DOGfloat);
		DOGVECTOR3& operator /= (const DOGfloat);

		DOGVECTOR3 operator + (const DOGVECTOR3&) const;
		DOGVECTOR3 operator - (const DOGVECTOR3&) const;
		DOGVECTOR3 operator * (DOGfloat) const;
		DOGVECTOR3 operator / (DOGfloat) const;
}DOGVECTOR3;

/**************************************************************
* VECTOR 4D
***************************************************************/

/**
* Estructura que almacena la información a un vector 4D
*/
typedef struct DOGVECTOR4
{
	public:
		DOGVECTOR4() { x = y = z = w = 0.0f; };
		DOGVECTOR4(DOGVECTOR4&);
		DOGVECTOR4(const DOGfloat* v) : x(v[0]), y(v[1]), z(v[2]), w(v[3]) {};
		DOGVECTOR4(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat w) : x(x), y(y), z(z), w(w) {};

		DOGfloat x;
		DOGfloat y;
		DOGfloat z;
		DOGfloat w;

		DOGVECTOR4& operator += (const DOGVECTOR4&);
		DOGVECTOR4& operator -= (const DOGVECTOR4&);
		DOGVECTOR4& operator *= (const DOGfloat);
		DOGVECTOR4& operator /= (const DOGfloat);

		DOGVECTOR4 operator + (const DOGVECTOR4&) const;
		DOGVECTOR4 operator - (const DOGVECTOR4&) const;
		DOGVECTOR4 operator * (DOGfloat) const;
		DOGVECTOR4 operator / (DOGfloat) const;
}DOGVECTOR4;


/**************************************************************
* MATRIX 4x4
***************************************************************/
/**
* Estructura que almacena información en forma de matriz 4x4
*/
typedef struct DOGMATRIX
{
	public:
		DOGMATRIX() {};
		DOGMATRIX(const DOGfloat*);
		DOGMATRIX(const DOGMATRIX&);
		DOGMATRIX(DOGfloat f11, DOGfloat f12, DOGfloat f13, DOGfloat f14,
			DOGfloat f21, DOGfloat f22, DOGfloat f23, DOGfloat f24,
			DOGfloat f31, DOGfloat f32, DOGfloat f33, DOGfloat f34,
			DOGfloat f41, DOGfloat f42, DOGfloat f43, DOGfloat f44);

		union
		{
			struct
			{
				DOGfloat _11, _12, _13, _14;
				DOGfloat _21, _22, _23, _24;
				DOGfloat _31, _32, _33, _34;
				DOGfloat _41, _42, _43, _44;
			};
			DOGfloat m[4][4];
		};

		DOGfloat& operator () (unsigned int Row, unsigned int Col);
		DOGfloat operator () (unsigned int Row, unsigned int Col) const;

		DOGMATRIX& operator *= (const DOGMATRIX&);
		DOGMATRIX& operator /= (const DOGfloat);

		DOGMATRIX operator * (const DOGMATRIX&) const;
		DOGMATRIX operator / (const DOGfloat) const;

		DOGfloat* ToArrayFloat();

	private:
		DOGfloat mf[16];

}DOGMATRIX;

/**************************************************************
* MATRIX 3x3
***************************************************************/
/**
* Estructura que almacena información en forma de matriz 3x3
*/
typedef struct DOGMATRIX3x3
{
	public:
		DOGMATRIX3x3() {};
		DOGMATRIX3x3(const DOGfloat*);
		DOGMATRIX3x3(const DOGMATRIX3x3&);
		DOGMATRIX3x3(DOGfloat f11, DOGfloat f12, DOGfloat f13,
			DOGfloat f21, DOGfloat f22, DOGfloat f23,
			DOGfloat f31, DOGfloat f32, DOGfloat f33);

		union
		{
			struct
			{
				DOGfloat _11, _12, _13;
				DOGfloat _21, _22, _23;
				DOGfloat _31, _32, _33;
			};
			DOGfloat m[3][3];
		};

		DOGfloat& operator () (unsigned int Row, unsigned int Col);
		DOGfloat operator () (unsigned int Row, unsigned int Col) const;

		DOGMATRIX3x3& operator *= (const DOGMATRIX3x3&);

		DOGMATRIX3x3 operator * (const DOGMATRIX3x3&) const;

}DOGMATRIX3x3;

/**************************************************************
* PLANE
***************************************************************/
/**
* Define un plano
*/
typedef struct DOGPLANE {
	DOGfloat a;
	DOGfloat b;
	DOGfloat c;
	DOGfloat d;
} DOGPLANE;

/**************************************************************
* FUNCIONES VECTOR 3D
***************************************************************/
/**
* Calcula la longitud de un vector 3D
*
* @param pV Puntero al vector que se le calculara la longitud
* @return La longitud del vector
*/
DOGfloat DOGVector3Length(const DOGVECTOR3 *pV);

/**
* Normaliza un vector. Al normalizar el vector lo convierte en un vector
* unitario (de longitud 1)
*
* @param pOut Puntero al vector normalizado que se regresara
* @param pV Puntero al vector que se normalizara
* @return El vector normalizado
*/
DOGVECTOR3* DOGVector3Normalize(DOGVECTOR3 *pOut, const DOGVECTOR3 *pV);

/**
* Producto punto de 2 vectores
*
* @param pV1 Puntero al primero vector que se multiplicara
* @param pV2 Puntero al segundo vector que se multiplicara
* @return Regresa el resultado de la multiplicación
*/
DOGfloat DOGVector3Dot(const DOGVECTOR3 *pV1, const DOGVECTOR3 *pV2);

/**
* Producto cruz entre 2 vectores
*
* @param pOut Puntero al vector que contendrá el resultado
* @param pV1 Puntero al primer vector que se multiplicará
* @param pV2 Puntero al segundo vector que se multiplicará
* @return El vector con el resultado de la multiplicación
*/
DOGVECTOR3* DOGVector3Cross(DOGVECTOR3 *pOut, const DOGVECTOR3 *pV1, const DOGVECTOR3 *pV2);

/**
* Transforma un vector 3D normalizado por una matriz dada
*
* @param pOut Puntero al vector que contendrá el resultado
* @param pV Puntero al vector que se transformará
* @param pM Puntero a la matriz
*/
DOGVECTOR3* DOGVector3TransformNormal(DOGVECTOR3 *pOut, const DOGVECTOR3 *pV, const DOGMATRIX *pM);

/**************************************************************
* FUNCIONES MATRIX 4X4
***************************************************************/
/**
* Regresa la matriz de identidad
*
* @param pOut Puntero a la Matriz de Identididad
*/
DOGMATRIX* DOGMatrixIdentity(DOGMATRIX *pOut);

/**
* Realiza la mulplicación de 2 matrices 4x4. La función puede regresar la matriz como resultado
* principal o como segunda vía
*
* @param pOut Es un puntero a la matriz que regresa como resultado en segunda vía
* @param pM1 Puntero a la matriz que se multiplicara
* @param pM2 Puntero a la matriz que se multiplicara
* @return Regresa la matriz con la multiplicación hecha
*/
DOGMATRIX* DOGMatrixMultiply(DOGMATRIX *pOut, const DOGMATRIX *pM1, const DOGMATRIX *pM2);

/**
* Transpone una matriz 4x4
*
* @param pOut Puntero de salida a la matriz transpuesta
* @param pM Matriz que sera transpuesta
* @param return Regresa la matriz transpuesta
*/
DOGMATRIX* DOGMatrixTranspose(DOGMATRIX *pOut, const DOGMATRIX *pM);

/**
* Calcula la inversa de una matriz 4x4. Lo hace por cofactores y determinante de
* una matriz
*
* @param pOut Puntero de salida a la matriz inversa
* @param pM Matriz que sera invertida
* @return La matriz invertida
*/
DOGMATRIX* DOGMatrixInverse(DOGMATRIX *pOut, const DOGMATRIX *pM);

/**
* Crea la View Matrix que es la matriz de la cámara. También se le conoce como
* matriz del mundo (World Matrix) invertida en un sistema de Mano Izquierda
*
* @param pOut Puntero de salida a la View Matrix
* @param pEye Es la posición de la cámara en el universo
* @param pLookAt Es la posición a donde apuntara la cámara
* @param pUp Es hacia donde apunta la parte de arriba de la cámara generalmente siempre
*		     es (0, 1, 0)
*/
DOGMATRIX* DOGViewMatrixLH(DOGMATRIX *pOut, const DOGVECTOR3 *pEye, const DOGVECTOR3 *pLookAt, const DOGVECTOR3 *pUp);

/**
* Crea la View Matrix que es la matriz de la cámara. También se le conoce como
* matriz del mundo (World Matrix) invertida en un sistema de Mano Derecha
*
* @param pOut Puntero de salida a la View Matrix
* @param pEye Es la posición de la cámara en el universo
* @param pLookAt Es la posición a donde apuntara la cámara
* @param pUp Es hacia donde apunta la parte de arriba de la cámara generalmente siempre
*		     es (0, 1, 0)
*/
DOGMATRIX* DOGViewMatrixRH(DOGMATRIX *pOut, const DOGVECTOR3 *pEye, const DOGVECTOR3 *pLookAt, const DOGVECTOR3 *pUp);

/**
* Crea la matriz de proyección en un sistema de Mano Derecha
*
* @param pOut Es un puntero de salida a la matriz de proyección creada
* @param fovY Es el Field Of View Angle Height (Y) ó ángulo lateral del frustum
* @param aspectRatio Esta dado por la razón de width/height
* @param zn Es el near plane. Generalmente es 0
* @param zf Es el far plane. Generalmente es 1
*/
DOGMATRIX* DOGPerspectiveProjectionMatrixLH(DOGMATRIX* pOut, DOGfloat fovY, DOGfloat aspectRatio, DOGfloat zn, DOGfloat zf);

/**
* Crea la matriz de proyección en un sistema de Mano Derecha
*
* @param pOut Es un puntero de salida a la matriz de proyección creada
* @param fovY Es el Field Of View Angle Height (Y) ó ángulo lateral del frustum
* @param aspectRatio Esta dado por la razón de width/height
* @param zn Es el near plane. Generalmente es 0
* @param zf Es el far plane. Generalmente es 1
*/
DOGMATRIX* DOGPerspectiveProjectionMatrixRH(DOGMATRIX* pOut, DOGfloat fovY, DOGfloat aspectRatio, DOGfloat zn, DOGfloat zf);

/**
* Crea la matriz de proyección en perspectiva en un sistema de Mano Derecha, mas en concreto como lo hace OpenGL.
* La coordenada X se mapea de -1 a 1
* La coordenada Y se mapea de -1 a 1
* La coordenada Z se mapea de -1 a 1
* Compatible con OpenGL ES 2.0
*
* @param pOut Es un puntero de salida a la matriz de proyección creada
* @param fovY Es el Field Of View Angle Height (Y) ó ángulo lateral del frustum
* @param aspectRatio Esta dado por la razón de width/height
* @param zn Es el near plane.
* @param zf Es el far plane.
*/
DOGMATRIX* DOGPerspectiveProjectionMatrixGL(DOGMATRIX* pOut, DOGfloat fovY, DOGfloat aspectRatio, DOGfloat zn, DOGfloat zf);

/**
* Crea la matriz de proyección en perspectiva en un sistema de Mano Derecha, mas en concreto como lo hace OpenGL.
* Esta función hace lo mismo que la matrz de perspectiva. Solo que los objetos (según las pruebas) se aprecian
* mas pequeños. La matriz que se utiliza para hacer el cálculo es una matriz no reducida como lo es la de perspectiva
* utilizada en DOGPerspectiveProjectionMatrixGL.
*
* La coordenada X se mapea de -1 a 1
* La coordenada Y se mapea de -1 a 1
* La coordenada Z se mapea de -1 a 1
* Compatible con OpenGL ES 2.0
*
* @param pOut Es un puntero de salida a la matriz de proyección creada
* @param fovY Es el Field Of View Angle Height (Y) ó ángulo lateral del frustum
* @param aspectRatio Esta dado por la razón de width/height
* @param zn Es el near plane.
* @param zf Es el far plane.
*/
DOGMATRIX* DOGFrustumGL(DOGMATRIX* pOut, DOGfloat fovY, DOGfloat aspectRatio, DOGfloat zn, DOGfloat zf);

/**
* Crea la matriz de proyección en ortogonal en un sistema de Mano Derecha, mas en concreto en OpenGL. Esta matriz es generada
* por la función glOrtho en versiones de OpenGL 2 y OpenGL 1.1
* La función calcula en automático el left, right, bottom y top de la proyección. Deja la coordenada (0,0) justo en el centro
* de la pantalla.
* Los cálculos por default para los limites son:
* left = -width/2
* right = width/2
* bottom = -height/2
* top = height/2
*
* @param pOut Es un puntero de salida a la matriz de proyección creada
* @param width Es el ancho de la pantalla.
* @param height Es el largo de la pantalla.
* @param zn Es el near plane.
* @param zf Es el far plane.
*/
DOGMATRIX* DOGOrthogonalProjectionMatrixGL(DOGMATRIX* pOut, int width, int height, DOGfloat zn, DOGfloat zf);

/**
* Crea la matriz de proyección en ortogonal en un sistema de Mano Derecha, mas en concreto en OpenGL. Esta matriz es generada
* por la función glOrtho en versiones de OpenGL 2 y OpenGL 1.1
* El usuario debe proporcionar los valores para los limites de la pantalla
*
* @param pOut Es un puntero de salida a la matriz de proyección creada
* @param left Limite izquierdo de la pantalla de donde se podrá dibujar
* @param right Limite derecho de la pantalla de donde se podrá dibujar
* @param bottom Limite inferior de la pantalla de donde se podrá dibujar
* @param top Limite superior de la pantalla de donde se podrá dibujar
* @param zn Es el near plane.
* @param zf Es el far plane.
*/
DOGMATRIX* DOGOrthogonalProjectionMatrixGL(DOGMATRIX* pOut, int left, int right, DOGfloat bottom, DOGfloat top, DOGfloat zn, DOGfloat zf);

/**
* Hace una Traslación en el espacio vectorial 3D. Sistema de Mano Izquierda
*
* @param pOut Almacena el resultado de la operación
* @param x Desplazamiento en X
* @param y Desplazamiento en Y
* @param z Desplazamiento en Z
*/
DOGMATRIX* DOGMatrixTranslateLH(DOGMATRIX *pOut, DOGfloat x, DOGfloat y, DOGfloat z);

/**
* Hace una Traslación en el espacio vectorial 3D. Sistema de Mano Derecha.
*
* @param pOut Almacena el resultado de la operación
* @param x Desplazamiento en X
* @param y Desplazamiento en Y
* @param z Desplazamiento en Z
*/
DOGMATRIX* DOGMatrixTranslateRH(DOGMATRIX* pOut, DOGfloat x, DOGfloat y, DOGfloat z);

/**
* Hace una rotación en el eje X. Sistema mano izuquierda. En un ángulo específicado en radianes
*
* @param pOut Almacena el resultado de la operación
* @param angle Ángulo en que girará sobre el eje. Es radianes
*/
DOGMATRIX* DOGMatrixRotationXLH(DOGMATRIX *pOut, DOGfloat angle);

/**
* Hace una rotación en el eje Y. Sistema mano izuquierda. En un ángulo específicado en radianes
*
* @param pOut Almacena el resultado de la operación
* @param angle Ángulo en que girará sobre el eje. Es radianes
*/
DOGMATRIX* DOGMatrixRotationYLH(DOGMATRIX *pOut, DOGfloat angle);

/**
* Hace una rotación en el eje Z. Sistema mano izuquierda. En un ángulo específicado en radianes
*
* @param pOut Almacena el resultado de la operación
* @param angle Ángulo en que girará sobre el eje. Es radianes
*/
DOGMATRIX* DOGMatrixRotationZLH(DOGMATRIX *pOut, DOGfloat angle);

/**
* Hace una rotación en el eje X. En un ángulo específicado en radianes
*
* @param pOut Almacena el resultado de la operación
* @param angle Ángulo en que girará sobre el eje. Es radianes
*/
DOGMATRIX* DOGMatrixRotationXRH(DOGMATRIX *pOut, DOGfloat angle);

/**
* Hace una rotación en el eje Y. En un ángulo específicado en radianes
*
* @param pOut Almacena el resultado de la operación
* @param angle Ángulo en que girará sobre el eje. Es radianes
*/
DOGMATRIX* DOGMatrixRotationYRH(DOGMATRIX *pOut, DOGfloat angle);

/**
* Hace una rotación en el eje Z. En un ángulo específicado en radianes
*
* @param pOut Almacena el resultado de la operación
* @param angle Ángulo en que girará sobre el eje. Es radianes
*/
DOGMATRIX* DOGMatrixRotationZRH(DOGMATRIX *pOut, DOGfloat angle);

/**
* Hace una escalación en los diferentes ejes
*
* @param x Escalamiento en x
* @param y Escalamiento en x
* @param z Escalamiento en z
*/
DOGMATRIX* DOGMatrixScale(DOGMATRIX *pOut, DOGfloat x, DOGfloat y, DOGfloat z);

/**
* Crea un matriz que rota alrededor de un eje arbitrario
*
* @param pOut Puntero a la matriz resultante
* @param pV Puntero al eje arbitrario
* @param angle Angulo de rotación en radianes
*/
DOGMATRIX* DOGMatrixRotationAxis(DOGMATRIX *pOut, const DOGVECTOR3 *pV, DOGfloat angle);

/**************************************************************
* FUNCIONES MATRIX 3x3
***************************************************************/
/**
* Realiza la mulplicación de 2 matrices 3x3. La función puede regresar la matriz como resultado
* principal o como segunda vía
*
* @param pOut Es un puntero a la matriz que regresa como resultado en segunda vía
* @param pM1 Puntero a la matriz que se multiplicara
* @param pM2 Puntero a la matriz que se multiplicara
* @return Regresa la matriz con la multiplicación hecha
*/
DOGMATRIX3x3* DOGMatrix3x3Multiply(DOGMATRIX3x3 *pOut, const DOGMATRIX3x3 *pM1, const DOGMATRIX3x3 *pM2);

/**************************************************************
* FUNCIONES VECTOR 4D
***************************************************************/
DOGVECTOR4* DOGVector4Transform(DOGVECTOR4 *pOut, DOGVECTOR4 *pV, DOGMATRIX *pM);

/**************************************************************
* FUNCIONES DOGPLANE
***************************************************************/
/**
* Normaliza un plano
* @param pOut Es un puntero al plano normalizado
* @param pP Plano que se normalizará
*/
DOGPLANE* DOGPlaneNormalize(DOGPLANE *pOut, const DOGPLANE *pP);

/**************************************************************
* FUNCIONES PARA COMPATIBILIDAD DE OPENGL ES 2.0
***************************************************************/
DOGfloat* CovertDOGMATRIXToFloatArray(DOGfloat* pOut, DOGMATRIX *pM);

/**************************************************************
* FUNCIONES
***************************************************************/

/**
* Cálcula un número potencia de 2 a partir de otro número
*
* @param n Número a partir del cual se cálcula el resultado
*/
int PowerOfTwo(int n);

/**
* Calcula la distancia entre dos puntos sin sacar la raíz cuadrada
*
* @param x1 Coordenada en X del punto 1
* @param y1 Coordenada en Y del punto 1
* @param x2 Coordenada en X del punto 2
* @param y2 Coordenada en Y del punto 2
*/
DOGfloat DistanceTwoPointNoSQRT(DOGfloat x1, DOGfloat y1, DOGfloat x2, DOGfloat y2);

/**
* Cálcula el producto punto entre un plano y vector 3D. Se asume que el parámetro w del vector es 1
* @param pP Puntero al plano
* @param pV Puntero al vector 3D
*/
DOGfloat DOGPlaneDotCoord(const DOGPLANE *pP, const DOGVECTOR3 *pV);

//DOGint DOGRandomNumber(DOGint from, DOGint to);

#endif
