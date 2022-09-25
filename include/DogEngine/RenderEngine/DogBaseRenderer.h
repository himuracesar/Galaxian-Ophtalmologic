#pragma once
#ifndef DOG_BASE_RENDERER_H
#define DOG_BASE_RENDERER_H

#include "../Core/DogError.h"
#include "../Core/DogStdafx.h"

/**
* Clase base para crear un renderer en cualquier API gráfica
*
* @author Cesar Himura
* @version 1.0
*/
class DogBaseRenderer
{
	public:
		DogBaseRenderer();
		virtual ~DogBaseRenderer();

		virtual DOGRESULT Init(DOGushort width, DOGushort height, DOGbool windowed, DOGbool enableMsaa) = 0;
		virtual DOGvoid Release() = 0;
		virtual DOGvoid Resize(DOGushort width, DOGushort height) = 0;

		DOGushort GetWidth();
		DOGushort GetHeight();

		DOGbool IsWindowed();
		DOGbool IsEnableMsaa();

		DOGvoid SetWidth(DOGushort width);
		DOGvoid SetHeight(DOGushort height);
		DOGvoid SetWindowed(DOGbool windowed);
		DOGvoid SetEnableMsaa(DOGbool enableMsaa);

	private:
		DOGushort width;
		DOGushort height;
		DOGbool windowed;
		DOGbool enableMsaa;
};

#endif