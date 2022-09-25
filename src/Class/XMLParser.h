#pragma once
#ifndef XML_PARSER_H
#define XML_PARSER_H

#include "DogEngine/Common/Log.h"

#include "DogEngine/Core/DogStdafx.h"

#include <libxml/xpath.h>

class XMLParser
{
	public:
		XMLParser();
		~XMLParser();

		DOGvoid Release();

		DOGvoid Init(string file);
		DOGint GetDatai(string node);
		DOGfloat GetDataf(string node);
		DOGchar* GetDatac(string node);

	private:
		xmlDoc* pDoc;
		xmlXPathContext *xpathCtx;

		char* trimwhitespace(char *str);
};

#endif