/*************************************************************
 * 1. Name:
 *      Demo
 * 2. Assignment Name:
 *      Lab 07: Orbit Simulator
 * 3. Assignment Description:
 *      Simulate satellites orbiting the earth
 * 4. What was the hardest part? Be as specific as possible.
 *      ??
 * 5. How long did it take for you to complete the assignment?
 *      ??
 *****************************************************************/

#include <cassert>      // for ASSERT
#include "uiInteract.h" // for INTERFACE
#include "uiDraw.h"     // for RANDOM and DRAW*
#include "position.h"      // for POINT
#include "satellite.h"
#include "hubble.h"
#include "ship.h"
#include "test.h"
#include <math.h>
#include "gps.h"
#include "starlink.h"
#include "dragon.h"
#include "sputnik.h"
#include "Star.h"

#include <vector>
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
   public:
   Demo(Position ptUpperRight) :
   
   ptUpperRight(ptUpperRight),
   tpf((24.0 * 60.0) / 30.0)
   {
      satellites.clear();
      
      satellites.push_back(new Ship);
      
      satellites.push_back(new GPS(Position(0, 26560000), Velocity(-3880, 0)));
      satellites.push_back(new GPS(Position(23001634.72, 13280000.0), Velocity(-1940.00, 3360.18)));
      satellites.push_back(new GPS(Position(23001634.72, -13280000.0), Velocity(1940.00, 3360.18)));
      satellites.push_back(new GPS(Position(-23001634.72, -13280000.0), Velocity(1940.00, -3360.18)));
      satellites.push_back(new GPS(Position(-23001634.72, 13280000.0), Velocity(-1940.00, -3360.18)));
      satellites.push_back(new GPS(Position(0, -26560000), Velocity(3880, 0)));
      
      satellites.push_back(new Hubble(Position(0.0, -42164000.0), Velocity(-3100, 0.0)));
      
      satellites.push_back(new Starlink(Position(0,-13020000), Velocity(5800, 0)));
      
      satellites.push_back(new Dragon(Position(0,8000000), Velocity(-7900, 0)));
      
      satellites.push_back(new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050, 2684.68)));
      
       
   }
   
   
   void collision()
   {
      for (auto it = satellites.begin(); it != satellites.end(); it++)
      {
         for (auto it2 = next(it); it2 != satellites.end(); it2++)
         {
            if (!(*it) -> isDead() && !(*it2) -> isDead())
            {
               if (abs((*it)->getPosition().getPixelsX() -
                       (*it2)->getPosition().getPixelsX()) <= ((*it)->getRadius() +
                       (*it2)->getRadius()) &&
                       abs((*it)->getPosition().getPixelsY() -
                       (*it2)->getPosition().getPixelsY()) <= ((*it)->getRadius() +
                       (*it2)->getRadius()))
               {
                  (*it)->kill();
                  (*it2)->kill();
               }
         
            }
            if (computeDistance(Position(0,0), (*it)->getPosition()) <= 6378000 ) // radius of earth
            {
               (*it)->kill();
            }
         }
         
      }
      
      vector<Satellite*> newSats;
      for (auto it = satellites.begin(); it != satellites.end(); it++)
      {
         if ((*it)->isDead())
         {
            (*it)->destroy(newSats);
            it = satellites.erase(it);
         }
         if (!(*it)->isDead())
         {
            newSats.push_back(*it);
         }
      }
      satellites = newSats;
   }
   
   Position ptShip;
   Ship ship;
   double angleShip;
   double angleEarth;
   double tpf;
   Position ptUpperRight;
   Position ptStar;
   Stars stars;
   vector<Satellite*> satellites;
    
};



/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(const Interface* pUI, void* p)
{
   // the first step is to cast the void pointer into a game object. This
   // is the first step of every single callback function in OpenGL.
   Demo* pDemo = (Demo*)p;
   
   
   double secondsDay =  86400;
   double rf = -(2 * (M_PI) / 30.0) * (pDemo -> tpf * 30.0 / secondsDay);
   

   // rotate the earth
   pDemo->angleEarth += rf;
  
   
   for (auto it = pDemo->satellites.begin(); it != pDemo->satellites.end(); ++it)
      {
         Satellite *sat = *it;
         if (!sat->isDead())
         {
            sat->input(pUI, pDemo-> tpf);
            sat->move(pDemo->tpf);
         }
      }
   
   if (typeid(*(pDemo->satellites[0])) == typeid(Ship))
      {
         Ship* ship = dynamic_cast<Ship*>(pDemo->satellites[0]);
         if (ship->isFiring())
            ship->fire(pDemo->satellites);
      }
   
   // collision
   pDemo->collision();
   
   
   // draw everything
   ogstream gout;
   
   pDemo->stars.draw(gout);
   
   Position pt;
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
   
    for(Satellite* sat : pDemo->satellites){
        sat->draw(gout);
    }
  
}

//double Position::metersFromPixels = 40.0;

/*********************************
 * Initialize the simulation and set it in motion
 *********************************/
#ifdef _WIN32_X
#include <windows.h>
int WINAPI wWinMain(
                    _In_ HINSTANCE hInstance,
                    _In_opt_ HINSTANCE hPrevInstance,
                    _In_ PWSTR pCmdLine,
                    _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{
   
   testRunner();
   
   // Initialize OpenGL
   Position ptUpperRight;
   ptUpperRight.setZoom(128000.0 /* 128km equals 1 pixel */);
   ptUpperRight.setPixelsX(1000.0);
   ptUpperRight.setPixelsY(1000.0);
   Interface ui(0, NULL,
                "Demo",   /* name on the window */
                ptUpperRight);
   
   // Initialize the demo
   Demo demo(ptUpperRight);
   demo.stars.initializeStars(500, ptUpperRight);

   
   // set everything into action
   ui.run(callBack, &demo);
   
   
   return 0;
}
