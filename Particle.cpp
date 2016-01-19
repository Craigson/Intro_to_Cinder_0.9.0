//
//  Particle.cpp
//  Particles
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
    // Fill all variables
    mAcceleration = ci::vec2( ci::randFloat(-.02,.02), ci::randFloat(-.02,.02));
    mVelocity = ci::vec2( ci::randFloat(-2,2) , ci::randFloat(-2,2) );
    
    std::cout << mVelocity << std::endl;
    mLocation = location;
    mLifespan = 125.0;
}

void Particle::run()
{
    update();
    display();
   // checkFriends(p);
}

// Method to update location
void Particle::update()
{
    mVelocity += mAcceleration;
    mLocation += mVelocity;
    mAcceleration *= 0;
    if (mLocation.x > getWindowWidth() || mLocation.x < 0) mVelocity.x *= -1;
    if (mLocation.y > getWindowHeight() || mLocation.y < 0) mVelocity.y *= -1;
    
    
}

// Method to display
void Particle::display()
{
    gl::color( ColorA8u( 255, 255, 255, mLifespan ) );
    gl::drawSolidEllipse( mLocation, 3.0, 3.0 );
    
}

void Particle::checkFriends(const Particle& p)
{
    if (distance(mLocation, p.mLocation) < 50) gl::drawLine(mLocation, p.mLocation);
}

// Is the particle still useful?
bool Particle::isDead()
{
    if (mLifespan < 0.0) {
        return true;
    }
    else {
        return false;
    }
}