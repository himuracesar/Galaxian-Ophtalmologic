#version 400

precision mediump float;

varying vec2 v_texCoord;
uniform sampler2D s_texture;
//uniform vec4 color;

varying vec4 v_color;

void main(void) {
    //gl_FragColor =  texture2D(s_texture, v_texCoord); //* vec4(0.0, 1.0, 0.0, 1.0);
    //gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    gl_FragColor = vec4(v_color.r, v_color.g, v_color.b, texture2D(s_texture, v_texCoord).a * v_color.a);// * vec4(0.0, 1.0, 0.0, 1.0);
}