#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H

#include "../../Common/Log.h"

#include "../../Core/DogMath.h"

#include "../Camera2D.h"

#include "Sprite.h"

class AnimatedSprite : public Sprite
{
	public:
        AnimatedSprite(string file, int rows, int cols, bool animated = false);
        virtual ~AnimatedSprite();
    
        static const int LOOP_INFINITE = 0;
    
        virtual void Release();
        virtual void Update(float elapsedTime);
        virtual void Render();
    
        void SetFrameStart(int frame);
        void SetFrameEnd(int frame);
        void SetFrameStartToEnd(int start, int end);
    
        /**
         * Asigna cuantos loop correrá la animación
         * @param loop Número de ciclos que durará el loop de animación
         */
        void SetTotalLoopAnimation(int loop){ totalLoopAnimation = loop; };
    
        /**
         * Pone en activo un frame que será el que mostrará en pantalla.
         * El frame activo es el que se renderea actualmente
         * @param frame Frame que será activo
         */
        void SetFrameActive(int frame){ frameActive = frame; };
    
        /**
         * Indica si la animación esta detenida o esta corriendo
         * @param animate True si la animcación esta en proceso o false si esta detenida
         */
        void SetAnimate(bool animate){ this->animate = animate; };
    
        /** 
         * Asigna el tiempo en segundos en el que transcurrira la animación
         * @param time Tiempo en segundos para controlar la animación
         */
        void SetTimeAnimation(float time){ timeAnimation = time; };
        void FindFrameInSpriteSheet(int currentFrame);
    
        int GetFrameWidth(){ return frameWidth; };
        int GetFrameHeight(){ return frameHeight; };
        int GetFrameActive(){ return frameActive; };
        int GetTotalLoopAnimation(){ return totalLoopAnimation; };
    
        bool IsAnimate(){ return animate; };
    
    private:
        int frameHeight;
        int frameWidth;
        int frameActive;
        int frameStart;
        int frameEnd;
        int totalFrames;
        int cols;
        int rows;
        int colFrame;
        int rowFrame;
        int totalLoopAnimation;
        int currentLoopAnimation;
    
        float timeAnimation;
        float elapsedTimeAnimation;
    
        bool animate;

		Camera2D *camera;

		DOGMATRIX mScale;
    
        //***** FUNCIONES *****
        void CreateVertexBuffer();
};

#endif