//
//  Sputnik.h
//  Orbit
//
//  Created by Isabel Kamphaus on 3/13/25.
//

#include "satellite.h"

class TestSputnik;

class Sputnik : public Satellite
{
public:
    friend TestSputnik;
    // constructors
    Sputnik(){};
    Sputnik(const Position& pos, const Velocity& velocity, const Angle & angle, double angularVeloicty, double radius) : Satellite(pos, velocity, angle, angularVeloicty, 4.0) {}
    Sputnik(const Position& pos, const Velocity& velocity) : Satellite(pos, velocity) {}
    ~Sputnik() {}
    
   
    // implement satellite virtual functions

   void draw(ogstream& gout) override;

};
