/***********************************************************************
 * Header File:
 *    TEST POSITION
 * Author:
 *    <your name here>
 * Summary:
 *    Unit tests for the Position class.
 ************************************************************************/

#pragma once

#include "unitTest.h"
#include "position.h"
#include "velocity.h"
#include "acceleration.h"

using namespace std;

/*******************************
 * TEST Position
 * A friend class for Position which contains the Position unit tests
 ********************************/
class TestPosition : public UnitTest
{
public:
    void run()
    {
        // Ticket 7: Meters
        construct_default();
        construct_nonDefault();
        construct_copy();
        assign();
        setMetersX();
        setMetersY();
        getMetersX();
        getMetersY();

        // Ticket 8: Pixels and Zoom
        setZoom_member();
        setZoom_anotherVariable();
        getZoom_member();
        getZoom_anotherVariable();
        setPixelsX_noZoom();
        setPixelsX_zoom();
        setPixelsY_noZoom();
        setPixelsY_zoom();
        getPixelsX_noZoom();
        getPixelsX_zoom();
        getPixelsY_noZoom();
        getPixelsY_zoom();

        // Ticket 9: Add
        addMetersX();
        addMetersY();
        addPixelsX_noZoom();
        addPixelsX_zoom();
        addPixelsY_noZoom();
        addPixelsY_zoom();
        add_stationary();
        add_moving();
        add_movingLonger();
        add_fromStop();
        add_fromStopLonger();
        add_complex();

        report("Position");
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
      * output:  pos=(0, 0)
      *********************************************/
    void construct_default()
    {
        // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        // exercise
        Position pos;
        // verify
        assertEquals(pos.x, 0.0);
        assertEquals(pos.y, 0.0);
        assertEquals(pos.metersFromPixels, 99.9);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*********************************************
     * name:    NON-DEFAULT CONSTRUCTOR
     * input:   x=120.0, y=360.0
     * output:  pos=(120.0, 360.0)
     *********************************************/
    void construct_nonDefault()
    {
        // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        double x = 120.0;
        double y = 360.0;
        // exercise
        Position pos(x, y);
        // verify
        assertEquals(pos.x, 120.0);
        assertEquals(pos.y, 360.0);
        assertEquals(pos.metersFromPixels, 99.9);
        assertEquals(x, 120.0);
        assertEquals(y, 360.0);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*********************************************
     * name:    COPY CONSTRUCTOR
     * input:   posRHS = (1234.5, 6789.0)
     * output:  pos = (1234.5, 6789.0)
     *********************************************/
    void construct_copy()
    {
        // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        Position posRHS;
        posRHS.x = 1234.5;
        posRHS.y = 6789.0;
        // exercise
        Position pos(posRHS);
        // verify
        assertEquals(posRHS.x, 1234.5);
        assertEquals(posRHS.y, 6789.0);
        assertEquals(posRHS.metersFromPixels, 99.9);
        assertEquals(pos.x, 1234.5);
        assertEquals(pos.y, 6789.0);
        assertEquals(pos.metersFromPixels, 99.9);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*********************************************
     * name:    ASSIGNMENT OPERATOR
     * input:   posLHS=(-99.9, -88.8)  posRHS=(24.68, -13,57)
     * output:  posLHS=(24.68, -13,57)
     *********************************************/
    void assign()
    {
        // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        Position posLHS;
        posLHS.x = -99.9;
        posLHS.y = -88.8;
        Position posRHS;
        posRHS.x = 24.68;
        posRHS.y = -13.57;
        // exercise
        posLHS = posRHS;
        // verify
        assertEquals(posRHS.x, 24.68);
        assertEquals(posRHS.y, -13.57);
        assertEquals(posRHS.metersFromPixels, 99.9);
        assertEquals(posLHS.x, 24.68);
        assertEquals(posLHS.y, -13.57);
        assertEquals(posLHS.metersFromPixels, 99.9);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*****************************************************************
     *****************************************************************
     * GETTERS
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    GET ZOOM : member variable
      * input:   pos.metersFromPixels=123.4
      * output:  zoom=123.4
      *          Position::metersFromPixels=123.4
      *********************************************/
    void getZoom_member()
    {
        Position p;
        p.metersFromPixels = 123.4;
        double metersFromPixels = Position::metersFromPixels;

        p.getZoom();

        assertEquals(p.metersFromPixels, 123.4);

        assertEquals(Position::metersFromPixels, 123.4);
    }

    /*********************************************
     * name:    GET ZOOM : another variable
     * input:   pos1.metersFromPixels=99.9  (set this first)
     *          pos2.metersFromPixels=123.4 (set this second)
     * output:  zoom=123.4
     *          pos1.metersFromPixels=123.4 (last assignment sticks)
     *          pos2.metersFromPixels=123.4
     *********************************************/
    void getZoom_anotherVariable()
    {
        Position p1;
        Position p2;

        p1.metersFromPixels = 99.9;
        p2.metersFromPixels = 123.4;

        p2.getZoom();

        assertEquals(p1.metersFromPixels, 123.4);
        assertEquals(p2.metersFromPixels, 123.4);
    }


    /*********************************************
     * name:    GET METERS X
     * input:   pos=(4500.0, 2500.0)   Store meters internally
     * output:  x=4500.0
     *********************************************/
    void getMetersX()
    {
        // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        Position pos;
        pos.x = 4500.0;
        pos.y = 2500.0;
        // exercise
        double x = pos.getMetersX();
        // verify
        assertEquals(x, 4500.0);
        assertEquals(pos.x, 4500.0);
        assertEquals(pos.y, 2500.0);
        assertEquals(pos.metersFromPixels, 99.9);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*********************************************
     * name:    GET METERS Y
     * input:   pos=(4500.0, 2500.0)
     * output:  y=2500.0
     *********************************************/
    void getMetersY()
    {
        // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        Position pos;
        pos.x = 4500.0;
        pos.y = 2500.0;
        // exercise
        double y = pos.getMetersY();
        // verify
        assertEquals(pos.x, 4500.0);
        assertEquals(pos.y, 2500.0);
        assertEquals(pos.metersFromPixels, 99.9);
        assertEquals(y, 2500.0);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*********************************************
     * name:    GET METERS X NO ZOOM
     * input:   pos=(123.4, 567.8) metersFromPixels=1
     * output:  x=123.4
     *********************************************/
    void getPixelsX_noZoom()
    {
        Position p;
        p.x = 123.4;
        p.y = 567.8;
        p.metersFromPixels = 1.0;

        double xPixels = p.getPixelsX();

        assertEquals(xPixels, 123.4);
    }

    /*********************************************
     * name:    GET PIXELS X ZOOM
     *          pixels = meters / metersFromPixels
     * input:   pos=(123.4, 567.8) metersFromPixels=100
     * output:  x=1.234
     *********************************************/
    void getPixelsX_zoom()
    {
        Position p;
        p.x = 123.4;
        p.y = 567.8;
        p.metersFromPixels = 100.0;

        double xPixels = p.getPixelsX();

        assertEquals(xPixels, 1.234);
    }

    /*********************************************
     * name:    GET PIXELS Y NO ZOOM
     * input:   pos=(123.4, 567.8) metersFromPixels=1
     * output:  y=567.8
     *********************************************/
    void getPixelsY_noZoom()
    {
        Position p;
        p.x = 123.4;
        p.y = 567.8;
        p.metersFromPixels = 1.0;

        double yPixels = p.getPixelsY();

        assertEquals(yPixels, 567.8);
    }

    /*********************************************
     * name:    GET PIXELS Y ZOOM
     * input:   pos=(123.4, 567.8) metersFromPixels=100
     * output:  y=5.678
     *********************************************/
    void getPixelsY_zoom()
    {
        Position p;
        p.x = 123.4;
        p.y = 567.8;
        p.metersFromPixels = 100.0;

        double yPixels = p.getPixelsY();

        assertEquals(yPixels, 5.678);
    }

    /*****************************************************************
     *****************************************************************
     * SETTERS
     *****************************************************************
     *****************************************************************/

     /*********************************************
      * name:    SET METERS X
      *          We store pixels internally
      * input:   pos=(999.9, 888.8) x = 123.4
      * output:  pos=(123.4, 888.8)
      *********************************************/
    void setMetersX()
    {  // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        Position pos;
        pos.x = 999.9;
        pos.y = 888.8;
        // exercise
        pos.setMetersX(123.4);
        // verify
        assertEquals(pos.x, 123.4);
        assertEquals(pos.y, 888.8);
        assertEquals(pos.metersFromPixels, 99.9);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*********************************************
     * name:    GET METERS Y
     * input:   pos=(999.9, 888.8) y = 123.4
     * output:  pos=(999.9, 123.4)
     *********************************************/
    void setMetersY()
    {  // setup
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        Position pos;
        pos.x = 999.9;
        pos.y = 888.8;
        // exercise
        pos.setMetersY(123.4);
        // verify
        assertEquals(pos.x, 999.9);
        assertEquals(pos.y, 123.4);
        assertEquals(pos.metersFromPixels, 99.9);
        // teardown
        Position::metersFromPixels = metersFromPixels;
    }

    /*********************************************
     * name:    SET PIXELS X NO ZOOM
     *          When meterFromPixels == 1, pixels and meters are the same
     * input:   pos=(999.9, 888.8) x=123.4 meterFromPixels=1
     * output:  pos=(123.4, 888.8)
     *********************************************/
    void setPixelsX_noZoom()
    {
        Position p;
        p.x = 999.9;
        p.y = 888.8;
        p.metersFromPixels = 1.0;

        p.setPixelsX(123.4);

        assertEquals(p.x, 123.4);
        assertEquals(p.y, 888.8);


    }

    /*********************************************
     * name:    SET PIXELS X ZOOM
     *          meters = pixels * metersFromPixels
     * input:   pos=(999.9, 888.8) x=123.4 meterFromPixels=100
     * output:  pos=(12340.0, 888.8)
     *********************************************/
    void setPixelsX_zoom()
    {
        Position p;
        p.x = 999.9;
        p.y = 888.8;
        p.metersFromPixels = 100.0;

        p.setPixelsX(123.4);

        assertEquals(p.x, 12340.0);
        assertEquals(p.y, 888.8);
    }

    /*********************************************
     * name:    SET PIXELS Y NO ZOOM
     * input:   pos=(999.9, 888.8) y=123.4 meterFromPixels=1
     * output:  pos=(999.9, 123.4)
     *********************************************/
    void setPixelsY_noZoom()
    {
        Position p;
        p.x = 999.9;
        p.y = 888.8;
        p.metersFromPixels = 1.0;

        p.setPixelsY(123.4);

        assertEquals(p.x, 999.9);
        assertEquals(p.y, 123.4);
    }

    /*********************************************
     * name:    SET PIXELS Y ZOOM
     * input:   pos=(999.9, 888.8) y=123.4 meterFromPixels=100
     * output:  pos=(999.9, 12340.0)
     *********************************************/
    void setPixelsY_zoom()
    {
        Position p;
        p.x = 999.9;
        p.y = 888.8;
        p.metersFromPixels = 100.0;

        p.setPixelsY(123.4);

        assertEquals(p.x, 999.9);
        assertEquals(p.y, 12340.0);
    }

    /*********************************************
     * name:    ADD METERS X
     * input:   pos=(4500,2500) x=123.4
     * output:  pos=(4623.4,2500)
     *********************************************/
    void addMetersX()
    {
        Position p;
        p.x = 4500.0;
        p.y = 2500.0;

        p.addMetersX(123.4);


        assertEquals(p.x, 4623.4);
        assertEquals(p.y, 2500);
    }

    /*********************************************
     * name:    ADD METERS Y
     * input:   pos=(4500,2500) y=123.4
     * output:  pos=(4500,2623.4)
     *********************************************/
    void addMetersY()
    {
        Position p;
        p.x = 4500.0;
        p.y = 2500.0;

        p.addMetersY(123.4);


        assertEquals(p.x, 4500.0);
        assertEquals(p.y, 2623.4);
    }

    /*********************************************
     * name:    ADD PIXELS X ZERO ZOOM
     * input:   pos=(4500,2500) x=3pixels meterFromPixels=1.0
     * output:  pos=(4503,2500)
     *********************************************/
    void addPixelsX_noZoom()
    {
        Position p;
        p.x = 4500.0;
        p.y = 2500.0;
        Position::metersFromPixels = 1.0;
        p.addPixelsX(3.0);


        assertEquals(p.x, 4503.0);
        assertEquals(p.y, 2500.0);
    }

    /*********************************************
     * name:    ADD PIXELS X ZOOM
     * input:   pos=(4500,2500) x=3pixels meterFromPixels=50.0
     * output:  pos=(4650,2500)
     *********************************************/
    void addPixelsX_zoom()
    {
        Position p;
        p.x = 4500.0;
        p.y = 2500.0;
        Position::metersFromPixels = 50.0;

        p.addPixelsX(3.0);


        assertEquals(p.x, 4650.0);
        assertEquals(p.y, 2500.0);
    }

    /*********************************************
     * name:    ADD PIXELS Y ZERO ZOOM
     * input:   pos=(4500,2500) y=3pixels meterFromPixels=1.0
     * output:  pos=(4500,2503)
     *********************************************/
    void addPixelsY_noZoom()
    {
        Position p;
        p.x = 4500.0;
        p.y = 2500.0;
        Position::metersFromPixels = 1.0;
        p.addPixelsY(3.0);


        assertEquals(p.x, 4500.0);
        assertEquals(p.y, 2503.0);
    }

    /*********************************************
     * name:    ADD PIXELS Y ZOOM
     * input:   pos=(4500,2500) y=3pixels meterFromPixels=50.0
     * output:  pos=(4500,2650)
     *********************************************/
    void addPixelsY_zoom()
    {
        Position p;
        p.x = 4500.0;
        p.y = 2500.0;
        p.metersFromPixels = 50.0;

        p.addPixelsY(3.0);


        assertEquals(p.x, 4500.0);
        assertEquals(p.y, 2650.0);
    }

    /*********************************************
     * name:    SET ZOOM : member variable
     * input:   pos.metersFromPixels = 99.9, setZoom(123.4)
     * output:  pos.metersFromPixels=123.4
     *       Position::metersFromPixels=123.4
     *********************************************/
    void setZoom_member()
    {
        Position p;
        p.metersFromPixels = 99.9;

        p.setZoom(123.4);


        assertEquals(p.metersFromPixels, 123.4);
        assertEquals(Position::metersFromPixels, 123.4);

    }

    /*********************************************
     * name:    SET ZOOM : another variable
     * input:   pos1.metersFromPixels=99.9
     *          pos2.metersFromPixels=88.9
     *          pos2.setZoom(123.4)
     * output:  pos1.metersFromPixels=123.4
     *          pos2.metersFromPixels=123.4
     *          Position::metersFromPixels=123.4
     *********************************************/
    void setZoom_anotherVariable()
    {
        Position p1;
        Position p2;

        p1.metersFromPixels = 99.9;
        p2.metersFromPixels = 88.9;

        p2.setZoom(123.4);

        assertEquals(p1.metersFromPixels, 123.4);
        assertEquals(p2.metersFromPixels, 123.4);
        assertEquals(Position::metersFromPixels, 123.4);
    }

    /*********************************************
     * name:    ADD update position when not moving and not accelerating
     * input:   pos=(11.1,22.2) acc=(0,0), vel=(0,0) t=1
     * output:  pos=(11.1,22.2)
     *********************************************/
    void add_stationary()
    {
        Position p;
        Acceleration a;
        Velocity v;
        p.x = 11.1;
        p.y = 22.2;
        a.ddx = 0.0;
        a.ddy = 0.0;
        v.dx = 0.0;
        v.dy = 0.0;

        p.add(a, v, 1);

        assertEquals(p.x, 11.1);
        assertEquals(p.y, 22.2);
    }

    /*********************************************
     * name:    ADD update position when moving but not accelerating
     * input:   pos=(11.1,22.2) acc=(0,0), vel=(0.5,0.4) t=1
     * output:  pos.x = 11.6 = 11.1 + 0.5*1
     *          pos.y = 22.6 = 22.2 + 0.4*1
     *********************************************/
    void add_moving()
    {
        Position p;
        Acceleration a;
        Velocity v;
        p.x = 11.1;
        p.y = 22.2;
        a.ddx = 0.0;
        a.ddy = 0.0;
        v.dx = 0.5;
        v.dy = 0.4;

        p.add(a, v, 1);

        assertEquals(p.x, 11.6);
        assertEquals(p.y, 22.6);
    }

    /*********************************************
     * name:    ADD update position when moving longer (2 seconds) but not accelerating
     * input:   pos=(11.1,22.2) acc=(0,0), vel=(0.5,0.4) t=2
     * output:  pos.x = 12.1 = 11.1 + 0.5*2
     *          pos.y = 23.0 = 22.2 + 0.4*2
     *********************************************/
    void add_movingLonger()
    {
        Position p;
        Acceleration a;
        Velocity v;
        p.x = 11.1;
        p.y = 22.2;
        a.ddx = 0.0;
        a.ddy = 0.0;
        v.dx = 0.5;
        v.dy = 0.4;

        p.add(a, v, 2);

        assertEquals(p.x, 12.1);
        assertEquals(p.y, 23.0);
    }

    /*********************************************
     * name:    ADD update position when accelerating but not moving
     * input:   pos=(11.1,22.2) acc=(0.2,0.3), vel=(0,0) t=1
     * output:  pos.x = 11.20 = 11.1 + 1/2 .2 1^2
     *          pos.y = 22.35 = 22.2 + 1/2 .3 1^2
     *********************************************/
    void add_fromStop()
    {
        Position p;
        Acceleration a;
        Velocity v;
        p.x = 11.1;
        p.y = 22.2;
        a.ddx = 0.2;
        a.ddy = 0.3;
        v.dx = 0.0;
        v.dy = 0.0;

        p.add(a, v, 1);

        assertEquals(p.x, 11.20);
        assertEquals(p.y, 22.35);
    }

    /*********************************************
     * name:    ADD update position when accelerating longer (2 seconds)
     * input:   pos=(11.1,22.2) acc=(0.2,0.3), vel=(0,0) t=2
     * output:  pos.x = 11.5 = 11.1 + 1/2 .2 2^2
     *          pos.y = 22.8 = 22.2 + 1/2 .3 2^2
     *********************************************/
    void add_fromStopLonger()
    {
        Position p;
        Acceleration a;
        Velocity v;
        p.x = 11.1;
        p.y = 22.2;
        a.ddx = 0.2;
        a.ddy = 0.3;
        v.dx = 0.0;
        v.dy = 0.0;

        p.add(a, v, 2);

        assertEquals(p.x, 11.50);
        assertEquals(p.y, 22.8);
    }

    /*********************************************
     * name:    ADD update position when both moving and accelerating for 2 seconds
     * input:   pos=(11.1,22.2) acc=(0.2,0.3), vel=(0.5,0.4) t=2
     * output:  pos.x = 12.5 = 11.1 + 0.5*2 + 1/2 .2 2^2
     *          pos.y = 23.6 = 22.2 + 0.4*2 + 1/2 .3 2^2
     *********************************************/
     // update position when both moving and accelerating for 2 seconds
    void add_complex()
    {  // SETUP
        double metersFromPixels = Position::metersFromPixels;
        Position::metersFromPixels = 99.9;
        Position pos;
        pos.x = 11.1;
        pos.y = 22.2;
        Velocity vel;
        vel.dx = 0.5;
        vel.dy = 0.4;
        Acceleration acc;
        acc.ddx = 0.2;
        acc.ddy = 0.3;
        double time(2.0);

        // EXERCISE
        pos.add(acc, vel, time);

        // VERIFY
        assertEquals(pos.x, 12.5); // 12.5 = 11.1 + 0.5*2 + 1/2 .2 2^2
        assertEquals(pos.y, 23.6); // 23.6 = 22.2 + 0.4*2 + 1/2 .3 2^2
        assertEquals(vel.dx, 0.5);
        assertEquals(vel.dy, 0.4);
        assertEquals(acc.ddx, 0.2);
        assertEquals(acc.ddy, 0.3);
        assertEquals(time, 2.0);

        // TEARDOWN
        Position::metersFromPixels = metersFromPixels;
    }

};
