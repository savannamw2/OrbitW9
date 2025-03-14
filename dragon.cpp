//
//  dragon.cpp
//  CSE231_Orbit09W10
//
//  Created by Sara Fisk on 3/13/25.
//
    
#include "dragon.h"
#include "uiDraw.h"


void Dragon::draw(ogstream& gout)
{
   gout.drawCrewDragon(pos, angle.getDegrees());
}
