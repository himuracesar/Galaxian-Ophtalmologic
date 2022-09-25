#pragma once
#ifndef DIRECT_INPUT_8_H
#define DIRECT_INPUT_8_H

#include "../../Common/Log.h"

#include "../../Core/DogError.h"
#include "../../Core/DogStdafx.h"

#include "../DogBaseInput.h"

// Device types
enum DIRECTINPUT8TYPE
{
	DIT_KEYBOARD,
	DIT_MOUSE,
	DIT_FORCE_DWORD = 0x7fffffff
};

/**
* Se encarga de habilitar y leer los eventos generados por el teclado y mouse
*
* @author Cesar Himura
* @version 1.0
*/
class DirectInput8 : public DogBaseInput
{
	public:
		DirectInput8();
		~DirectInput8();

		DOGRESULT Init();
		DOGRESULT Init(LPDIRECTINPUT8 pDI, HWND hWnd, DIRECTINPUT8TYPE type);
		DOGvoid Release();
		DOGvoid Read();
		DOGvoid LockKey(DWORD key);

		DOGlong GetX();
		DOGlong GetY();
		DOGlong GetDeltaX();
		DOGlong GetDeltaY();
		DOGlong GetDeltaZ();
		DOGBOOL* GetButtons();
		DOGBOOL* GetKeys();

	private:
		LPDIRECTINPUTDEVICE8  m_pDevice;
		HWND                  m_hWnd;
		DIRECTINPUT8TYPE      m_type;
		DOGchar               m_keyboardState[256];
		DOGBOOL               m_pressedKeys[256];
		DIMOUSESTATE          m_mouseState;
		DOGBOOL               m_pressedButtons[4];
		DOGBOOL               m_keyLock[256];
		DOGlong               m_x, m_y;
};

#endif