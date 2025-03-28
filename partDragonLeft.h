//
//  partDragonLeft.h
//  OrbitSimulatorW9
//
//  Created by savanna on 3/27/25.
//


#pragma once
#include "parts.h"
#include "satellite.h"
#include "uiDraw.h"
#include <vector>

class Position;
class Velocity;

//class TestDragonLeft;

class PartDragonLeft : public Parts
{
//   friend TestDragonLeft;
   PartDragonLeft() : Parts() {}
   PartDragonLeft(const Position& pos, const Velocity& vel) : Parts(pos, vel) {this -> radius = 6;}
   
   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
   
};
