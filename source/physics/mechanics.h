#pragma once

#include "structures/vector2d.h"

template <typename T>
static Vector2d<T> calculate_acceleration(const Vector2d<T>& F, T m) {
    if (m == 0) {
        throw std::invalid_argument("Mass cannot be zero.");
    }
    return Vector2d<T>(F.x / m, F.y / m);
}

template <typename T>
static Vector2d<T> calculate_velocity(const Vector2d<T>& v0, const Vector2d<T>& a, T t) {
    return Vector2d<T>(v0.x + a.x * t, v0.y + a.y * t);
}