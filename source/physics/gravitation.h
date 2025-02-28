#pragma once

#include <cmath>

static const double gravitational_constant = 6.67430e-11;

static double gravitational_force(double m1, double m2, double d) {
    if (d == 0) {
        throw std::invalid_argument("Distance between bodies cannot be zero.");
    }
    return gravitational_constant * m1 * m2 / (d * d);
}