/***********************************************************************
 * Header File:
 *    TEST ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    All the unit tests for ANGLE
 ************************************************************************/

#pragma once

#include "satellite.h"
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
class TestSatellite : public UnitTest
{
public:
    void run()
    {
      defaultConstructor();
      initalConstructor();
      getRadiusMax();
      getRadiusMin();
      getRadiusMed();
      isDeadTrue();
      isDeadFalse();
      getPosMin();
      getPosMed();
      getPosMax();
      moveSat1();
      moveSat2();
      
      report("Satellite");
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
       Satellite s; 
    
        // verify
        assertUnit(s.angularVelocity == 0.0);
        assertUnit(s.dead == false);
        assertUnit(s.radius == 0.0);
    }  // teardown

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zero
     *********************************************/
   void initalConstructor()
   {  // setup
       
      // exercise
       Satellite s;
       // verify
       assertUnit(s.angularVelocity == 0.0);
       assertUnit(s.dead == false);
       assertUnit(s.radius == 0.0);
   }  // teardown
    
     /*********************************************
      * name:   GET RADIUS
      * input:   nothing
      * output:  10
      *********************************************/
    void getRadiusMax()
    {  // setup
        Satellite s;
       s.radius = 10.0;
       
      float rad;
        
        // exercise
        rad = s.getRadius();
        
        // verify
        assertEquals(rad, 10.0);
    }  // teardown

    /*********************************************
     * name:   GET RADIUS
     * input:   nothing
     * output:  4.0
     *********************************************/
   void getRadiusMin()
   {  // setup
       Satellite s;
      s.radius = 4.0;
       float rad;
       
       // exercise
       rad = s.getRadius();
       
       // verify
       assertEquals(rad, 4.0);
   }  // teardown

    /*********************************************
     * name:   GET RADIUS
     * input:   nothing
     * output:  7.0
     *********************************************/
   void getRadiusMed()
   {  // setup
       Satellite s;
      s.radius = 7.0;
       float rad;
       
       // exercise
       rad = s.getRadius();
       
       // verify
       assertEquals(rad, 7.0);
   }  // teardown
    
    /*********************************************
     * name:   IS DEAD TRUE
     * input:   nothing
     * output:  TRUE
     *********************************************/
   void isDeadTrue()
   {  // setup
       Satellite s;
       s.dead = true;
      bool dead;
       
       // exercise
       dead = s.isDead();
       
       // verify
       assertEquals(dead, true);
   }  // teardown
    
    /*********************************************
     * name:   IS DEAD FALSE
     * input:   nothing
     * output:  TRUE
     *********************************************/
   void isDeadFalse()
   {  // setup
       Satellite s;
       s.dead = false;
      bool dead;
       
       // exercise
       dead = s.isDead();
       
       // verify
       assertEquals(dead, false);
   }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
   void getPosMin()
   {  // setup
       Satellite s;

       s.pos.x = 0.0;
       s.pos.y = 0.0;
       
      Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = s.getPosition();
       
       // verify
       assertEquals(p.x, 0.0);
       assertEquals(p.y, 0.0);
       assertEquals(s.pos.x, 0.0);
       assertEquals(s.pos.y, 0.0);
   }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
   void getPosMed()
   {  // setup
       Satellite s;

       s.pos.x = 50.0;
       s.pos.y = 50.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = s.getPosition();
       
       // verify
       assertEquals(p.x, 50.0);
       assertEquals(p.y, 50.0);
       assertEquals(s.pos.x, 50.0);
       assertEquals(s.pos.y, 50.0);
   }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
   void getPosMax()
   {  // setup
       Satellite s;

       s.pos.x = 100.0;
       s.pos.y = 100.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = s.getPosition();
       
       // verify
       assertEquals(p.x, 100.0);
       assertEquals(p.y, 100.0);
       assertEquals(s.pos.x, 100.0);
       assertEquals(s.pos.y, 100.0);
   }  // teardown
    
   void moveSat1()
   {
      // setup
      Satellite s;
      s.pos.x = 5000000000.0;
      s.pos.y = 5000000000.0;
      s.velocity.dx = 30.0;
      s.velocity.dy = 30.0;
      double time = 0;

      // exercise
      s.move(time);

      //verify
      assertEquals(time, 0);
      assertEquals(s.velocity.dx, 30.0);
      assertEquals(s.velocity.dy, 30.0);
      assertEquals(s.pos.x, 5000000000.0);
      assertEquals(s.pos.y, 5000000000.0);
   } // teardown

   /*********************************************
   * name:    GET POSITION of Satellite after moving with time.
   * input:   move(3)
   * output:  x != 50,000km, y != 50,000km
   *********************************************/
   void moveSat2()
   {
      // setup
      Satellite s;
      s.pos.x = 50000000.0;
      s.pos.y = 50000000.0;
      s.velocity.dx = 30.0;
      s.velocity.dy = 30.0;
      double time = 3;

      // exercise
      s.move(time);

      //verify
      assertEquals(time, 3);
      assertUnit(s.pos.x != 50000000.0);
      assertUnit(s.pos.y != 50000000.0);
   } // teardown
};
