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


};
