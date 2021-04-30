// Bryn Mawr College, alinen, 2020
//

#include "AGL.h"
#include "AGLM.h"
#include <cmath>
#include "myparticlesystem.h"

using namespace std;
using namespace agl;
using namespace glm;

float n = rand() / (RAND_MAX + 1.);

void MyParticleSystem::createParticles(int size)
{
   mTexture = theRenderer.loadTexture("../textures/ParticleFirecloud.png");
   for (int i = 0; i < size; i++) {
      Particle particle = {start_position, random_unit_vector(),start_color, 0.05,n};
      mParticles.push_back(particle);
   }
}

void MyParticleSystem::update(float dt)
{
}