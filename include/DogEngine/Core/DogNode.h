#ifndef DOG_NODE_H
#define DOG_NODE_H

#include "DogError.h"
#include "DogStdafx.h"

class DogNode
{
	public:
		DogNode();
		~DogNode();

		void AddChild(DogNode *node);
		void AddSibling(DogNode *node);
		virtual void Process();

	protected:
		DogNode *next;
		DogNode *prev;
		DogNode *child;
};

#endif