#ifndef UTILS_H
#define UTILS_H

#include "../Core/DogMath.h"
#include "../Core/DogStdafx.h"

using namespace std;

class Utils
{
	public:
		static BOOL GetMediaFile(char* file, char path[]);
		static string GetCurrentPathAbsolute();
		static float GetRandomFloat(float a, float b);
		static void GetRandomVector(DOGVECTOR3& out);
		static char* ReadFile(const char* fileName);

	private:
		static BOOL SearchFolders(char* filename, char* exeFolder, char* exeName, char fullPath[]);
};

#endif