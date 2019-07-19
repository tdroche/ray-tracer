/*
Light.cpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#include <math.h>
#include "Light.hpp"

Light::Light(double x, double y, double z)
{
    Vector loc(x, y, z);
    this->loc = loc;
}

COLOR_T Light::illuminate(RAY_T ray, COLOR_T surface_col, Vector int_pt, Vector normal)
{
    COLOR_T color;

    // ambient lighting
    color.r = (surface_col.r * 0.1);
    color.g = (surface_col.g * 0.1);
    color.b = (surface_col.b * 0.1);

    // diffuse lighting
    Vector L = loc - int_pt;
    L.normalize();
    double dot = L.dot(normal);

    if (dot > 0) {
        color.r += (dot * surface_col.r);
        color.g += (dot * surface_col.g);
        color.b += (dot * surface_col.b);

        // specular lighting
        Vector R = L - normal * (2.0 * dot);
        R.normalize();
        double dot2 = R.dot(ray.dir);

        if (dot2 > 0) {
            color.r += pow(dot2, 200);
            color.g += pow(dot2, 200);
            color.b += pow(dot2, 200);
        }
    }

    return color;
}
