#include "XMLParser.h"

XMLParser::XMLParser()
{

}

XMLParser::~XMLParser()
{
	/*DOG_SAFE_DELETE(pDoc);
	DOG_SAFE_DELETE(xpathCtx);*/
}

DOGvoid XMLParser::Init(string file)
{
	xmlInitParser();
	LIBXML_TEST_VERSION

	xmlKeepBlanksDefault(0);

	xmlDoc *pDoc = xmlParseFile(file.c_str());

	if (pDoc == NULL)
		LOGGER->Error("failed to read the .xml file");

	xpathCtx = xmlXPathNewContext(pDoc);

	if (xpathCtx == NULL)
		LOGGER->Error("failed to create the xpath context");
}

DOGint XMLParser::GetDatai(string node)
{
	xmlXPathObject* pXpathObj = xmlXPathEvalExpression((xmlChar*)node.c_str(), xpathCtx);
	return atoi((char*)(pXpathObj->nodesetval->nodeTab[0]->children->content));
}

DOGfloat XMLParser::GetDataf(string node)
{
	xmlXPathObject* pXpathObj = xmlXPathEvalExpression((xmlChar*)node.c_str(), xpathCtx);
	return atof((char*)(pXpathObj->nodesetval->nodeTab[0]->children->content));
}

DOGchar* XMLParser::GetDatac(string node)
{
	xmlXPathObject* pXpathObj = xmlXPathEvalExpression((xmlChar*)node.c_str(), xpathCtx);
	//return (char*)(pXpathObj->nodesetval->nodeTab[0]->children->content);
	return trimwhitespace((char*)(pXpathObj->nodesetval->nodeTab[0]->children->content));
}

// Note: This function returns a pointer to a substring of the original string.
// If the given string was allocated dynamically, the caller must not overwrite
// that pointer with the returned value, since the original pointer must be
// deallocated using the same allocator with which it was allocated.  The return
// value must NOT be deallocated using free() etc.
char* XMLParser::trimwhitespace(char *str)
{
	char *end;

	// Trim leading space
	while (isspace(*str)) str++;

	if (*str == 0)  // All spaces?
		return str;

	// Trim trailing space
	end = str + strlen(str) - 1;
	while (end > str && isspace(*end)) end--;

	// Write new null terminator
	*(end + 1) = 0;

	return str;
}