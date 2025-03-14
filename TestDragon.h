//
//  TestDragon.h
//  CSE231_Orbit09W10
//
//  Created by Sara Fisk on 3/13/25.
//
#pragma once

#include "angle.h"
#include "velocity.h"
#include "satellite.h"
#include "dragon.h"
#include "unitTest.h"
#include <math.h>

//using namespace std;


class TestDragon : public UnitTest
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
        
        report("Dragon");
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
        
        Dragon dragon;
        
        // verify
        assertUnit(dragon.angularVelocity == 0.0);
        //        assertUnit(gps.dead == false);
        assertUnit(dragon.radius == 7.0);
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
        Dragon dragon(pos, v, 0.0, 0.0, 0.0);
        // verify
        assertUnit(dragon.pos.x == 0.0);
        assertUnit(dragon.pos.y == 0.0);
        assertUnit(dragon.velocity.dx == 0.0);
        assertUnit(dragon.velocity.dy == 0.0);
        assertUnit(dragon.angularVelocity == 0.0);
        assertUnit(dragon.dead == false);
        assertUnit(dragon.radius == 7.0);
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
        Dragon d(pos, v);
        // verify
        assertUnit(d.pos.x == 0.0);
        assertUnit(d.pos.y == 0.0);
        assertUnit(d.velocity.dx == 0.0);
        assertUnit(d.velocity.dy == 0.0);
        assertUnit(d.angularVelocity == 0.0);
        assertUnit(d.dead == false);
        assertUnit(d.radius == 0.0);
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
        
        Dragon d1;
        d1.pos = pos;
        d1.velocity = v;
        
        // exercise
        Dragon d(d1);
        
        // verify
        assertUnit(d.pos.x == 9.0);
        assertUnit(d.pos.y == 9.0);
        assertUnit(d.velocity.dx == 9.0);
        assertUnit(d.velocity.dy == 9.0);
        assertUnit(d.angularVelocity == 0.0);
        assertUnit(d.dead == false);
        assertUnit(d.radius == 7.0);
    }
    /*********************************************
     * name:   GET RADIUS
     * input:   nothing
     * output:  10
     *********************************************/
    void getRadiusMax()
    {  // setup
        Dragon d;
        d.radius = 10.0;
        float rad;
        
        // exercise
        rad = d.getRadius();
        
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
        Dragon d;
        d.radius = 4.0;
        float rad;
        
        // exercise
        rad = d.getRadius();
        
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
        Dragon d;
        d.radius = 7.0;
        float rad;
        
        // exercise
        rad = d.getRadius();
        
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
        Dragon d;
        d.dead = true;
        bool dead;
        
        // exercise
        dead = d.isDead();
        
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
        Dragon d;
        d.dead = false;
        bool dead;
        
        // exercise
        dead = d.isDead();
        
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
        Dragon d;
        
        d.pos.x = 0.0;
        d.pos.y = 0.0;
        
        Position p;
        p.x = 99.0;
        p.y = 99.0;
        // exercise
        p = d.getPosition();
        
        // verify
        assertEquals(p.x, 0.0);
        assertEquals(p.y, 0.0);
        assertEquals(d.pos.x, 0.0);
        assertEquals(d.pos.y, 0.0);
    }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
    void getPosMed()
    {  // setup
        Dragon d;
        
        d.pos.x = 50.0;
        d.pos.y = 50.0;
        
        Position p;
        p.x = 99.0;
        p.y = 99.0;
        // exercise
        p = d.getPosition();
        
        // verify
        assertEquals(p.x, 50.0);
        assertEquals(p.y, 50.0);
        assertEquals(d.pos.x, 50.0);
        assertEquals(d.pos.y, 50.0);
    }  // teardown
    
    /*********************************************
     * name:   GET POS
     * input:   nothing
     * output:
     *********************************************/
    void getPosMax()
    {  // setup
        Dragon d;
        
        d.pos.x = 100.0;
        d.pos.y = 100.0;
        
        Position p;
        p.x = 99.0;
        p.y = 99.0;
        // exercise
        p = d.getPosition();
        
        // verify
        assertEquals(p.x, 100.0);
        assertEquals(p.y, 100.0);
        assertEquals(d.pos.x, 100.0);
        assertEquals(d.pos.y, 100.0);
    }  // teardown
    
    
};
