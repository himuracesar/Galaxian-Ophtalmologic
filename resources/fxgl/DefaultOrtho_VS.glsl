#version 400

attribute vec4 a_position;
attribute vec2 a_texCoord;
varying vec2 v_texCoord;

uniform mat4 mWVPMatrix;

void main()
{
    gl_Position = mWVPMatrix * a_position;
    v_texCoord = a_texCoord;
}