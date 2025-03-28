//
//  partGPSCenter.h
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

//class TestGPSCenter;

class PartGPSCenter : public Parts
{
//   friend TestGPSCenter;
   PartGPSCenter() : Parts() {}
   PartGPSCenter(const Position& pos, const Velocity& vel) : Parts(pos, vel) {this -> radius = 7;}
   
   void destroy(std::vector<Satellite*>& satellites) override;
   void draw(ogstream& gout) override;
   
};
