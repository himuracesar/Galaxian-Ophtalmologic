#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "CollisionGroup.h"

#include "../Core/DogStdafx.h"

#include "../RenderEngine/UtilsGraphics.h"


/**
 * Se encarga de manejar las colisiones entre los diferentes objetos. Cada uno de estos
 * objetos forma parte de algún grupo de colisión. Las colisiones se checan entre los
 * Sprites que forman parte de los grupos de colisión
 *
 * @author Cesar Himura
 * @version 1.0
 */
class CollisionManager
{
    public:
        CollisionManager();
        virtual ~CollisionManager();
    
        virtual void Release();
        virtual void CheckCollisions();
    
        void CreateCollisionGroup(unsigned int idCollisionGroup);
        void AddCollisionRelation(unsigned int idCollisionRelation, unsigned int idCollisionGroup1, unsigned int idCollisionGroup2);
    
        bool CheckBoxVsBox(const Sprite& sp1, const Sprite& sp2);
        bool CheckCircleVsCircle(const Sprite& sp1, const Sprite& sp2);
        bool CheckBoxVsCircle(const Sprite& sp1, const Sprite& sp2);
    
        CollisionGroup* GetCollisionGroup(unsigned int idCollisionGroup);
    
        vector<COLLISION>* GetCollisions(){ return pVecCollisions; }
    
    private:
        typedef struct CollisionRelation
        {
            unsigned int idGroup1;
            unsigned int idGroup2;
            unsigned int idCollisionRelation;
        }CollisionRelation;
    
        vector<CollisionRelation> *pVecCollisionRelation;
        vector<CollisionGroup*> *pVecCollisionGroups;
        vector<COLLISION> *pVecCollisions;
    
        /***** FUNCIONES PRIVADAS *****/
        void AddCollision(int idTypeCollision, const Sprite& sp1, const Sprite& sp2);
        bool ExistCollision(const Sprite& sp1, const Sprite& sp2);
};

#endif