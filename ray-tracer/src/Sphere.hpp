/*
Sphere.hpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#include "Vector.hpp"
#include "rt.hpp"

#ifndef SPHERE_HPP
#define SPHERE_HPP

class Sphere {
private:
    Vector ctr;
    double radius;
public:
    Sphere(void) {}
    void set(Vector ctr, double radius);
    bool intersect(RAY_T ray, double &t, Vector &int_pt, Vector &normal);
};

#endif
