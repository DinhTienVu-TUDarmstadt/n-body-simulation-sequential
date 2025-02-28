#pragma once

#include <string>
#include <cstdint>
#include "vector2d.h"

#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

class BoundingBox{
public:
    double x_min;
    double x_max;
    double y_min;
    double y_max;

    // Standard constructor
    BoundingBox();

    // Constructor
    BoundingBox(double x_min_val, double x_max_val, double y_min_val, double y_max_val);

    std::string get_string();
    double get_diagonal();
    void plotting_sanity_check();
    BoundingBox get_scaled(std::uint32_t scaling_factor);

    // 2.d
    bool contains(const Vector2d<double>& position) const;
    BoundingBox get_quadrant(std::uint8_t quadrant_index) const;
};

#endif