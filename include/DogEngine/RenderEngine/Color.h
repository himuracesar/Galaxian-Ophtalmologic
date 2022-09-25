#ifndef COLOR_H
#define COLOR_H

#include "DOGCOLOR.h"

/**
* Clase que maneja el vector de color y los componentes por separado
*
* @author Cesar Himura
*/
class Color
{
    public:
        Color(){};
        ~Color(){};
    
        void ResetColor();
        void SetRed(float r){ color.r = r; };
        void SetGreen(float g){ color.g = g; };
        void SetBlue(float b){ color.b = b; };
        void SetAlpha(float a){ color.a = a; };
        void SetColor(const DOGCOLOR& c){ color = c; };
        void SetColor(float r, float g, float b, float a);
    
        float GetRed(){ return color.r; };
        float GetGreen(){ return color.g; };
        float GetBlue(){ return color.b; };
        float GetAlpha(){ return color.a; };
        DOGCOLOR GetColor() { return color; };
    
    private:
        DOGCOLOR color;
};

#endif