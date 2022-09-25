#ifndef DOG_SCENE_GRAPH_H
#define DOG_SCENE_GRAPH_H

#include "DogMath.h"
#include "DogNode.h"
#include "DogError.h"
#include "DogStdafx.h"

#include "../RenderEngine/DogBaseCamera.h"

class DogSceneGraph
{
	public:
		DogSceneGraph();
		~DogSceneGraph();

		void Release();
		void AddNode(DogNode *node);
		void Process();

		static DogSceneGraph* Instance();

		/*void SetActiveCamera(Camera *camera){ cameraActive = camera; };
		Camera* GetActiveCamera(){ return cameraActive; };*/

		void SetActiveCamera(DogBaseCamera* camera){ cameraActive = camera; }
		DogBaseCamera* GetActiveCamera(){ return cameraActive; }

		//void SetOrthographicProjection(DOGMATRIX *pMatrix){ pOrthographicProjection = pMatrix; };
        //DOGMATRIX* GetOrthographicProjection(){ return pOrthographicProjection; };

	private:
		DogNode *root;
		//Camera *cameraActive;
		DogBaseCamera *cameraActive;
		//DOGMATRIX *pOrthographicProjection;
};

#define DOGSCENE DogSceneGraph::Instance()

#endif