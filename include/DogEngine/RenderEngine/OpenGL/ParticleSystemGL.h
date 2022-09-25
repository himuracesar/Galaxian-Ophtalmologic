#ifndef PARTICLE_SYSTEM_GL_H
#define PARTICLE_SYSTEM_GL_H

#include "OpenGLUtils.h"

#include "../Camera2D.h"
#include "../UtilsGraphics.h"
#include "../TransformRH.h"

#include "../../Common/Log.h"

#include "../../Core/DogMath.h"
#include "../../Core/DogSceneGraph.h"
#include "../../Core/DogStdafx.h"

#include "FXGL.h"

class ParticleSystemGL : public TransformRH
{
    public:
        ParticleSystemGL(
                       const string& vertexShaderName,
                       const string& fragmentShaderName,
                       const string& textureName,
                       const DOGVECTOR3& acceleration,
                       //const DOGAABB& box,
                       int maxNumParticles,
                       float timePerParticle);
    
        virtual ~ParticleSystemGL();
    
        // Access Methods
        float GetTime();
        void  SetTime(float t);
        //const DOGAABB& GetAABB()const;
  
        void Release();
		void AddParticle();
		void InitParticles();
		void ReinitDeadParticles();
    
        virtual void InitParticle(DOGPARTICLE& dp) = 0;
        virtual void Update(float elapsedTime);
        virtual void Render();
    
        vector<DOGPARTICLE>& GetParticles(){ return mParticles; };
    
        void SetFxWVP(string fxAttribute){ fxWVP = fxAttribute; }
        void SetFxColor(string fxAttribute){ fxColor = fxAttribute; }
        void SetFxSamplerTexture(string fxAttribute){ fxSamplerTexture = fxAttribute; }
        void SetFxTime(string fxAttribute){ fxTime = fxAttribute; }
        void SetFxAcceleration(string fxAttribute){ fxAcceleration = fxAttribute; }
        void SetFxPositionPort(string fxAttribute){ fxPosition = fxAttribute; }
		void SetFxAngle(string fxAttribute){ fxAngle = fxAttribute; }
		void SetFxLifeTime(string fxAttribute){ fxLifeTime = fxAttribute; }
		void SetFxSize(string fxAttribute){ fxSize = fxAttribute; }
		void SetFxVelocity(string fxAttribute){ fxVelocity = fxAttribute; }
		void SetFxMass(string fxAttribute){ fxMass = fxAttribute; }
		void SetFxInitialTime(string fxAttribute){ fxInitialTime = fxAttribute; }
    
        string GetFxWVP(){ return fxWVP; }
        string GetFxColor(){ return fxColor; }
        string GetFxTexture(){ return fxSamplerTexture; }
        string GetFxTime(){ return fxTime; }
        string GetFxAcceleration(){ return fxAcceleration; }
        string GetFxPosition(){ return fxPosition; }
		string GetFxAngle(){ return fxAngle; }
		string GetFxLifeTime(){ return fxLifeTime; }
		string GetFxSize(){ return fxSize; }
		string GetFxVelocity(){ return fxVelocity; }
		string GetFxMass(){ return fxMass; }
		string GetFxInitialTime(){ return fxInitialTime; }
        
		DOGbool IsDead();
    
    private:
        FXGL* fx;
    
        DOGMATRIX mWVP;
    
        GLuint texture;
		GLuint vao;
    
        unsigned int bufferParticles;
    
        //IDirect3DTexture9* mTex;
        //IDirect3DVertexBuffer9* mVB;
        //D3DXMATRIX mWorld;
        //D3DXMATRIX mInvWorld;
        float mTime;
        DOGVECTOR3 mAcceleration;
        //DOGAABB mBox;
        int mMaxNumParticles;
        float mTimePerParticle;
    
        vector<DOGPARTICLE> mParticles;
        vector<DOGPARTICLE*> mAliveParticles;
        vector<DOGPARTICLE*> mDeadParticles;
    
        DOGPARTICLE *pParticles;
    
        OpenGLUtils *oglUtils;

		Camera2D *camera;
    
        string fxWVP;
        string fxColor;
        string fxSamplerTexture;
        string fxTime;
        string fxAcceleration;
        string fxPosition;
        string fxAngle;
        string fxLifeTime;
        string fxSize;
        string fxVelocity;
        string fxMass;
        string fxInitialTime;
};

#endif