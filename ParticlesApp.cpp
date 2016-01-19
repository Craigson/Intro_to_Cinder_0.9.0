#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

#include "Particle.hpp"
#include "cinder/Rand.h"


using namespace ci;
using namespace ci::app;
using namespace std;

const int NUM_PARTICLES = 200;

class ParticlesApp : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    vector<Particle> mParticles;
    
};

void ParticlesApp::setup()
{

    mParticles = vector<Particle>();
    
    for (int i = 0; i < NUM_PARTICLES; i++)
    {
        vec2 rand = randVec2();
        rand.x *= getWindowWidth();
        rand.y *= getWindowHeight();
        
        mParticles.push_back( Particle( rand ));
    }
    
    cout << mParticles.size() << endl;
}

void ParticlesApp::mouseDown( MouseEvent event )
{
}

void ParticlesApp::update()
{
    cout << getAverageFps() << endl;
}

void ParticlesApp::draw()
{
    // clear out the window with black
    gl::clear( Color::black() );
    
    for (int i = 0; i < mParticles.size(); i++)
    {
        mParticles[i].run();
//        for (int j = 0; j < mParticles.size() - 1; j++)
//        {
//            if (i != j) mParticles[i].run(mParticles[j]);
//        }
    }
}

CINDER_APP( ParticlesApp, RendererGl )
