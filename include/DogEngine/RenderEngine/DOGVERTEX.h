#pragma once
#ifndef DOG_VERTEX_H
#define DOG_VERTEX_H

#include "../Core/DogStdafx.h"

/**
* Contiene la estructuras para tener los datos en crudo, convertirlos en un buffer y mandarlos
* a los shaders
*/
namespace DOGVERTEX
{
	typedef struct Position
	{
		public:
			Position() : X(0), Y(0), Z(0) {}
			Position(DOGfloat x, DOGfloat y, DOGfloat z)
				: X(x), Y(y), Z(z) {}
			DOGfloat X, Y, Z;
	} Position;

	typedef struct PositionColor
	{
		public:
			PositionColor() : X(0), Y(0), Z(0), R(0), G(0), B(0), A(0) {}
			PositionColor(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat r, DOGfloat g, DOGfloat b, DOGfloat a)
				: X(x), Y(y), Z(z), R(r), G(g), B(b), A(a) {}
			DOGfloat X, Y, Z;
			DOGfloat R, G, B, A;
	} PositionColor;

	typedef struct PositionColorTextured
	{
		public:
			PositionColorTextured() : X(0), Y(0), Z(0), R(0), G(0), B(0), A(0), Tu(0), Tv(0) {}
			PositionColorTextured(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat r, DOGfloat g, DOGfloat b, DOGfloat a, DOGfloat tu, DOGfloat tv)
				: X(x), Y(y), Z(z), R(r), G(g), B(b), A(a), Tu(tu), Tv(tv) {}
			DOGfloat X, Y, Z;
			DOGfloat R, G, B, A;
			DOGfloat Tu, Tv;
	} PositionColorTextured;

	typedef struct PositionNormalTextured
	{
		public:
			PositionNormalTextured() : X(0), Y(0), Z(0), Nx(0), Ny(0), Nz(0), Tu(0), Tv(0) {}
			PositionNormalTextured(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat nx, DOGfloat ny, DOGfloat nz, DOGfloat tu, DOGfloat tv)
				: X(x), Y(y), Z(z), Nx(nx), Ny(ny), Nz(nz), Tu(tu), Tv(tv) {}
			DOGfloat X, Y, Z;
			DOGfloat Nx, Ny, Nz;
			DOGfloat Tu, Tv;
	} PositionNormalTextured;

	typedef struct PositionTextured
	{
		public:
			PositionTextured() : X(0), Y(0), Z(0), Tu(0), Tv(0) {}
			PositionTextured(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat tu, DOGfloat tv)
				: X(x), Y(y), Z(z), Tu(tu), Tv(tv) {}
			DOGfloat X, Y, Z;
			DOGfloat Tu, Tv;
	} PositionTextured;

	typedef struct Position2Textured
	{
		public:
			Position2Textured() : X(0), Y(0), Z(0), Tu1(0), Tv1(0), Tu2(0), Tv2(0) {}
			Position2Textured(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat tu1, DOGfloat tv1, DOGfloat tu2, DOGfloat tv2)
				: X(x), Y(y), Z(z), Tu1(tu1), Tv1(tv1), Tu2(tu2), Tv2(tv2) {}
			DOGfloat X, Y, Z;
			DOGfloat Tu1, Tv1;
			DOGfloat Tu2, Tv2;
	} Position2Textured;

	typedef struct PositionNormalColor
	{
		public:
			PositionNormalColor() : X(0), Y(0), Z(0), Nx(0), Ny(0), Nz(0), R(0), G(0), B(0), A(0) {}
			PositionNormalColor(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat nx, DOGfloat ny, DOGfloat nz, DOGfloat r, DOGfloat g, DOGfloat b, DOGfloat a)
				: X(x), Y(y), Z(z), Nx(nx), Ny(ny), Nz(nz), R(r), G(g), B(b), A(a) {}
			DOGfloat X, Y, Z;
			DOGfloat Nx, Ny, Nz;
			DOGfloat R, G, B, A;
	} PositionNormalColor;

	typedef struct Color
	{
		public:
			Color() : R(0), G(0), B(0), A(0) {}
			Color(DOGfloat r, DOGfloat g, DOGfloat b, DOGfloat a)
				: R(r), G(g), B(b), A(a) {}
			DOGfloat R, G, B, A;
	} Color;

	typedef struct PosNorTexBinTan
	{
		public:
			PosNorTexBinTan() : X(0), Y(0), Z(0), Nx(0), Ny(0), Nz(0), Tu(0), Tv(0), Bx(0), By(0), Bz(0), Tanx(0), Tany(0), Tanz(0) {}
			PosNorTexBinTan(DOGfloat x, DOGfloat y, DOGfloat z, DOGfloat nx, DOGfloat ny, DOGfloat nz, DOGfloat tu, DOGfloat tv,
				DOGfloat bx, DOGfloat by, DOGfloat bz, DOGfloat tanx, DOGfloat tany, DOGfloat tanz)
				: X(x), Y(y), Z(z), Nx(nx), Ny(ny), Nz(nz), Tu(tu), Tv(tv), Bx(bx), By(by), Bz(bz), Tanx(tanx), Tany(tany), Tanz(tanz) {}
			DOGfloat X, Y, Z;
			DOGfloat Nx, Ny, Nz;
			DOGfloat Tu, Tv;
			DOGfloat Bx, By, Bz;
			DOGfloat Tanx, Tany, Tanz;
	} PosNorTexBinTan;
}

#endif