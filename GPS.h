//
//  GPS.h
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "satellite.h"



class GPS : public Satellite
{
    
    // constructors
    GPS(const Position& pos, const Velocity& velocity, const Angle & angle, double angularVeloicty, double radius) : Satellite(pos, velocity, angle, angularVeloicty, radius) {}
    GPS(const Position& pos, const Velocity& velocity) : Satellite(pos, velocity) {}
    ~GPS() {}
    
    // implement satellite virtual functions
    void move(float time);
    void draw(ogstream& gout) const;
    
    //Velocity velocity;
    //Position pos;
    //double angularVelocity;
    //bool dead;
    //float radius;
    
};
