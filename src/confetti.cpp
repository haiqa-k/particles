// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "confetti.h"

using namespace std;
using namespace agl;
using namespace glm;

void Confetti::createParticles(int size) 
{
  mTexture = theRenderer.loadTexture("../textures/particle.png");
  for (int i = 0; i < size; i++)
  {
    Particle part = {random_unit_cube(), random_unit_vector()*0.5f, vec4(random_unit_vector(), random_float()), 0.25f, 1.0f};
    mParticles.push_back(part);
  }
}

void Confetti::update(float dt)
{
  for(int i = 0; i < mParticles.size(); i++) {
    Particle part = mParticles[i];
    vec3 pos = part.pos;
    vec3 vel = part.vel;
    pos += (dt * vel);
    if(pos.x > 1.0f) {
      pos.x = 1.0f;
      vel.x*=-1;
    }
    else if(pos.x < -1.0f) {
      pos.x = -1.0f;
      vel.x*=-1;
    }
    else if(pos.y > 1.0f) {
      pos.y = 1.0f;
      vel.y*=-1;
    }
    else if(pos.y < -1.0f) {
      pos.y = -1.0f;
      vel.y*=-1;
    }
    else if(pos.z > 1.0f) {
      pos.z = 1.0f;
      vel.z*=-1;
    }
    else if(pos.z < -1.0f) {
      pos.z = -1.0f;
      vel.y*=-1;
    }
    part.pos = pos;
    part.vel = vel;
    mParticles[i] = part;
  }
  std::sort(mParticles.begin(), mParticles.end(), [](const Particle& lhs, const Particle& rhs) {
    return lhs.pos.z < rhs.pos.z;
  });
}

