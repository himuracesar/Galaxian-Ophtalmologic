#pragma once
#ifndef DOG_ERROR_H
#define DOG_ERROR_H

#include "../Common/Log.h"

typedef int DOGRESULT;

#define DOGNULL 0
#define DOGFAILED(dr)(((DOGRESULT)(dr))>0)
#define DOGSUCCEED(dr)(((DOGRESULT)(dr))==0)

#define DOG_OK 0x00000000
#define DOG_ERROR_INIT_SDL2 0x00000001
#define DOG_ERROR_WINDOW_SDL2 0x00000002
#define DOG_ERROR_DEVICE_D3D11 0x00000003
#define DOG_ERROR_D3D_FEATURE_LEVEL 0x00000004
#define DOG_ERROR_LOAD_COMPILED_SHADER 0x00000005
#define DOG_ERROR_BINARY_FILE 0x00000006
#define DOG_ERROR_OBJECT_NULL 0x00000007
#define DOG_ERROR_CREATE_VERTEX_SHADER 0x00000008
#define DOG_ERROR_CREATE_PIXEL_SHADER 0x00000009
#define DOG_ERROR_TYPE_BUFFER_NO_EXIST 0x0000000A
#define DOG_ERROR_DIRECT_INPUT_8_INVALID_INTERFACE 0x0000000C
#define DOG_ERROR_DIRECT_INPUT_8_CREATE_KEYBOARD 0x0000000D
#define DOG_ERROR_DIRECT_INPUT_8_CREATE_MOUSE 0x0000000E
#define DOG_ERROR_UNKNOWN 0x0000000F
#define DOG_ERROR_DIRECT_INPUT_8_SET_DATA_FORMAT 0x00000010
#define DOG_ERROR_DIRECT_INPUT_8_SET_INPUT_COOPERATIVE_LEVEL 0x00000011
#define DOG_ERROR_DIRECT_INPUT_8_CREATE_INPUT 0x00000012
#define DOG_ERROR_OPENGL_CONTEXT 0x00000013
#define DOG_ERROR_GLEW_INIT 0x00000014

typedef struct {
	int value;
	const char* name;
}CODES;

static const CODES error_codes[] = {
	{ DOG_OK, "Successful" },
	{ DOG_ERROR_INIT_SDL2, "It couldn't initialize SDL2" },
	{ DOG_ERROR_WINDOW_SDL2, "It couldn't create the window with SDL2" },
	{ DOG_ERROR_DEVICE_D3D11, "It couldn't create the Direct3D11's device" },
	{ DOG_ERROR_D3D_FEATURE_LEVEL, "The hardware doesn't support the d3d feature level" },
	{ DOG_ERROR_LOAD_COMPILED_SHADER, "It couldn't load the compiled shader" },
	{ DOG_ERROR_BINARY_FILE, "There is an error in the binary file" },
	{ DOG_ERROR_OBJECT_NULL, "The object is null" },
	{ DOG_ERROR_CREATE_VERTEX_SHADER , "It couldn't create the vertex shader" },
	{ DOG_ERROR_CREATE_PIXEL_SHADER , "It couldn't create the pixel shader" },
	{ DOG_ERROR_TYPE_BUFFER_NO_EXIST , "The buffer's type that it wants to create does not exist" },
	{ DOG_ERROR_DIRECT_INPUT_8_INVALID_INTERFACE , "There is not a valid parent DIRECTINPUT8 interface" },
	{ DOG_ERROR_DIRECT_INPUT_8_CREATE_KEYBOARD , "Direct Input 8 is unable to create the keyboard device" },
	{ DOG_ERROR_DIRECT_INPUT_8_CREATE_MOUSE , "Direct Input 8 is unable to create the mouse device" },
	{ DOG_ERROR_UNKNOWN , "Error Unknown" },
	{ DOG_ERROR_DIRECT_INPUT_8_SET_DATA_FORMAT , "Direct Input 8 is unable to set input data format" },
	{ DOG_ERROR_DIRECT_INPUT_8_SET_INPUT_COOPERATIVE_LEVEL , "Direct Input 8 is unable to set input cooperative level" },
	{ DOG_ERROR_DIRECT_INPUT_8_SET_DATA_FORMAT , "Direct Input 8 is unable to set input cooperative level" },
	{ DOG_ERROR_DIRECT_INPUT_8_CREATE_INPUT , "Direct Input 8 is unable to create the input" },
	{ DOG_ERROR_OPENGL_CONTEXT , "It couldn't create the OpenGL Context" },
	{ DOG_ERROR_GLEW_INIT , "It couldn't initialize Glew" }
};

	//Manejo de errores del Dog Game Engine
	#if defined(DEBUG) | defined(_DEBUG)
		#ifndef DR
			#define DR(x)																						\
				{																								\
					DOGRESULT dr = (x);																			\
					if(DOGFAILED(dr))																			\
					{																							\
						LPWSTR output = L"";																	\
						for (int i = 0; error_codes[i].name; ++i){												\
							if (error_codes[i].value == dr){													\
								int nSize = MultiByteToWideChar(CP_ACP, 0,  error_codes[i].name, -1, NULL, 0);	\
																												\
								output = new WCHAR[nSize];														\
																												\
								MultiByteToWideChar(CP_ACP, 0, error_codes[i].name, -1, output, nSize);			\
								break;																			\
							}																					\
						}																						\
						MessageBox(NULL, output, L"Error Dog Engine", MB_OK);									\
						delete[] output;																		\
					}																							\
				}
		#endif
	#else
		#ifndef DR
			#define DR(x) (x)
		#endif
	#endif 

#endif 
