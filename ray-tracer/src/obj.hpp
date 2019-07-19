/*
obj.hpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#include "Sphere.hpp"
#include "rt.hpp"

#ifndef OBJ_HPP
#define OBJ_HPP

typedef struct OBJ {
    Sphere sphere;
    COLOR_T color;
    struct OBJ *next;
} OBJ_T;

#endif
