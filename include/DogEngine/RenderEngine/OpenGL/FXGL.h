//
//  FXGL.h
//  Dog Game Engine
//
//  Created by César Himura on 22/11/14.
//  Copyright (c) 2013 César Himura. All rights reserved.
//

#ifndef FXGL_H
#define FXGL_H

#include "../../Common/Log.h"
//#include "../../Common/Utils.h"

#include "../../Core/DogStdafx.h"

#define GL_ATTRIB 0x001
#define GL_UNIFORM 0x002

/**
 * Clase que maneja un shader
 * @author Cesar Himura
 */
class FXGL
{
    public:
        FXGL(const std::string& vertexShaderFilename, const std::string& fragmentShaderFilename);
        FXGL();
        ~FXGL();

        void Release();

        bool CompileAndLink();

        void AddHandler(std::string nameHandler, int type);

        int GetHandlerByName(std::string nameHandler);

        void Bind(){ glUseProgram(shaderProgram); }

    private:
		GLuint LoadShaderFromFile( GLenum shaderType, std::string path );
		GLuint LoadShaderFromFileV2(GLenum shaderType, const std::string &path);

        bool LinkProgram();

        unsigned int fragmentShader;
        unsigned int vertexShader;
        unsigned int shaderProgram;

        std::string fragmentShaderFilename;
        std::string vertexShaderFilename;

        int totalHandlers;

        typedef struct
        {
            std::string name;
            int handle;
        }DOGFXHANDLER;

        DOGFXHANDLER *fxHandler;
        DOGFXHANDLER *fxHandler_aux;

        void AllocateArray();

		std::string ReadFile(const char* file);

		DOGvoid PrintShaderLinkingError(int32_t shaderId);
		DOGvoid PrintShaderCompilationErrorInfo(int32_t shaderId);
};

#endif