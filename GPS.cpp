//
//  GPS.cpp
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/6/25.
//


#include "GPS.h"
#include "uiDraw.h"


void GPS::move(float time)
{       //   gravity
    double r = 6378000;
    double h = sqrt((pos.getMetersX() * pos.getMetersX()) + (pos.getMetersY() * pos.getMetersY())) - r;
    
    double g = 9.80665 * ((r / (r + h)) *(r / (r + h)));
    double gh = g * ( r / (r + h)) * (r / (r + h));
    double d = atan2(0 - pos.getMetersX(), 0 - pos.getMetersY());
    double ddx = gh * asin(d);
    double ddy = gh * acos(d);
    double sx = pos.getMetersX() + (velocity.getDX() * time) + (.5 * ddx * time *time);
    double sy = pos.getMetersY() + (velocity.getDY() * time) + (.5 * ddy * time *time);
    pos.setMeters(sx, sy);
    
}

void GPS::draw(ogstream& gout) const
{
    gout.drawGPS(pos, angularVelocity);
}
