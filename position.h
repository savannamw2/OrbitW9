/***********************************************************************
 * Header File:
 *    Point : The representation of a position
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a location on the screen
 *    or the location on the field.
 ************************************************************************/


#pragma once

#include <iostream>
#include <cmath>
#include "velocity.h"
#include "acceleration.h"

class TestPosition;
class Acceleration;
class Velocity;
class TestSatellite;
class TestGPS;
class TestShip;
class TestHubble;
class TestSputnik;
class TestStarlink;
class TestDragon;

/*********************************************
 * Position
 * A single position on the field in Meters
 *********************************************/
class Position
{
   public:
   friend TestPosition;
   friend TestSatellite;
   friend TestGPS;
    friend TestShip;
    friend TestHubble;
    friend TestSputnik;
    friend TestStarlink;
    friend TestDragon;
    
   
   // constructors
   Position(): x(0.0), y(0.0)  {}
   Position(double x, double y);
   Position(const Position & pt) : x(pt.x), y(pt.y) {}
   Position& operator = (const Position& pt);
   
   // getters
   double getMetersX()       const { return x;                    }
   double getMetersY()       const { return y;                    }
   double getPixelsX()       const { return x / metersFromPixels; }
   double getPixelsY()       const { return y / metersFromPixels; }
   double getDx()            const{ return dx;}
   double getDy()            const{return dy;}
   
   void setDx(double dx) {this -> dx = dx;}
   void setDy(double dy) {this -> dy = dy;}
   
   

   // setters
   void setMeters(double xMeters, double yMeters) {x = xMeters; y = yMeters; }
   void setMetersX(double xMeters)       { x = xMeters;           }
   void setMetersY(double yMeters)       { y = yMeters;           }
   void setPixelsX(double xPixels)       { x = xPixels * metersFromPixels;          }
   void setPixelsY(double yPixels)       { y = yPixels * metersFromPixels;          }
   void addMetersX(double dxMeters)      { setMetersX(getMetersX() + dxMeters);     }
   void addMetersY(double dyMeters)      { setMetersY(getMetersY() + dyMeters);     }
   void addPixelsX(double dxPixels)      { setPixelsX(getPixelsX() + dxPixels);     }
   void addPixelsY(double dyPixels)      { setPixelsY(getPixelsY() + dyPixels);     }
   
   void add(const Acceleration &a, const Velocity &v, double t);

   // deal with the ratio of meters to pixels
   void setZoom(double metersFromPixels)
   {
      this->metersFromPixels = metersFromPixels;
   }
   double getZoom() const { return metersFromPixels; }

private:
   double x;                 // horizontal position
   double y;                 // vertical position
   double dx;
   double dy;
   static double metersFromPixels;
};

/*********************************************
 * COMPUTE DISTANCE
 * Find the distance between two positions
 *********************************************/
inline double computeDistance(const Position& pos1, const Position& pos2)
{
   return sqrt((pos1.getMetersX() - pos2.getMetersX()) * (pos1.getMetersX() - pos2.getMetersX()) +
               (pos1.getMetersY() - pos2.getMetersY()) * (pos1.getMetersY() - pos2.getMetersY()));
}

// stream I/O useful for debugging
std::ostream & operator << (std::ostream & out, const Position& pt);
std::istream & operator >> (std::istream & in,        Position& pt);


/*********************************************
 * PT
 * Trivial point
 *********************************************/
struct PT
{
   double x;
   double y;
};


