//
//  testFragments.h
//  orbit2
//
//  Created by Isabel Kamphaus on 3/28/25.
//

#pragma once


#include "angle.h"
#include "velocity.h"
#include "satellite.h"
#include "fragment.h"
#include "unitTest.h"
#include <math.h>

//using namespace std;


class TestFragments : public UnitTest
{
public:
    void run()
    {
        defaultConstructor();
        initalConstructor();
        initalConstructor2();
        moveAtZero();
        moveAtFive();
        moveAtHundred();
        
        report("Fragments");
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
        
        Fragment f;
    
        // verify
        assertUnit(f.angularVelocity == 0.0);
//        assertUnit(gps.dead == false);
        assertUnit(f.radius == 0.0);
    }  // teardown

    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zero
     *********************************************/
   void initalConstructor()
   {  // setup
       Velocity v;
       v.dx = 10.0;
       v.dy = 10.0;
       Position pos;
       pos.x = 10.0;
       pos.y = 10.0;
      
      // exercise
       Fragment f(pos, v);
       // verify
       assertUnit(f.pos.x == 10.0);
       assertUnit(f.pos.y == 10.0);
       assertUnit(f.velocity.dx == 10.0);
       assertUnit(f.velocity.dy == 10.0);
       assertUnit(f.angularVelocity == 0.0);
       assertUnit(f.dead == false);
       assertUnit(f.radius == 0.0);
   }  // teardown
    
    /*********************************************
     * name:    DEFAULT CONSTRUCTOR
     * input:   nothing
     * output:  zero
     *********************************************/
   void initalConstructor2()
   {  // setup
       Velocity v;
       v.dx = 90.0;
       v.dy = 90.0;
       Position pos;
       pos.x = 90.0;
       pos.y = 90.0;
       
      // exercise
       Fragment f(pos, v);
       // verify
       assertUnit(f.pos.x == 90.0);
       assertUnit(f.pos.y == 90.0);
       assertUnit(f.velocity.dx == 90.0);
       assertUnit(f.velocity.dy == 90.0);
       assertUnit(f.angularVelocity == 0.0);
       assertUnit(f.dead == false);
       assertUnit(f.radius == 0.0);
   }  // teardown
    
    void moveAtZero()
    {  // setup

        Fragment f;
        f.age = 0;
        
       // exercise
        f.move(1.0);
        
        // verify
        assertUnit(f.dead == true);

    }  // teardown
     
    void moveAtFive()
    {  // setup

        Fragment f;
        f.age = 5;
        
       // exercise
        f.move(1.0);
        
        // verify
        assertUnit(f.dead == false);
        assertUnit(f.age == 4);

    }  // teardown
    
    void moveAtHundred()
    {  // setup

        Fragment f;
        f.age = 100;
        
       // exercise
        f.move(1.0);
        
        // verify
        assertUnit(f.dead == false);
        assertUnit(f.age == 99);

    }  // teardown
};
