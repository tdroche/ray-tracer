/*
Vector.hpp (Assignment 5)
Program created by Thomas Roche on 11/21/16
*/

#ifndef VECTOR_HPP
#define VECTOR_HPP

class Vector {
private:
    double x;
    double y;
    double z;
public:
    Vector(void) {}
    Vector(double x, double y, double z);
    void set(double x, double y, double z);
    void normalize(void);
    double dot(Vector v);
    Vector add(Vector v);
    Vector operator+(Vector v);
    Vector subtract(Vector v);
    Vector operator-(Vector v);
    Vector mult(Vector v);
    Vector operator*(Vector v);
    Vector scalar_mult(double c);
    Vector operator*(double c);
    Vector scalar_divide(double v);
    Vector operator/(double c);
    double sum_components();
    double length();
};

#endif
