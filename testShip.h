/***********************************************************************
 * Header File:
 *    TEST ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    All the unit tests for Ship
 ************************************************************************/

#pragma once

#include "ship.h"
#include "angle.h"
#include "velocity.h"
#include "position.h"
#include "unitTest.h"
#include <math.h>

using namespace std;

/*******************************
 * TEST ANGLE
 * A friend class for Angle which contains the Angle unit tests
 ********************************/
class TestShip : public UnitTest
{
public:
    void run()
    {
//        defaultConstructor();
//        initalConstructor2();
//        ThrustingIsTrue();
//        ThrustingIsFalse();
//        moveWithNoThrust();
//        moveWithThrust();
//        moveWithVel();
       move_thrust();
       move_no_thrust();

      
      report("Ship");
    }

private:

    /*****************************************************************
     *****************************************************************
     * CONSTRUCTOR
     *****************************************************************
     *****************************************************************/

void move_thrust()
   {  // setup
      Ship s;
      s.thrust = true;
      s.pos.x = 500000000;
      s.pos.y = 500000000;
      s.velocity.dx = 0;
      s.velocity.dy = 0;
      s.angle.radians = 0;
      double dt = 48;

         // exercise
      s.move(dt);
   
         // verify
         // s_t = s_0 + v(t) + a(t * t)
      assertUnit(s.isThrusting() == true);
      assertEquals(s.pos.x,  499999998.7);
      assertEquals(s.pos.y,  500004606.7);
      assertEquals(s.velocity.dx, 0.0);
      assertEquals(s.velocity.dy, 96.0);
      assertUnit(dt == 48);
      assertUnit(s.angle.radians == 0);
      }  // teardown

      void move_no_thrust()
      {  // setup
         Ship s;
         s.thrust = false;
         s.pos.x = 500000000;
         s.pos.y = 500000000;
         s.velocity.dx = 0;
         s.velocity.dy = 0;
         s.angle.radians = 0;
         double dt = 48;

         // exercise
         s.move(dt);

         // verify
         assertUnit(s.thrust == false);
         assertEquals(s.pos.x, 499999998.7);
         assertEquals(s.pos.y, 499999998.7);
         assertEquals(s.velocity.dx, 0.0);
         assertEquals(s.velocity.dy, 0.0);
         assertUnit(dt == 48);
         assertUnit(s.angle.radians == 0);
         
      }
   };
