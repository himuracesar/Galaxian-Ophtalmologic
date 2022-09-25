#version 400

attribute vec4 aPosition;
attribute vec4 aVelocity;
attribute float aSize;
attribute float aInitialTime;
attribute vec4 aColor;
attribute float aLifeTime;

uniform mat4 uWVP;
uniform vec4 uAcceleration;
uniform float uTime;

varying vec4 vColor;

void main(void)
{
	//uTime Representa la "edad" del Sistema de Particulas
    float t = uTime - aInitialTime;

    vec4 pos = aPosition + aVelocity * t + 0.5 * uAcceleration * t * t;

    gl_Position = uWVP * pos;
    gl_PointSize = aSize;

    vec4 color = aColor;

    if(t == aLifeTime)
    	color.a = 1.0;
    else
    	color.a = 1.0/aLifeTime;

    vColor = color;
}