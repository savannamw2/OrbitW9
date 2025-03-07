//void kill() {}
//void virtual draw(ogstream& gout) const {}
//void virtual destroy(std::vector <Satellite> satellites) {}
//void virtual move(float time) {}
//void virtual input(Interface& ui) {}
#include "satellite.h"


// Move Method
void Satellite::move(float time)
{
   //   gravity
   double g = 9.80665;

   //   earth radius
   double r = 6378000;
   
   double h = sqrt((pDemo -> ptGPS.getMetersX() * pDemo -> ptGPS.getMetersX()) + (pDemo -> ptGPS.getMetersY() * pDemo -> ptGPS.getMetersY())) - r;

   
   
}

