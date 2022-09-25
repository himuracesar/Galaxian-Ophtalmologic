#pragma once
#ifndef OPENGL_FRAMEWORK_LAYER_H
#define OPENGL_FRAMEWORK_LAYER_H

#include "../Common/Log.h"
#include "../Common/WinTimer.h"
#include "../Input/DogBaseInput.h"
#include "../Input/DirectInput8/DirectInput8.h"
#include "../RenderEngine/OpenGL/OpenGLRenderer.h"

#include "DogBaseFrameworkLayer.h"
#include "DogError.h"
#include "DogGame.h"
#include "DogStdafx.h"

class OpenGLFrameworkLayer : public DogBaseFrameworkLayer
{
	public:
		OpenGLFrameworkLayer(DogGame *pDogGame);
		~OpenGLFrameworkLayer();

		DOGRESULT Init(DOGchar* name, DOGushort width, DOGushort height, DOGbool windowed, DOGint inputType);
		DOGRESULT InitOpenGL();
		DOGvoid Update();
		DOGvoid Render();
		DOGvoid Release();
		DOGvoid Resize(DOGushort width, DOGushort height);
		DOGvoid Input();
		DOGvoid ToogleFullScreen(DOGushort width, DOGushort height);

		DOGvoid Run();

		DOGfloat GetFPS();

	private:
		/*SDL_Window *window;
		SDL_GLContext maincontext;*/

		WinTimer timer;

		DOGfloat fps;

		DOGbool bAlive;

		DOGint videoFlags;

		LPDIRECTINPUT8 pDirectInput8;
		DirectInput8 inpKeyboard;
		DirectInput8 inpMouse;

		DOG_INPUT_MOUSE dim;

		vector<DOGBOOL> vLockKeys;

		/** FUNCTIONS */
		DOGvoid CalculateFramesPerSecond();
	};


#endif