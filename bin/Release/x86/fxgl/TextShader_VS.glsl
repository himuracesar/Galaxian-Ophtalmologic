#version 400

attribute vec4 a_position;
attribute vec4 a_color;
attribute vec2 a_texCoord;

uniform mat4 mWVPMatrix;

varying vec4 v_color;
varying vec2 v_texCoord;

void main(void) {
    gl_Position = mWVPMatrix * a_position;
    v_texCoord = a_texCoord;
    v_color = a_color;
}