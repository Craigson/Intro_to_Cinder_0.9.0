//
//  Particle.cpp
//  BasicParticles
//
//  Created by Craig Pickard on 1/18/16.
//
//

#include "Particle.hpp"


#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;


Particle::Particle()
{
}

Particle::Particle( ci::vec2 location )
{
    mAcceleration = ci::vec2( ci::randFloat(-.02,.02), ci::randFloat(-.02,.02));
    mVelocity = ci::vec2( ci::randFloat(-2,2) , ci::randFloat(-2,2) );
    
    std::cout << mVelocity << std::endl;
    mLocation = location;
}

void Particle::run()
{
    update();
    display();
}


void Particle::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    mAcceleration *= 0;
    if (mLocation.x > getWindowWidth() || mLocation.x < 0) mVelocity.x *= -1;
    if (mLocation.y > getWindowHeight() || mLocation.y < 0) mVelocity.y *= -1;
    
    
}


void Particle::display()
{
    gl::color( ColorA8u( 255, 255, 255, 255 ) );
    gl::drawSolidEllipse( mLocation, 3.0, 3.0 );
    
}

