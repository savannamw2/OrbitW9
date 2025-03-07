/***********************************************************************
 * Header File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include "velocity.h" // for M_PI which is 3.14159

class TestPosition;
class TestVelocity;
class TestAcceleration;
class TestAngle;
class TestHowitzer;

/************************************
 * ANGLE
 ************************************/
class Angle
{
public:
    friend TestAcceleration;
    friend TestVelocity;
    friend TestAngle;
    friend TestHowitzer;
    friend TestProjectile;

    // Constructors
    Angle();
    Angle(const Angle& rhs);
    Angle(double degrees);

    // Getters
    double getDegrees() const;
    double getRadians() const;
    double getDX();
    double getDY();



    // Setters
    void setDegrees(double degrees);
    void setRadians(double radians);
    void setUp();
    void setDown();
    void setRight();
    void setLeft();
    void reverse();
    Angle& add(double delta);
    void setDxDy(double dx, double dy);

    bool  isLeft();
    bool  isRight();

private:
    double normalize(double radians) const;

    double radians;
    double dx;
    double dy;
    double total;

    static int  isLeftPress;          //    "   left       "
    static int  isRightPress;         //    "   right      "

    // 360 degrees equals 2 PI radians
};



#include <iostream>

/*******************************************************
 * OUTPUT ANGLE
 * place output on the screen in degrees
 *******************************************************/
inline std::ostream& operator << (std::ostream& out, const Angle& rhs)
{
    out << rhs.getDegrees() << "degree";
    return out;
}