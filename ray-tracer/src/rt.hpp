/*
rt.hpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#include "Vector.hpp"

#ifndef RT_HPP
#define RT_HPP

typedef struct {
    Vector origin;
    Vector dir;
} RAY_T;

typedef struct {
    double r;
    double g;
    double b;
} COLOR_T;

#endif
