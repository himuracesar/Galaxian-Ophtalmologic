#ifndef BOUNDING_H
#define BOUNDING_H

#include "../Camera2D.h"
#include "../DOGCOLOR.h"
#include "../TransformRH.h"
#include "../DOGVERTEX.h"

#include "../../Core/DogMath.h"
#include "../../Core/DogSceneGraph.h"
#include "../../Core/DogStdafx.h"

#include "FXGL.h"

//Tipos de bounding para colision
#define BOUNDING_BOX    0x00000001
#define BOUNDING_CIRCLE 0x00000002

/**
 * Esta clase se encarga de crear un bounding para las colisiones. 
 * Maneja Bounding Box y Bounding Circle.
 *
 * Se hace una clase aparte para poder gestionar las colisiones de una forma
 * más precisa y con esto solo una parte del sprite puede ser colisionable 
 *
 * @author Cesar Himura
 * @version 1.0
 */
class Bounding : public TransformRH
{
    public:
        Bounding();
        virtual ~Bounding();
    
        virtual void Release();
        void Init();
        void Update(float elapsedTime);
        void Render(const DOGCOLOR &color);
    
        void CreateBoundingBox(float widthRadio, float heightRadio, float centerX, float centerY);
        void CreateBoundingCircle(float radio, float centerX, float centerY);
        void GetCenter(float &cx, float &cy){ cx = GetXPosition(); cy = GetYPosition(); }
        void Reinit();
        void SetRenderable(bool renderable);
        void SetSize(float size){ this->size = size; }
        void SetFxPosition(string fxPosition){ this->fxPosition = fxPosition; };
        void SetFxWVP(string fxWVP){ this->fxWVP = fxWVP; }
        void SetFxSamplerTexture(string fxSamplerTexture){ this->fxSamplerTexture = fxSamplerTexture; }
        void SetFxSize(string fxSize){ this->fxSize = fxSize; }
        void SetFxColor(string fxColor){ this->fxColor = fxColor; }
    
        float GetRadio(){ return radio; }
        float GetHeightRadio(){ return heightRadio; }
        float GetWidthRadio(){ return widthRadio; }
        float GetSize(){ return size; }
    
        int GetBoundingType(){ return boundingType; }
    
        string GetFxPosition(){ return fxPosition; }
        string GetFxWVP(){ return fxWVP; }
        string GetFxSamplerTexture(){ return fxSamplerTexture; }
        string GetFxSize(string fxSize){ return fxSize; }
        string GetFxColor(){ return fxColor; }
    
        bool IsRenderable(){ return renderable; }
    
    private:
        float radio;
        float widthRadio;
        float heightRadio;
        float size;
    
        int boundingType;
    
        GLuint buffer;
        GLuint texture;
		GLuint vao;
    
        vector<DOGVERTEX::Position> vShape;
    
        FXGL *fx;
    
        DOGMATRIX mWVP;
    
        bool renderable;
        bool initialized;

		Camera2D *camera;
    
        string fxWVP;
        string fxSamplerTexture;
        string fxPosition;
        string fxSize;
        string fxColor;
    
        /***** FUNCIONES *****/
        void CreateShape();
};

#endif