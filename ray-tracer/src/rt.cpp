/*
rt.cpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#include <iostream>
#include "rt.hpp"
#include "obj.hpp"
#include "Light.hpp"

void read_objs(OBJ_T **list) {
    double cx, cy, cz, radius, r, g, b;
    OBJ_T *node;

    while (std::cin >> cx >> cy >> cz >> radius >> r >> g >> b) {
        node = new OBJ_T;
        node->sphere.set(*new Vector(cx, cy, cz), radius);
        node->color.r = r;
        node->color.g = g;
        node->color.b = b;
        node->next = *list;
        *list = node;
    }
}

COLOR_T trace(RAY_T ray, OBJ_T *list, Light light) {
    COLOR_T color;
    color.r = 0, color.g = 0, color.b = 0;
    double min_t = 1000.0;
    double t;
    Vector int_pt, closest_int_pt;
    Vector normal, closest_normal;
    OBJ_T *obj, *closest_obj = NULL;

    // finds closest intersection point and closest normal
    for (obj = list; obj != NULL; obj = obj->next) {
        if (obj->sphere.intersect(ray, t, int_pt, normal)) {
            if (t < min_t) {
                min_t = t;
                closest_obj = obj;
                closest_int_pt = int_pt;
                closest_normal = normal;
            }
        }
    }

    // calls illuminate method for light and returns lighted color of closest sphere
    if (closest_obj != NULL)
        color = light.illuminate(ray, closest_obj->color, closest_int_pt, closest_normal);

    return color;
}

int main() {
    OBJ_T *list = NULL;
    COLOR_T pixel;
    RAY_T ray;
    Light light = *new Light(5.0, 10.0, 0.0);
    ray.origin.set(0, 0, 0);
    read_objs(&list);
    std::cout << "P6\n1000 1000\n255\n";

    // iterates over pixels, initializes light
    for (int y = 0; y < 1000; y++) {
        for (int x = 0; x < 1000; x++) {
            ray.dir.set(-0.5 + (x / 1000.0), 0.5 - (y / 1000.0), 1.0);
            ray.dir.normalize();
            pixel = trace(ray, list, light);
            // color capping
            std::cout
                << (unsigned char)((pixel.r < 1 ? pixel.r : 1) * 255)
                << (unsigned char)((pixel.g < 1 ? pixel.g : 1) * 255)
                << (unsigned char)((pixel.b < 1 ? pixel.b : 1) * 255);
        }
    }

    // free the linked list
    OBJ_T *curr;
    while (list != NULL) {
        curr = list;
        list = list->next;
        delete curr;
    }
}
