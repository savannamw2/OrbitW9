//
//  ship.h
//  OrbitSimulatorW9
//
//  Created by savanna on 3/12/25.
//

#include "satellite.h"
#include "uiInteract.h"

class TestShip;

class Ship : public Satellite
{
   friend TestShip;

public:
   
   Ship() : Satellite() {radius = 10.0;
                        pos.setPixelsX(-450.0);
                        pos.setPixelsY(450.0);
                        velocity = Velocity(0.0, -2000.0);
                        thrust = false;}
   

   void draw(ogstream& gout) override;
   
   bool isThrusting();
   
   void input(const Interface *pUI, double time);
   
   void move(float time) override; 

private:
   bool thrust; 
   
   
};
