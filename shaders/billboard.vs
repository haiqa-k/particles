#version 400

layout (location = 0) in vec3 vPos;

uniform vec3 uCameraPos;
uniform float uSize;
uniform vec3 uOffset;
uniform vec4 uColor;
uniform mat4 uVP;

out vec4 color;
out vec2 uv;

void main()
{
   color = uColor;
   uv = vPos.xy;

   vec3 shift = vec3(-0.5, -0.5, 0.0);
   vec3 myPos = vPos + shift;
   myPos.x *= uSize;
   myPos.y *= uSize;
   myPos.z *= uSize;
   vec3 up = vec3(0.0, 1.0, 0.0);
   vec3 r_z = normalize(uCameraPos - myPos);
   vec3 r_x = normalize(cross(up, r_z));
   vec3 r_y = normalize(cross(r_z, r_x));
   mat3 rotation = mat3(r_x, r_y, r_z);
   
   gl_Position = uVP * vec4(((rotation * myPos) + uOffset), 1.0);

}