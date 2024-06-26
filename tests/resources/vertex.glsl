#version 330 core
layout(location=0) in vec3 iPosition;
layout(location=1) in vec3 iNormal;
layout(location=2) in vec2 iUV;

out vec3 vNormal;
out vec2 vUV;

uniform mat4 uNormalTransform;
uniform mat4 uTransform;
uniform mat4 uModel;

void main() {
  gl_Position = uTransform * uModel * vec4(iPosition, 1.0f);
  vNormal = mat3(uNormalTransform) * iNormal;
  vUV = iUV;
}
