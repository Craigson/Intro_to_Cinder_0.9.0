//
//  Particle.hpp
//  Particles
//
//  Created by Craig Pickard on 1/18/16.
//
//

class Particle {
public:
    Particle();
    Particle( ci::vec2 location );
    
    void run();
    void update();
    void display();
    bool isDead();
    void checkFriends(const Particle& p);
    
private:
    ci::vec2 mLocation;
    ci::vec2 mAcceleration;
    ci::vec2 mVelocity;
    float mLifespan;
};
