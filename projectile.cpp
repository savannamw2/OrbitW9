//
//  projectile.cpp
//  OrbitSimulatorW9
//
//  Created by savanna on 3/28/25.
//

#include "angle.h"
#include "position.h"
#include "projectile.h"
#include "satellite.h"
#include "uiDraw.h"
#include "velocity.h"
#include <cmath>
#include <vector>

Projectile::Projectile(const Satellite& rhs) : Satellite(rhs)
{
   this->radius = 1;
   this->age = 70;
   this->velocity.setDX(this->velocity.getDX() +
      (9000.0 * sin(this->angle.getRadians())));
   this->velocity.setDY(this->velocity.getDY() +
      (9000.0 * cos(this->angle.getRadians())));


   this->pos.addPixels(19, this->angle.getRadians());
}

void Projectile::destroy(std::vector<Satellite*>& satellites)
{
}

void Projectile::draw(ogstream& gout)
{
   gout.drawProjectile(pos);
}
