#include "particlesystem.h"
#include "AGLM.h"

using namespace glm;
using namespace std;
using namespace agl;

Renderer ParticleSystem::theRenderer;

Renderer& ParticleSystem::GetRenderer()
{
   return theRenderer;
}

ParticleSystem::ParticleSystem()
{
   mBlendMode = ADD;
   mTexture = -1;
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::init(int size)
{
   if (!theRenderer.initialized())
   {
      theRenderer.init("../shaders/billboard.vs", "../shaders/billboard.fs");
   }
   createParticles(size);
}
void  ParticleSystem::startPos(vec3 pos) {
    start_position = pos;
}

void  ParticleSystem::startCol(vec4 col) {
    start_color = col;
}

void ParticleSystem::draw() 
{
   theRenderer.begin(mTexture, mBlendMode);
   for (int i = 0; i < mParticles.size(); i++)
   {
      Particle particle = mParticles[i];
      theRenderer.quad(particle.pos, particle.color, particle.size);
   }
}

