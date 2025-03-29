//
//  testParts.h
//  orbit2
//
//  Created by Isabel Kamphaus on 3/28/25.
//

#pragma once


#include "angle.h"
#include "velocity.h"
#include "satellite.h"
#include "parts.h"
#include "unitTest.h"
#include <math.h>

//using namespace std;


class TestParts : public UnitTest
{
public:
    void run()
    {
        defaultConstructor();
        initalConstructor();
        initalConstructor2();
        
        report("Parts");
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
        
        Parts p;
    
        // verify
        assertUnit(p.angularVelocity == 0.0);
//        assertUnit(gps.dead == false);
        assertUnit(p.radius == 0.0);
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
       Parts p(pos, v);
       // verify
       assertUnit(p.pos.x == 10.0);
       assertUnit(p.pos.y == 10.0);
       assertUnit(p.velocity.dx == 10.0);
       assertUnit(p.velocity.dy == 10.0);
       assertUnit(p.angularVelocity == 0.0);
       assertUnit(p.dead == false);
       assertUnit(p.radius == 0.0);
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
       Parts p(pos, v);
       // verify
       assertUnit(p.pos.x == 90.0);
       assertUnit(p.pos.y == 90.0);
       assertUnit(p.velocity.dx == 90.0);
       assertUnit(p.velocity.dy == 90.0);
       assertUnit(p.angularVelocity == 0.0);
       assertUnit(p.dead == false);
       assertUnit(p.radius == 0.0);
   }  // teardown
    

};
