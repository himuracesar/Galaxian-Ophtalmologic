#version 400

precision mediump float;

//varying lowp vec4 vColor;
varying vec4 vColor;

uniform sampler2D sTexture;

void main(void)
{
    vec4 texture = texture2D(sTexture, gl_PointCoord);

    gl_FragColor = texture * vColor;
}
