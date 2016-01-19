#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

//INCLUDE THE PARTICLE HEADER FILE AND PORTION
#include "Particle.hpp"
#include "cinder/Rand.h"

//THIS IS A GLOBAL VARIABLE THAT DETERMINES HOW MANY PARTICLES WILL BE IN THE SYSTEM, THE const KEYWORD SIMPLY MEANS THAT THE VALUE WILL REMAIN CONSTANT AND CAN'T BE CHANGED ONCES THE CODE HAS COMPILED.
const int NUM_PARTICLES = 200;

using namespace ci;
using namespace ci::app;
using namespace std;

class BasicParticlesApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    //DECLARE A CONTAINER CALLED mParticles THAT WILL HOLD ALL THE PARTICLES
    vector<Particle> mParticles;
};

void BasicParticlesApp::setup()
{
    //DEFINE mParticles AS BEING A VECTOR THAT STORES Particle OBJECTS
    mParticles = vector<Particle>();
    
    //FOR EVERY PARTICLE WE WANT IN THE SYSTEM, DEFINED BY NUM_PARTICLES, CREATE A RANDOM VALUE FOR THE X AND Y POSITIONS OF THE PARTICLE, AND PASS THESE AS A VEC2 TO THE PARTICLE'S CONSTRUCTOR, THEN ADD THE PARTICLE TO THE mParticles CONTAINER
    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        vec2 rand = randVec2();
        rand.x *= getWindowWidth();
        rand.y *= getWindowHeight();
        mParticles.push_back( Particle( rand ));
    }
}

void BasicParticlesApp::mouseDown( MouseEvent event )
{
}

void BasicParticlesApp::update()
{
}

void BasicParticlesApp::draw()
{
    //CLEAR THE WINDOW WITH A BLACK FILL
    gl::clear( Color::black() );
    
    //FOR EVERY PARTICLE IN THE CONTAINER, EXECUTE THE run() MEMBER FUNCTION USING THE '.' OPERATOR
    for (int i = 0; i < mParticles.size(); i++)
    {
        mParticles[i].run();
    }
}

CINDER_APP( BasicParticlesApp, RendererGl )
