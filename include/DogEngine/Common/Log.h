#pragma once

#ifndef LOG_H
#define LOG_H

#include "../Core/DogError.h"
#include "../Core/DogStdafx.h"

/**
* Escribe mensajes en archivo Log
*
* @author Cesar Himura
* @version 1.0
*/
class Log
{
	public:
		Log();
		~Log();

		DOGvoid Release();
		DOGvoid SetFileName(string fileName) { this->fileName = fileName; }

		string GetFileName() { return fileName; }

		DOGvoid Info(const DOGchar* format, ...);
		DOGvoid Debug(const DOGchar* format, ...);
		DOGvoid Error(const DOGchar* format, ...);

		static Log* Instance();

	private:
		string fileName;

		FILE* pFile;

		DOGbool OpenFile();

	};

	#define LOGGER Log::Instance()

#endif
