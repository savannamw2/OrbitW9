#pragma once


#include "angle.h"
#include "velocity.h"
#include "satellite.h"
#include "hubble.h"
#include "unitTest.h"
#include <math.h>
#include "position.h"
#include "velocity.h"

//using namespace std;


class TestHubble : public UnitTest
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
        moveSat1();
        moveSat2();
        moveSat3();
        
        report("Hubble");
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
        
        Hubble h;
    
        // verify
        assertUnit(h.angularVelocity == 0.0);
//        assertUnit(gps.dead == false);
        assertUnit(h.radius == 10.0);
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
       Angle a;
       a.radians = 90;
      // exercise
       Hubble h(pos, v, a, 0.0, 0.0);
       // verify
       assertUnit(h.pos.x == 0.0);
       assertUnit(h.pos.y == 0.0);
       assertUnit(h.velocity.dx == 0.0);
       assertUnit(h.velocity.dy == 0.0);
       assertUnit(h.angularVelocity == 0.0);
       assertUnit(h.dead == false);
       assertUnit(h.radius == 10.0);
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
       Hubble h(pos, v);
       // verify
       assertUnit(h.pos.x == 0.0);
       assertUnit(h.pos.y == 0.0);
       assertUnit(h.velocity.dx == 0.0);
       assertUnit(h.velocity.dy == 0.0);
       assertUnit(h.angularVelocity == 0.0);
       assertUnit(h.dead == false);
       assertUnit(h.radius == 0.0);
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
        
        Hubble h1;
        h1.pos = pos;
        h1.velocity = v;
        
        // exercise
        Hubble h(h1);

        // verify
        assertUnit(h.pos.x == 9.0);
        assertUnit(h.pos.y == 9.0);
        assertUnit(h.velocity.dx == 9.0);
        assertUnit(h.velocity.dy == 9.0);
        assertUnit(h.angularVelocity == 0.0);
        assertUnit(h.dead == false);
        assertUnit(h.radius == 12.0);
    }
     /*********************************************
      * name:   GET RADIUS
      * input:   nothing
      * output:  90
      *********************************************/
    void getRadiusMax()
    {  // setup
      Hubble h;
      h.radius = 90.0;
      float rad;
        
        // exercise
        rad = h.getRadius();
        
        // verify
        assertEquals(rad, 90.0);
    }  // teardown

    /*********************************************
     * name:   GET RADIUS
     * input:   nothing
     * output:  4.0
     *********************************************/
   void getRadiusMin()
   {  // setup
       Hubble h;
      h.radius = 4.0;
       float rad;
       
       // exercise
       rad = h.getRadius();
       
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
       Hubble h;
      h.radius = 7.0;
       float rad;
       
       // exercise
       rad = h.getRadius();
       
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
       Hubble h;
        h.dead = true;
       bool dead;
       
       // exercise
       dead = h.isDead();
       
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
       Hubble h;
       h.dead = false;
       bool dead;
       
       // exercise
       dead = h.isDead();
       
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
       Hubble h;

       h.pos.x = 0.0;
       h.pos.y = 0.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = h.getPosition();
       
       // verify
       assertEquals(p.x, 0.0);
       assertEquals(p.y, 0.0);
       assertEquals(h.pos.x, 0.0);
       assertEquals(h.pos.y, 0.0);
   }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
   void getPosMed()
   {  // setup
       Hubble h;

       h.pos.x = 50.0;
       h.pos.y = 50.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = h.getPosition();
       
       // verify
       assertEquals(p.x, 50.0);
       assertEquals(p.y, 50.0);
       assertEquals(h.pos.x, 50.0);
       assertEquals(h.pos.y, 50.0);
   }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
   void getPosMax()
   {  // setup
       Hubble h;

       h.pos.x = 100.0;
       h.pos.y = 100.0;
       
       Position p;
       p.x = 99.0;
       p.y = 99.0;
       // exercise
       p = h.getPosition();
       
       // verify
       assertEquals(p.x, 100.0);
       assertEquals(p.y, 100.0);
       assertEquals(h.pos.x, 100.0);
       assertEquals(h.pos.y, 100.0);
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
