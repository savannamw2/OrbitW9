/***********************************************************************
 * Header File:
 *    TEST ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    All the unit tests for Ship
 ************************************************************************/

#pragma once

#include "Ship.h"
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
        defaultConstructor();
        initalConstructor();
        initalConstructor2();
        ThrustingIsTrue();
        ThrustingIsFalse();
        moveWithNoThrust();
        moveWithThrust();
        moveWithVel();

      
      report("Ship");
    }

private:

    /*****************************************************************
     *****************************************************************
     * CONSTRUCTOR
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    DEFAULT CONSTRUCTOR
      * input:   nothing
      * output:  zero
      *********************************************/
    void defaultConstructor()
    {  // setup
       // exercise
       Ship s;
    
        // verify
        assertUnit(s.angularVelocity == 0.0);
        assertUnit(s.dead == false);
        assertUnit(s.radius == 0.0);
        assertUnit(s.thrust == false);
    }  // teardown

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zero
     *********************************************/
   void initalConstructor()
   {  // setup
       Velocity v;
       v.dx = 9.0;
       v.dy = 9.0;
       Position pos;
       pos.x = 9.0;
       pos.y = 9.0;
       Angle angle;
       angle.radians = 90;
        
      // exercise
       Ship s(pos, v, angle, 9.0, 9.0);
       // verify
       assertUnit(s.pos.x == 9.0);
       assertUnit(s.pos.y == 9.0);
       assertUnit(s.velocity.dx == 9.0);
       assertUnit(s.velocity.dy == 9.0);
       assertUnit(s.angularVelocity == 9.0);
       assertUnit(s.dead == false);
       assertUnit(s.radius == 9.0);
   }  // teardown
    
    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zero
     *********************************************/
   void initalConstructor2()
   {  // setup
       Velocity v;
       v.dx = 9.0;
       v.dy = 9.0;
       Position pos;
       pos.x = 9.0;
       pos.y = 9.0;
       
      // exercise
       Ship s(pos, v);
       // verify
       assertUnit(s.pos.x == 9.0);
       assertUnit(s.pos.y == 9.0);
       assertUnit(s.velocity.dx == 9.0);
       assertUnit(s.velocity.dy == 9.0);
       assertUnit(s.angularVelocity == 0.0);
       assertUnit(s.dead == false);
       assertUnit(s.radius == 0.0);
   }  // teardown
    
    void copyConstructor()
    {
        // setup
        Velocity v;
        v.dx = 9.0;
        v.dy = 9.0;
        Position pos;
        pos.x = 9.0;
        pos.y = 9.0;
        
        Ship s1;
        s1.pos = pos;
        s1.velocity = v;
        
        // exercise
       Ship s(s1);

        // verify
        assertUnit(s.pos.x == 9.0);
        assertUnit(s.pos.y == 9.0);
        assertUnit(s.velocity.dx == 9.0);
        assertUnit(s.velocity.dy == 9.0);
        assertUnit(s.angularVelocity == 0.0);
        assertUnit(s.dead == false);
        assertUnit(s.radius == 0.0);
    }
    
     /*********************************************
      * name:   GET Thrusting
      * input:   nothing
      * output:  true
      *********************************************/
    void ThrustingIsTrue()
    {  // setup
        Ship s;
        s.thrust = true;
       
        bool thrust;
        
        // exercise
        thrust = s.isThrusting();
        
        // verify
        assertUnit(s.thrust == true);
        assertUnit(s.thrust == true);
    }  // teardown

    /*********************************************
     * name:   GET Thrusting
     * input:   nothing
     * output:  false
     *********************************************/
   void ThrustingIsFalse()
   {  // setup
       Ship s;
       s.thrust = false;
      
       bool thrust;
       
       // exercise
       thrust = s.isThrusting();
       
       // verify
       assertUnit(s.thrust == false);
       assertUnit(s.thrust == false);
   }  // teardown

    /*********************************************
     * name:    MOVE WITHOUT THRUST
     * input:   nothing
     * output:  zero
     *********************************************/
   void moveWithNoThrust()
   {  // setup
       Velocity v;
       v.dx = 0.0;
       v.dy = 0.0;
       Position pos;
       pos.x = 0.0;
       pos.y = 6380000;
       Angle angle;
       angle.radians = 90;
       Ship s;
       s.thrust = false;
      // exercise
       s.move(1.0);
       // verify
       assertUnit(s.pos.x == 0.0);
       assertUnit(s.pos.y == 6377990.19);

   }  // teardown
    
    /*********************************************
     * name:    MOVE WITH THRUST
     * input:   nothing
     * output:  zero
     *********************************************/
   void moveWithThrust()
   {  // setup
       Velocity v;
       v.dx = 0.0;
       v.dy = 0.0;
       Position pos;
       pos.x = 0.0;
       pos.y = 6381000;
       Angle angle;
       angle.radians = 90;
       Ship s;
       s.thrust = false;
      // exercise
       s.move(1.0);
       // verify
       assertUnit(s.pos.x == 0.0);
       assertUnit(s.pos.y == 6378988.20);

   }  // teardown
    
    /*********************************************
     * name:    MOVE WITH VELOCITY
     * input:   nothing
     * output:  zero
     *********************************************/
   void moveWithVel()
   {  // setup
       Velocity v;
       v.dx = 500.0;
       v.dy = -100.0;
       Position pos;
       pos.x = 1000000.0;
       pos.y = 6381000;
       Angle angle;
       angle.radians = 90;
       Ship s;
       s.thrust = true;
      // exercise
       s.move(1.0);
       // verify
       assertUnit(s.pos.x == 1000498.52);
       assertUnit(s.pos.y == 6378890.55);

   }  // teardown
};
