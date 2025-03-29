//
//  dragon.cpp
//  CSE231_Orbit09W10
//
//  Created by Sara Fisk on 3/13/25.
//
    
#include "dragon.h"
#include "uiDraw.h"
#include "partDragonLeft.h"
#include "partDragonRight.h"
#include "partDragonCenter.h"
#include "fragment.h"


void Dragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(pos, angle.getDegrees());
}

void Dragon::destroy(std::vector <Satellite*>& satellites)
{
   satellites.push_back(new PartDragonCenter());
   satellites.push_back(new PartDragonLeft());
   satellites.push_back(new PartDragonRight());
   satellites.push_back(new Fragment);
   satellites.push_back(new Fragment);
   
}

