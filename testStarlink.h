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
#include "starlink.h"
#include "unitTest.h"
#include <math.h>

using namespace std;


class TestStarlink : public UnitTest
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
      
      report("Starlink");
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
      
      Starlink s;
      
      // verify
      assertUnit(s.angularVelocity == 0.0);
      //        assertUnit(gps.dead == false);
      assertUnit(s.radius == 6.0);
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
      Starlink s(pos, v, 0.0, 0.0, 0.0);
      // verify
      assertUnit(s.pos.x == 0.0);
      assertUnit(s.pos.y == 0.0);
      assertUnit(s.velocity.dx == 0.0);
      assertUnit(s.velocity.dy == 0.0);
      assertUnit(s.angularVelocity == 0.0);
      assertUnit(s.dead == false);
      assertUnit(s.radius == 6.0);
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
      Starlink s(pos, v);
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
      
      Starlink s;
      s.pos = pos;
      s.velocity = v;
      
      // exercise
      Starlink s1(s);
      
      // verify
      assertUnit(s1.pos.x == 9.0);
      assertUnit(s1.pos.y == 9.0);
      assertUnit(s1.velocity.dx == 9.0);
      assertUnit(s1.velocity.dy == 9.0);
      assertUnit(s1.angularVelocity == 0.0);
      assertUnit(s1.dead == false);
      assertUnit(s1.radius == 6.0);
   }
   /*********************************************
    * name:   GET RADIUS
    * input:   nothing
    * output:  10
    *********************************************/
   void getRadiusMax()
   {  // setup
      Starlink s;
      s.radius = 6.0;
      float rad;
      
      // exercise
      rad = s.getRadius();
      
      // verify
      assertEquals(rad, 6.0);
   }  // teardown
   
   /*********************************************
    * name:   GET RADIUS
    * input:   nothing
    * output:  4.0
    *********************************************/
   void getRadiusMin()
   {  // setup
      Starlink s;
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
      Starlink s;
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
      Starlink s;
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
      Starlink s;
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
      Starlink s;
      
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
      Starlink s;
      
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
      Starlink s;
      
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
