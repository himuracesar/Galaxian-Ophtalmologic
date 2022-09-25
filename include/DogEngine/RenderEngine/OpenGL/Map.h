#ifndef MAP_H
#define MAP_H

#include "OpenGLUtils.h"

#include "../Camera2D.h"
#include "../UtilsGraphics.h"
#include "../TransformRH.h"
#include "../DOGVERTEX.h"

#include "../../Common/cJSON.h"
#include "../../Common/Log.h"
#include "../../Common/Utils.h"

#include "../../Core/DogError.h"
#include "../../Core/DogMath.h"
#include "../../Core/DogSceneGraph.h"
#include "../../Core/DogStdafx.h"

#include "FXGL.h"

#define NO_COLLISION 0x000
#define HORIZONTAL_COLLISION 0x001
#define VERTICAL_COLLISION 0x002

/**
* Carga mapas desde un archivo en formato JSON. El mapa solo funciona con el sistema un sistema
* de coordenadas donde el origen es la equina superior izquierda y el eje Y esta invertido. 
* Es decir, el lado positivo del eje Y va hacia abajo y el negativo hacia arriba.
*
* @author Cesar Himura
*/
class Map : public TransformRH
{
    public:
		Map(string mapFile);
        virtual ~Map();
    
        virtual void Release();
        virtual void Init();
        virtual void Update(float elapsedTime);
        virtual void Render();
    
        short GetTileWidth(){ return tileWidth; };
        short GetTileHeight(){ return tileHeight; };
        short GetRows(){ return rows; };
        short GetColumns(){ return cols; };
        short GetTotalTiles(){ return rows * cols; };

		int GetHeight(){ return rows * tileHeight; }
		int GetWidth(){ return cols * tileWidth; }
		int GetCollide(const Sprite* sprite);
		COLLISION_2D_MAP GetCollisionMapVsSprite(const Sprite* sprite);
    
        string GetFxPosition(){ return fxPosition; };
        string GetFxTextureCoords(){ return fxTextureCoords; };
        string GetFxSamplerTexture(){ return fxSamplerTexture; };
        string GetFxWVP(){ return fxWVP; };
    
        FXGL* GetShaderFX(){ return fx; };

		DOGVECTOR3 GetCoordMap(float x, float y);
		float GetXMap(float x);
		float GetYMap(float y);
    
    private:
        short rows;
        short cols;
        short tileSetWidth;
        short tileSetHeight;
        short tileHeight;
        short tileWidth;
        short rowTile;
        short colTile;
    
        FXGL *fx;
    
        DOGMATRIX mWVP;
		DOGMATRIX mScale;
    
        OpenGLUtils *oglUtils;

		Camera2D *camera;

		typedef struct LAYER
		{
			vector<DOGTILE*> vMap;
			string type;
			int height;
			int width;
			vector<GLuint> verticesBuffer;
			vector<GLuint> indicesBuffer;
		}LAYER;

		typedef struct MAP_COLLISION
		{
			int x;
			int y;
			int width;
			int height;
			Bounding bounding;
			string type; // polyline | circle | box:: Se debe indicar desde el Tile Map Editor
			vector<DOGPOINT*> polyline;
		}MAP_COLLISION;

		vector<LAYER*> vLayers;
		vector<DOGTILESET*> vTilesets;
		vector<MAP_COLLISION*> vMapCollision;
		vector<DOGPOINT*> vClosestPoints;

		bool frustum(const DOGTILE* dt);

		GLuint vao;
    
        //***** ATRIBUTOS DEL SHADER *****
        string fxPosition;
        string fxTextureCoords;
        string fxSamplerTexture;
        string fxWVP;
    
        //***** FUNCIONES *****
        int FindTileInTileSet(int idTile);
        void CreateShaderFX();
		char* ReadFile(const char *file);
};

#endif