/******************************************************************************
 * Header File:
 *    Fragment
 * Author:
 *
 * Summary:
 *
 *****************************************************************************/

#pragma once
#include "position.h"
#include "uiDraw.h"
#include <vector>
#include "velocity.h"
#include "parts.h"

using namespace std;


class Fragment: public Parts
{
public:
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
    
    void destroy(std::vector<Satellite*>& satellites) override { }
    void draw(ogstream& gout);

private:
    int age;
};
