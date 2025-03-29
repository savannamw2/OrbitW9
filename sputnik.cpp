//
//  Sputnik.cpp
//  Orbit
//
//  Created by Isabel Kamphaus on 3/13/25.
//

#include "sputnik.h"
#include "uiDraw.h"
#include "fragment.h"



void Sputnik::draw(ogstream& gout)
{
    gout.drawSputnik(pos, angularVelocity);
}

void Sputnik::destroy(std::vector <Satellite*>& satellites)
{
   satellites.push_back(new Fragment);
   satellites.push_back(new Fragment);
   satellites.push_back(new Fragment);
   satellites.push_back(new Fragment);
   
}


