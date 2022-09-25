#ifndef COLLISION_GROUP_H
#define COLLISION_GROUP_H

#include "../Core/DogStdafx.h"

#include "../RenderEngine/OpenGL/Sprite.h"

/**
 * Es el grupo donde se van agregando los objetos que son son colisionables
 *
 * @author Cesar Himura
 * @version 1.0
 */
class CollisionGroup
{
    public:
        CollisionGroup(unsigned int idCollisionGroup);
        virtual ~CollisionGroup();
    
        int GetIdCollisionGroup(){ return idCollisionGroup; }
    
        void Release();
        void Add(const Sprite *sp);
        void Delete(const Sprite *sp);
    
        vector<Sprite*>* GetMembers(){ return pVecMembers; }
    
    private:
        int idCollisionGroup;
        vector<Sprite*> *pVecMembers;
    
};

#endif