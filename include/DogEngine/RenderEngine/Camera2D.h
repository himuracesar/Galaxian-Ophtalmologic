#ifndef CAMERA_2D_GL_H
#define CAMERA_2D_GL_H

#include "../Core/DogMath.h"

#include "DogBaseCamera.h"

class Camera2D : public DogBaseCamera
{
	public:
		Camera2D(int width, int height, float zNear, float zFar);
		Camera2D(float left, float right, float bottom, float top, float zNear, float zFar);
		~Camera2D();

		void Release();
		void CreateProjection(int width, int height, float zNear, float zFar);
		void CreateProjection(float left, float right, float bottom, float top, float zNear, float zFar);
		void SetInvertY(bool invertY){ this->invertY = invertY; }

		DOGMATRIX* GetProjection(){ return &mProjection; }

		bool IsInvertY(){ return invertY; }

		int GetLeft(){ return left; }
		int GetRight(){ return right; }
		int GetTop(){ return top; }
		int GetBottom(){ return bottom; }
		int GetHeight(){ return height; }
		int GetWidth(){ return width; }

	private:
		bool invertY;

		int left;
		int right;
		int top;
		int bottom;

		int width;
		int height;

		DOGMATRIX mProjection;
};

#endif