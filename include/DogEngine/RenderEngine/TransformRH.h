#ifndef TRANSFORM_RH_H
#define TRANSFORM_RH_H

#include "../Core/DogMath.h"
#include "../Core/DogStdafx.h"

class TransformRH
{
    public:
        TransformRH();
        ~TransformRH() { Reset(); }
    
        void Reset();
        void TranslateAbs( float x, float y, float z );
        void TranslateRel( float x, float y, float z );
        void RotateAbs( float x, float y, float z );
        void RotateRel( float x, float y, float z );
        void ScaleAbs( float x, float y, float z );
        void ScaleRel( float x, float y, float z );
    
        DOGMATRIX* GetTransform();
        float GetXPosition() { return m_translate._14; }
        float GetYPosition() { return m_translate._24; }
        float GetZPosition() { return m_translate._34; }
        float GetXRotation() { return m_rotationX; }
        float GetYRotation() { return m_rotationY; }
        float GetZRotation() { return m_rotationZ; }
        float GetXScale()    { return m_scale._11; }
        float GetYScale()    { return m_scale._22; }
        float GetZScale()    { return m_scale._33; }
        void SetXPosition( float x ) { m_translate._14 = x; }
        void SetYPosition( float y ) { m_translate._24 = y; }
        void SetZPosition( float z ) { m_translate._34 = z; }
        void SetXRotation( float x ) { RotateAbs( x, m_rotationY, m_rotationZ ); }
        void SetYRotation( float y ) { RotateAbs( m_rotationX, y, m_rotationZ ); }
        void SetZRotation( float z ) { RotateAbs( m_rotationX, m_rotationY, z ); }
        void SetXScale( float x )    { m_scale._11 = x; }
        void SetYScale( float y )    { m_scale._22 = y; }
        void SetZScale( float z )    { m_scale._33 = z; }
    
    protected:
        DOGMATRIX m_translate;
        DOGMATRIX m_rotate;
        DOGMATRIX m_scale;
        DOGMATRIX m_transform;
        float m_rotationX, m_rotationY, m_rotationZ;
};

#endif
