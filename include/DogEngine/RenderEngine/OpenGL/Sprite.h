#ifndef SPRITE_H
#define SPRITE_H

#include "OpenGLUtils.h"

#include "../Camera2D.h"
#include "../DOGCOLOR.h"
#include "../TransformRH.h"
#include "../DOGVERTEX.h"

#include "../../Core/DogError.h"
#include "../../Core/DogMath.h"
#include "../../Core/DogSceneGraph.h"

#include "Bounding.h"
#include "FXGL.h"

using namespace std;

/**
 * Clase que maneja los sprites
 *
 * @author Cesar Himura
 * @version 1.0
 */
class Sprite : public TransformRH
{
    public:
        Sprite();
        Sprite(string pathTexture);
        Sprite(int width, int height);
        Sprite(string pathTexture, int width, int height);
        virtual ~Sprite();
    
        virtual void Release();
        virtual void Update(float elapsedTime);
        virtual void Render();
        void CreateBoundingBox(float widthRadio, float heightRadio, float centerX, float centerY);
        void CreateBoundingBox();
        void CreateBoundingCircle(float radio, float centerX, float centerY);
        void CreateBoundingCircle();
        void SetWidth(int width){ this->width = width; };
        void SetHeight(int height){ this->height = height; };
        void SetTexture(GLuint texture){ this->texture = texture; }
        void SetShaderFX(FXGL *fx){ this->fx = fx; };
        void SetCollisionable(bool collisionable){ this->collisionable = collisionable; }
        void SetDead(bool dead){ this->dead = dead; }
        void SetName(string name){ this->name = name; }
        void SetRenderBounding(bool render);
        void SetColorBounding(const DOGCOLOR &color){ colorBounding = color; }
        void SetIdCollisionGroup(unsigned int idCollisionGroup){ this->idCollisionGroup = idCollisionGroup; }
        void SetVx(float vx){ this->vx = vx; }
        void SetVy(float vy){ this->vy = vy; }
        void SetFxPosition(string aPosition){ fxPosition = aPosition; };
        void SetFxTextureCoords(string aTexCoords){ fxTextureCoords = aTexCoords; };
        void SetFxSamplerTexture(string aSampler){ fxSamplerTexture = aSampler; };
        void SetFxWVP(string aWVP){ fxWVP = aWVP; };
		DOGvoid SetId(DOGint id);
		DOGvoid SetColor(DOGCOLOR c);
    
        int GetWidth(){ return width; };
        int GetHeight(){ return height; };
        int GetBoundingType();
        int GetIdCollisionGroup(){ return idCollisionGroup; }
    
        float GetBoundingWidthRadio();
        float GetBoundingHeightRadio();
        float GetBoundingCenterX();
        float GetBoundingCenterY();
        float GetVx(){ return vx; }
        float GetVy(){ return vy; }
    
        GLuint* GetTexture(){ return &texture; };
        GLuint* GetVertexBuffer(){ return &mGeometry; };
        GLuint* GetIndices(){ return &mIndices; };
		GLuint* GetVertexArray() { return &vao; };
    
        FXGL* GetShaderFX(){ return fx; };
    
        DOGMATRIX* GetMatrixWorldViewProjection(){ return &mWVP; };
    
        DOGCOLOR GetColorBounding(){ return colorBounding; }
		DOGCOLOR& GetColor() { return color; }
    
        string GetFxPosition(){ return fxPosition; };
        string GetFxTextureCoords(){ return fxTextureCoords; };
        string GetFxSamplerTexture(){ return fxSamplerTexture; };
        string GetFxWVP(){ return fxWVP; };
        string GetName(){ return name; }
    
        bool IsTouched(float x, float y);
        bool IsCollisionable(){ return collisionable; }
        bool IsDead(){ return dead; }
        bool IsRenderBounding(){ return renderBounding;  }
    
        Bounding* GetBounding(){ return bounding; }

		DOGint GetId();
    
    private:
        GLuint texture;
		GLuint vao;
    
        int width;
        int height;
    
        OpenGLUtils *oglUtils;
    
        unsigned int mGeometry;
        unsigned int mIndices;
        unsigned int idCollisionGroup;
    
        float xBounding; //Coordenada en X donde debe moverse el bounding
        float yBounding; //Coordenada en Y donde debe moverse el bounding
        float dxRelativeBounding; //Distancia relativa en X del bounding con respecto al sprite
        float dyRelativeBounding; //Distancia relativa en Y del bounding con respecto al sprite
        float vx;
        float vy;
    
        FXGL *fx;
    
        DOGMATRIX mWVP;
		DOGMATRIX mScale;
    
        Bounding *bounding;
    
        bool collisionable;
        bool dead;
        bool renderBounding;
    
        string name;
    
        DOGCOLOR colorBounding;
		DOGCOLOR color;

		Camera2D *camera;

		DOGint id;
		DOGint wTex;
		DOGint hTex;
    
        //***** ATRIBUTOS DEL SHADER *****
        string fxPosition;
        string fxTextureCoords;
        string fxSamplerTexture;
        string fxWVP;
		string fxColor;
    
        //***** FUNCIONES ******
        void Init();
    
    protected:
        void CreateShaderFX();
        void LoadTexture(string pathTexture);
};

#endif