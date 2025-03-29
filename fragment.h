/******************************************************************************
 * Header File:
 *    Fragment
 * Author:
 *
 * Summary:
 *
 *****************************************************************************/

#pragma once
#include "uiDraw.h"
#include <vector>
#include "parts.h"
#include "satellite.h"

//using namespace std;

class Position;
class Velocity;
class TestFragments;

class Fragment: public Parts
{
public:
    friend TestFragments;
    
    Fragment(): Parts(), age(random(50, 100)){
        this->angularVelocity = random(0.0, .75);
    }
    
    Fragment(const Position& pos, const Velocity& vel) : Parts(pos, vel),
       age(random(50, 100))
    {
       this->angularVelocity = random(0.0, 0.75);
    }
    
    void move(double time) {
      Parts::move(time);
      age--;
      if (age == 0) kill();
    }
    
   void destroy(std::vector<Satellite*>& satellites) override {}
   void draw(ogstream& gout) override;

private:
    int age;
};
