//
//  testGPS.h
//  CSE231_Orbit09
//
//  Created by Sara Fisk on 3/7/25.
//

#pragma once


#include "angle.h"
#include "velocity.h"
#include "satellite.h"
#include "gps.h"
#include "unitTest.h"
#include <math.h>

//using namespace std;


class TestGPS : public UnitTest
{
public:
    void run()
    {
        defaultConstructor();
        initalConstructor();
        initalConstructor2();
        getRadiusMax();
        getRadiusMin();
        getRadiusMed();
        isDeadTrue();
        isDeadFalse();
        getPosMin();
        getPosMed();
        getPosMax();
        
        report("GPS");
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
        
        GPS gps;
    
        // verify
        assertUnit(gps.angularVelocity == 0.0);
//        assertUnit(gps.dead == false);
        assertUnit(gps.radius == 12.0);
    }  // teardown

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zero
     *********************************************/
   void initalConstructor()
   {  // setup
       Velocity v;
       v.dx = 0.0;
       v.dy = 0.0;
       Position pos;
       pos.x = 0.0;
       pos.y = 0.0;
      
      // exercise
       GPS gps(pos, v, 0.0, 0.0, 0.0);
       // verify
       assertUnit(gps.pos.x == 0.0);
       assertUnit(gps.pos.y == 0.0);
       assertUnit(gps.velocity.dx == 0.0);
       assertUnit(gps.velocity.dy == 0.0);
       assertUnit(gps.angularVelocity == 0.0);
       assertUnit(gps.dead == false);
       assertUnit(gps.radius == 12.0);
   }  // teardown
    
    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zero
     *********************************************/
   void initalConstructor2()
   {  // setup
       Velocity v;
       v.dx = 0.0;
       v.dy = 0.0;
       Position pos;
       pos.x = 0.0;
       pos.y = 0.0;
       
      // exercise
       GPS gps(pos, v);
       // verify
       assertUnit(gps.pos.x == 0.0);
       assertUnit(gps.pos.y == 0.0);
       assertUnit(gps.velocity.dx == 0.0);
       assertUnit(gps.velocity.dy == 0.0);
       assertUnit(gps.angularVelocity == 0.0);
       assertUnit(gps.dead == false);
       assertUnit(gps.radius == 0.0);
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
        
        GPS gps1;
        gps1.pos = pos;
        gps1.velocity = v;
        
        // exercise
       GPS gps(gps1);

        // verify
        assertUnit(gps.pos.x == 9.0);
        assertUnit(gps.pos.y == 9.0);
        assertUnit(gps.velocity.dx == 9.0);
        assertUnit(gps.velocity.dy == 9.0);
        assertUnit(gps.angularVelocity == 0.0);
        assertUnit(gps.dead == false);
        assertUnit(gps.radius == 12.0);
    }
     /*********************************************
      * name:   GET RADIUS
      * input:   nothing
      * output:  10
      *********************************************/
    void getRadiusMax()
    {  // setup
      GPS gps;
      gps.radius = 10.0;
      float rad;
        
        // exercise
        rad = gps.getRadius();
        
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
       GPS gps;
      gps.radius = 4.0;
       float rad;
       
       // exercise
       rad = gps.getRadius();
       
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
       GPS gps;
      gps.radius = 7.0;
       float rad;
       
       // exercise
       rad = gps.getRadius();
       
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
       GPS gps;
       gps.dead = true;
       bool dead;
       
       // exercise
       dead = gps.isDead();
       
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
       GPS gps;
       gps.dead = false;
       bool dead;
       
       // exercise
       dead = gps.isDead();
       
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
       GPS gps;

       gps.pos.x = 0.0;
       gps.pos.y = 0.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = gps.getPosition();
       
       // verify
       assertEquals(p.x, 0.0);
       assertEquals(p.y, 0.0);
       assertEquals(gps.pos.x, 0.0);
       assertEquals(gps.pos.y, 0.0);
   }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
   void getPosMed()
   {  // setup
       GPS gps;

       gps.pos.x = 50.0;
       gps.pos.y = 50.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = gps.getPosition();
       
       // verify
       assertEquals(p.x, 50.0);
       assertEquals(p.y, 50.0);
       assertEquals(gps.pos.x, 50.0);
       assertEquals(gps.pos.y, 50.0);
   }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
   void getPosMax()
   {  // setup
       GPS gps;

       gps.pos.x = 100.0;
       gps.pos.y = 100.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = gps.getPosition();
       
       // verify
       assertEquals(p.x, 100.0);
       assertEquals(p.y, 100.0);
       assertEquals(gps.pos.x, 100.0);
       assertEquals(gps.pos.y, 100.0);
   }  // teardown
    
};
