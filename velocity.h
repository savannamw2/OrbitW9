/***********************************************************************
 * Header File:
 *    VELOCITY
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about speed
 ************************************************************************/

#pragma once

 // for unit tests
class TestPosition;
class TestVelocity;
class TestAcceleration;

// for add()
class Acceleration;
class Angle;
class TestGPS;
class TestSatellite;
class TestShip;

/*********************************************
 * Velocity
 * I feel the need, the need for speed
 *********************************************/
class Velocity
{
    // for unit tests
   friend TestPosition;
   friend TestVelocity;
   friend TestSatellite;
   friend TestGPS;
   friend TestShip;

public:
    // constructors
    Velocity();
    Velocity(double dx, double dy);

    // getters
    double getDX()       const;
    double getDY()       const;
    double getSpeed()    const;

    // setters
    void setDX(double dx);
    void setDY(double dy);
    void set(const Angle& angle, double magnitude);
    void addDX(double dx);
    void addDY(double dy);
    void add(const Acceleration& acceleration, double time);
    void reverse();
    void addV(const Velocity& v);

private:
    double dx;           // horizontal velocity
    double dy;           // vertical velocity
};

