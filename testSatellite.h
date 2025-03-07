/***********************************************************************
 * Header File:
 *    TEST ANGLE
 * Author:
 *    <your name here>
 * Summary:
 *    All the unit tests for ANGLE
 ************************************************************************/

#pragma once


#include "angle.h"
#include "velocity.h"
#include "position.h"
#include "unitTest.h"
#include "satellite.h"
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
        defaultConstroctor();
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
        moveSat3();
        
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
        Satellite s();
    
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
       Satellite s();
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
        s.radius = 10.0
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
       s.radius = 4.0
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
       s.radius = 7.0
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
       bool dead
       
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
       bool dead
       
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
       
       Posistion p;
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
       
       Posistion p;
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
       
       Posistion p;
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
    
    /*********************************************
     * name:   Move
     * input:   nothing
     * output:
     *********************************************/
   void moveSat1()
   {  // setup
       
       
   }  // teardown
    
    /*********************************************
     * name:   MOVE
     * input:   nothing
     * output:
     *********************************************/
   void moveSat2()
   {  // setup
       
       
   }  // teardown
    
    /*********************************************
     * name:  MOVE
     * input:   nothing
     * output:
     *********************************************/
   void moveSat3()
   {  // setup
       
   }  // teardown
};
