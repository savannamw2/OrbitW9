//
//  TestSputnik.h
//  Orbit
//
//  Created by Isabel Kamphaus on 3/13/25.
//

#pragma once


#include "angle.h"
#include "velocity.h"
#include "satellite.h"
#include "sputnik.h"
#include "unitTest.h"
#include <math.h>
#include "position.h"
#include "velocity.h"

//using namespace std;


class TestSputnik : public UnitTest
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
        
        report("Sputnik");
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
        
        Sputnik s;
    
        // verify
        assertUnit(s.angularVelocity == 0.0);
//        assertUnit(gps.dead == false);
        assertUnit(s.radius == 0.0);
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
       Sputnik s(pos, v, a, 0.0, 0.0);
       // verify
       assertUnit(s.pos.x == 0.0);
       assertUnit(s.pos.y == 0.0);
       assertUnit(s.velocity.dx == 0.0);
       assertUnit(s.velocity.dy == 0.0);
       assertUnit(s.angularVelocity == 0.0);
       assertUnit(s.dead == false);
       assertUnit(s.radius == 4.0);
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
       Sputnik s(pos, v);
       // verify
       assertUnit(s.pos.x == 0.0);
       assertUnit(s.pos.y == 0.0);
       assertUnit(s.velocity.dx == 0.0);
       assertUnit(s.velocity.dy == 0.0);
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
        
        Sputnik s1;
        s1.pos = pos;
        s1.velocity = v;
        
        // exercise
        Sputnik s(s1);

        // verify
        assertUnit(s.pos.x == 9.0);
        assertUnit(s.pos.y == 9.0);
        assertUnit(s.velocity.dx == 9.0);
        assertUnit(s.velocity.dy == 9.0);
        assertUnit(s.angularVelocity == 0.0);
        assertUnit(s.dead == false);
        assertUnit(s.radius == 4.0);
    }
     /*********************************************
      * name:   GET RADIUS
      * input:   nothing
      * output:  10
      *********************************************/
    void getRadiusMax()
    {  // setup
        Sputnik s;
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
       Sputnik s;
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
       Sputnik s;
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
       Sputnik s;
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
       Sputnik s;
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
       Sputnik s;

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
       Sputnik s;

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
       Sputnik s;

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
    

};
