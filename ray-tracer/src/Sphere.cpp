/*
Sphere.cpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#include <math.h>
#include "Sphere.hpp"

void Sphere::set(Vector ctr, double radius)
{
    this->ctr = ctr;
    this->radius = radius;
}

bool Sphere::intersect(RAY_T ray, double &t, Vector &int_pt, Vector &normal)
{
    // computes intersection point and normal, using reference parameter t
    double A, B, C;

    A = 1.0;
    B = 2.0 * ray.dir.dot(ray.origin - ctr);
    C = ((ray.origin - ctr) * (ray.origin - ctr)).sum_components() - pow(radius, 2);
    double discriminant = pow(B, 2) - (4 * A * C);

    if (discriminant < 0)
        return false;

    float t0 = (-B + sqrt(discriminant)) / (2 * A);
    float t1 = (-B - sqrt(discriminant)) / (2 * A);

    if (t0 < 0 && t1 < 0)
        return false;

    t = t0 < t1 ? t0 : t1;
    int_pt = ray.origin + (ray.dir * t);
    normal = (int_pt - ctr) / radius;

    return true;
}
