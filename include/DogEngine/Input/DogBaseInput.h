#pragma once
#ifndef DOG_BASE_INPUT_H
#define DOG_BASE_INPUT_H

#include "../Core/DogError.h"
#include "../Core/DogStdafx.h"

/**
* Clase base para crear algún método de Input. Los métodos quedaron como abstractos para que 
* sean implementados por la clase hija debido a que los botones del mouse y/o teclas del teclado
* queden dentro del stack, la stack es más rápido que la heap.
*
* En esta clase base por le momento solo se contemplan dispositos como el teclado y mouse.
*
* De esta forma la respuesta del control será casi inmediata ó inmediata.
*
* @author Cesar Himura
* @version 1.0
*/
class DogBaseInput
{
	public:
		DogBaseInput();
		~DogBaseInput();

		virtual DOGRESULT Init() = 0;
		virtual DOGvoid Release() = 0;

		virtual DOGlong GetX() = 0;
		virtual DOGlong GetY() = 0;
		virtual DOGlong GetDeltaX() = 0;
		virtual DOGlong GetDeltaY() = 0;
		virtual DOGlong GetDeltaZ() = 0;

		virtual DOGBOOL* GetButtons() = 0;
		virtual DOGBOOL* GetKeys() = 0;
};

#endif
