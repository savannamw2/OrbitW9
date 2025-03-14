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
      satellites.push_back(new GPS(Position(0.0, 42164000), Velocity(-3100, 0.0)));
      satellites.push_back(new Hubble(Position(0.0, -42164000.0), Velocity(3100, 0.0)));
      satellites.push_back(new Starlink(Position(0,-13020000), Velocity(5800, 0)));
      satellites.push_back(new Dragon(Position(0,8000000), Velocity(-7900, 0)));
      satellites.push_back(new Sputnik(Position(-36515095.13, 21082000.0), Velocity(2050, 2684.68)));
      
//
//      ptSputnik.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptSputnik.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptStarlink.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptStarlink.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptCrewDragon.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptCrewDragon.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
//
//      ptShip.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptShip.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));

//      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
       
   }

   
   unsigned char phaseStar;
   Position ptShip;
   Ship ship;
   double angleShip;
   double angleEarth;
   double tpf;
   Position ptUpperRight;
   Position ptStar;
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
   
   //
   // accept input
   //
   
    //vector<Satellite()> satellites;
    
   // move by a little
//   if (pUI->isUp())
//      pDemo->ptShip.addPixelsY(1.0);
//   if (pUI->isDown())
//      pDemo->ptShip.addPixelsY(-1.0);
//   if (pUI->isLeft())
//      pDemo->ptShip.addPixelsX(-1.0);
//   if (pUI->isRight())
//      pDemo->ptShip.addPixelsX(1.0);
   
   
   double secondsDay =  86400;
   double rf = -(2 * (M_PI) / 30.0) * (pDemo -> tpf * 30.0 / secondsDay);
   

   // rotate the earth
   pDemo->angleEarth += rf;
  
   //   pDemo->angleShip += 0.02;
   pDemo->phaseStar++;
   
   // draw everything
   ogstream gout;
   
   pDemo->ship.input(pUI, pDemo-> tpf);
    
    for(Satellite *sat : pDemo->satellites){
        sat->move(pDemo -> tpf);
    }
    
    pDemo->ship.draw(gout);
    for(Satellite* sat : pDemo->satellites){
        sat->draw(gout);
    }
    
    
   // draw satellites
//   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
//   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
//   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
//   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
//   gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
//   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);
   
   // draw parts
//   pt.setPixelsX(pDemo->ptCrewDragon.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptCrewDragon.getPixelsY() + 20);
//   gout.drawCrewDragonRight(pt, pDemo->angleShip); // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptHubble.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptHubble.getPixelsY() + 20);
//   gout.drawHubbleLeft(pt, pDemo->angleShip);      // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptGPS.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptGPS.getPixelsY() + 20);
//   gout.drawGPSCenter(pt, pDemo->angleShip);       // notice only two parameters are set
//   pt.setPixelsX(pDemo->ptStarlink.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptStarlink.getPixelsY() + 20);
//   gout.drawStarlinkArray(pt, pDemo->angleShip);   // notice only two parameters are set
   
   // draw fragments
//   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
//   gout.drawFragment(pt, pDemo->angleShip);
//   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
//   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
//   gout.drawFragment(pt, pDemo->angleShip);
   
   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);
   
   // draw the earth
   Position pt;
   pt.setMeters(0.0, 0.0);
   gout.drawEarth(pt, pDemo->angleEarth);
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
   
   // set everything into action
   ui.run(callBack, &demo);
   
   
   return 0;
}
