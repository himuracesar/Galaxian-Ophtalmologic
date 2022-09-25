#ifndef GFX_STATS_GL_H
#define GFX_STATS_GL_H

#include "../TextSDL.h"
#include "../../../Core/DogStdafx.h"

/**
 * Clase que cálcula algunas estadísticas de la escena que se renderea
 * es solo para desarrollo. Esta clase muestra los FPS a los que esta rendereando
 * la aplicación
 *
 * @author César Himura
 */
class GfxStatsGL
{
    public:
        GfxStatsGL();
        ~GfxStatsGL();
    
        void AddVertices(int n);
        void SubVertices(int n);
        void AddTriangles(int n);
        void SubTriangles(int n);
    
        void SetTriCount(int n);
        void SetVertexCount(int n);
    
        void Release();
        void Update(float elapsedTime);
        void Render(float x, float y);
    
        //DOGRESULT SaveScreenshot(char* fileName);
    
        void AddDataExtra(string str){ dataExtra = str; }
		void SetFlipU(bool flip){ flipU = flip; }
		void SetFlipV(bool flip){ flipV = flip; }
    
    private:
        // Prevent copying
        GfxStatsGL(const GfxStatsGL& rhs);
        GfxStatsGL& operator=(const GfxStatsGL& rhs);
        //ID3DXFont* mFont;
    
        float mFPS;
        float mMilliSecPerFrame;
    
        int mNumTris;
        int mNumVertices;
    
        //int numberScreenshot;
    
        string dataExtra;
    
        TextSDL *text;

		bool flipU;
		bool flipV;
};
#endif // GFX_STATS_GL_H