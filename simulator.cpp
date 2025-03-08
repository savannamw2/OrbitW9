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
//#include "satellite.h"
#include "test.h"
#include <math.h>
using namespace std;

/*************************************************************************
 * Demo
 * Test structure to capture the LM that will move around the screen
 *************************************************************************/
class Demo
{
   public:
   Demo(Position ptUpperRight) :
   ptUpperRight(ptUpperRight)
   {
//      ptHubble.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptHubble.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
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
//      
//      ptGPS.setPixelsX(ptUpperRight.getPixelsX() * 0);
//      ptGPS.setPixelsY(ptUpperRight.getPixelsY() * 42164000);
//      
//      ptStar.setPixelsX(ptUpperRight.getPixelsX() * random(-0.5, 0.5));
//      ptStar.setPixelsY(ptUpperRight.getPixelsY() * random(-0.5, 0.5));
      
      ptGPS.setMetersX(0.0);
      ptGPS.setMetersY(42164000);
      ptGPS.setDx(-3100);
      ptGPS.setDy(0);
      
      angleShip = 0.0;
      angleEarth = 0.0;
      phaseStar = 0;
   }
   
   Position ptHubble;
   Position ptSputnik;
   Position ptStarlink;
   Position ptCrewDragon;
   Position ptShip;
   Position ptGPS;
   Position ptStar;
   Position ptUpperRight;
   
   unsigned char phaseStar;
   
   double angleShip;
   double angleEarth;
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
   
   // move by a little
   if (pUI->isUp())
      pDemo->ptShip.addPixelsY(1.0);
   if (pUI->isDown())
      pDemo->ptShip.addPixelsY(-1.0);
   if (pUI->isLeft())
      pDemo->ptShip.addPixelsX(-1.0);
   if (pUI->isRight())
      pDemo->ptShip.addPixelsX(1.0);
   
   
   //
   // perform all the game logic
   //
//   double hoursDay = 24.0;
//   double minutesHour = 60.0;
//   double td = hoursDay * minutesHour;
//   
//   double frameRate = 30.0;
//   double tpf = td / frameRate;
//   
//   double secondsDay =  86400;
//   double rf = -(2 * (M_PI) / frameRate) * (td / secondsDay);
//   
//   double g = 9.80665;
//   double r = 6378000;
//   
//   
//   double h = sqrt((pDemo -> ptGPS.getMetersX() * pDemo -> ptGPS.getMetersX()) + (pDemo -> ptGPS.getMetersY() * pDemo -> ptGPS.getMetersY())) - r;
//   
//   // acceleration
//   double gh = g * ( r / (r + h)) * (r / (r + h));
//   
//   // angle
//   double d = atan2(0 - pDemo -> ptGPS.getMetersX(), 0 - pDemo -> ptGPS.getMetersY());
//  
//   // velocity
//   double ddx = gh * sin(d);
//   double ddy = gh * cos(d);
//   
//   pDemo -> ptGPS.setDx(pDemo -> ptGPS.getDx()  + (ddx * tpf));
//   pDemo -> ptGPS.setDy(pDemo -> ptGPS.getDy()  + (ddy * tpf));
//   
//   // distance
//   pDemo->ptGPS.setMetersX(pDemo -> ptGPS.getMetersX() + ((pDemo -> ptGPS.getDx()  + (ddx * tpf)) * tpf) + (0.5 * gh * (tpf * tpf)));
//   pDemo->ptGPS.setMetersY(pDemo -> ptGPS.getMetersY() + ((pDemo -> ptGPS.getDy()  + (ddy * tpf)) * tpf) + (0.5 * gh * (tpf * tpf)));
//   
//   // rotate the earth
//   pDemo->angleEarth += rf;
//   //   pDemo->angleShip += 0.02;
//   pDemo->phaseStar++;
//   
//   //
//   // draw everything
//   //
   
   Position pt;
   ogstream gout(pt);
   
   // draw satellites
//   gout.drawCrewDragon(pDemo->ptCrewDragon, pDemo->angleShip);
//   gout.drawHubble    (pDemo->ptHubble,     pDemo->angleShip);
//   gout.drawSputnik   (pDemo->ptSputnik,    pDemo->angleShip);
//   gout.drawStarlink  (pDemo->ptStarlink,   pDemo->angleShip);
//   gout.drawShip      (pDemo->ptShip,       pDemo->angleShip, pUI->isSpace());
   gout.drawGPS       (pDemo->ptGPS,        pDemo->angleShip);
   
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
   pt.setPixelsX(pDemo->ptSputnik.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptSputnik.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);
   pt.setPixelsX(pDemo->ptShip.getPixelsX() + 20);
   pt.setPixelsY(pDemo->ptShip.getPixelsY() + 20);
   gout.drawFragment(pt, pDemo->angleShip);
   
   // draw a single star
   gout.drawStar(pDemo->ptStar, pDemo->phaseStar);
   
   // draw the earth
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
