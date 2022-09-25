#ifndef OPENGL_UTILS_H
#define OPENGL_UTILS_H

#include "../../Core/DogError.h"
#include "../../Core/DogMath.h"
#include "../../Core/DogStdafx.h"

#include "../../Common/Log.h"
//#include "Utils.h"

/**
 *
 *
 * @author Cesar Himura
 * @version 1.0
 */
class OpenGLUtils
{
    public:
        OpenGLUtils();
		~OpenGLUtils(){ Release(); }
    
        void Release();
    
        DOGRESULT LoadTexture(GLuint* texture, string path);
        DOGRESULT LoadTexture(GLuint* texture, string fileName, GLuint& width, GLuint& height);

    private:
        //Utils* utils;
};

#endif
