#pragma once
#ifndef OPENGL_RENDERER_H
#define OPENGL_RENDERER_H

#include "../../Core/DogStdafx.h"
#include "../DogBaseRenderer.h"

class OpenGLRenderer : public DogBaseRenderer
{
	public:
		OpenGLRenderer();
		~OpenGLRenderer();

		DOGvoid Release();

		DOGRESULT Init(DOGushort width, DOGushort height, DOGbool windowed, DOGbool enableMsaa);
		DOGRESULT Init(DOGchar* name, DOGbool windowed, DOGushort width, DOGushort height);

		DOGvoid Resize(DOGushort width, DOGushort height);

		SDL_Window* GetWindow();
		SDL_GLContext GetContext();

		DOGvoid  SwapGLBuffers();

		static OpenGLRenderer* Instance();

	private:
		SDL_Window *window;
		SDL_GLContext maincontext;

		DOGint videoFlags;
};

#define OPENGLRENDERER OpenGLRenderer::Instance()

#endif