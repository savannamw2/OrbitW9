//
//  parts.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//
#include "angle.h"
#include "parts.h"
#include "position.h"
#include "satellite.h"
#include "uiDraw.h"
#include "velocity.h"

Parts::Parts(const Position& pos, const Velocity& vel) : Satellite(pos, vel)
{
   this->angle.setDegrees(random(0, 360));

   this->velocity.set(this->angle, this->velocity.getSpeed() +
   random(5000.0, 9000.0));

   this->pos.addPixels(20, this->angle.getRadians());
}
