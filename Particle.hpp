//
//  Particle.hpp
//  BasicParticles
//
//  Created by Craig Pickard on 1/18/16.
//
//

#pragma once

#include <cinder/gl/gl.h>
#include <cinder/Vector.h>

class Particle {
public:
    
    //THE CONSTRUCTOR IS USED TO "CREATE" OBJECTS FROM THE CLASS
    
    //THIS IS THE DEFAULT CONSTRUCTOR: IT'S IS USED IF YOU DON'T DECLARE YOUR OWN
    Particle();
    
    //THIS IS THE MAIN CONSTRUCTOR: WE PASS A VEC2, FOR THE PARTICLES INITAL LOCATION, TO THE CONSTRUCTOR AS AN ARGUMENT WHEN WE CREATE A PARTICLE OBJECT, THIS ALLOWS US TO CREATE A PARTICLE AT A SPECIFIC LOCATION IN THE WINDOW
    Particle( ci::vec2 location );
    
    //THESE ARE THE MEMBER FUNCTIONS: EACH PARTICLE HAS ITS OWN INTERNAL VERSIONS OF THESE FUNCTIONS
    void run();
    void update();
    void display();
    
    //THESE ARE THE MEMBER VARIABLES: EACH PARTICLE STORES ITS OWN LOCATION, VELOCITY, AND ACCELERATION
    ci::vec2 mLocation;
    ci::vec2 mAcceleration;
    ci::vec2 mVelocity;
};
  