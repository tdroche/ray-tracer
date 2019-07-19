/*
Light.hpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#include "Vector.hpp"
#include "rt.hpp"

#ifndef LIGHT_HPP
#define LIGHT_HPP

class Light {
private:
    Vector loc;
public:
    Light(void) {}
    Light(double x, double y, double z);
    COLOR_T illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal);
};

#endif
