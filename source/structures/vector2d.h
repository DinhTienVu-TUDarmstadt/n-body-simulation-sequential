#pragma once

#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <stdexcept>

template <typename T>
class Vector2d {
public:
    T x = {T()};
    T y = {T()};

    Vector2d();

    Vector2d(T x_val, T y_val);

    T operator[](std::size_t index) const;
    T& operator[](std::size_t index);

    // Setter
    void set(T x_val, T y_val);

    // Addition
    Vector2d operator+(const Vector2d& other) const;

    // Subtraction
    Vector2d operator-(const Vector2d& other) const;

    // Multiply by a scalar
    Vector2d operator*(T scalar) const;

    // Divided by a scalar
    Vector2d operator/(T scalar) const;

    // Equal compare
    bool operator==(const Vector2d& other) const;
};

template <typename T>
Vector2d<T>::Vector2d() : x(T()), y(T()) {}

template <typename T>
Vector2d<T>::Vector2d(T x_val, T y_val) : x(x_val), y(y_val) {}

#endif

