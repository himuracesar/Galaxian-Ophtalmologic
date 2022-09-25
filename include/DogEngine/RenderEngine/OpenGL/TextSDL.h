#ifndef TEXT_SDL_H
#define TEXT_SDL_H

#include "SDL2/SDL_ttf.h"

#include "../../Core/DogMath.h"
#include "../../Core/DogSceneGraph.h"

#include "../Camera2D.h"
#include "../Color.h"
#include "../TransformRH.h"
#include "../DOGVERTEX.h"
#include "FXGL.h"

class TextSDL : public TransformRH, Color
{
	public:
        TextSDL(string fontFile);
        TextSDL(string fontFile, int size);
        ~TextSDL();
    
        virtual void Init();
        virtual void Update(float elpsedTime);
        virtual void Render(string text, float x, float y);
        virtual void Render(string text, float x, float y, const DOGCOLOR& color);
        virtual void Render(string text, float x, float y, int size);
        virtual void Render(string text, float x, float y, int size, const DOGCOLOR& color);
        virtual void Release();
    
        void SetShaderFX(FXGL *fx){ this->fx = fx; };
        void SetSize(int size){ this->size = size; };
		void SetFlipU(bool flip){ flipU = flip; }
		void SetFlipV(bool flip){ flipV = flip; }
    
        FXGL* GetShaderFX(){ return fx; };
    
        int GetSize() { return size; };
    
        string GetFxPosition(){ return fxPosition; };
        string GetFxColor(){ return fxColor; };
        string GetFxTextureCoords(){ return fxTextureCoords; };
        string GetFxSamplerTexture(){ return fxSamplerTexture; };
        string GetFxWVP(){ return fxWVP; };

		DOGint GetWidth() { return width; }
		DOGint GetHeight() { return height; }
    
    private:
        /*FT_Library ft;
        FT_Face face;
        FT_Error error;*/

		string fontFile;
		string text;

		TTF_Font *face;
    
        FXGL *fx;
    
        DOGMATRIX mWVP;
		//DOGMATRIX mScale;
    
        //Utils *utils;
    
        unsigned int mVertices;
        unsigned int mIndices;
    
        //const int TEXTURES_TEXT = 128;
    
        GLuint tex;
		GLuint vao;
    
        int size;
		int _size;
		DOGint width;
		DOGint height;
		DOGint x_error;

		Camera2D *camera;

		bool flipU;
		bool flipV;
    
        //***** ATRIBUTOS DEL SHADER *****
        string fxPosition;
        string fxColor;
        string fxTextureCoords;
        string fxSamplerTexture;
        string fxWVP;
    
        //***** FUNCIONES PRIVADAS *****
        void RenderText(string text, float x, float y);
        void Render(string text);
        void ConstructorDefault(string fontFile);
};

#endif