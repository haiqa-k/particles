#ifndef ParticleSystem_H_
#define ParticleSystem_H_

#include "AGL.h"
#include "image.h"
#include "renderer.h"
#include <vector>

namespace agl {

   struct Particle {
      glm::vec3 pos;
      glm::vec3 vel;
      glm::vec4 color;
      float size;
      float mass;
   };

   class ParticleSystem {
   public:
      ParticleSystem();
      virtual ~ParticleSystem();

      void init(int size);
      virtual void update(float dt) = 0;
      virtual void draw();

      static Renderer& GetRenderer();
      void startPos(glm::vec3 pos);
      void startCol(glm::vec4 col);
      glm::vec3 startPos();
      glm::vec4 startCol();
      
   protected:
      virtual void createParticles(int size) = 0;

   protected:

      std::vector<Particle> mParticles;
      glm::vec3 start_position = glm::vec3(0, 1,0);
      glm::vec4 start_color = glm::vec4(1,0,0,1); 
      GLuint mTexture;
      BlendMode mBlendMode;
      static Renderer theRenderer;
   };
}
#endif