#pragma once

#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#include <cstdint>
#include "vector2d.h"
#include "bounding_box.h"

class Universe {
public:
    std::uint32_t num_bodies;
    std::uint32_t current_simulation_epoch;
    std::vector<double> weights;
    std::vector<Vector2d<double>> forces;
    std::vector<Vector2d<double>> velocities;
    std::vector<Vector2d<double>> positions;

    Universe();

    BoundingBox get_bounding_box() const;

    std::uint32_t epoch_counter = 0;

};

#endif