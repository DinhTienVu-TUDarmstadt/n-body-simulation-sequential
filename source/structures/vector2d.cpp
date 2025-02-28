#include "vector2d.h"
#include <stdexcept>

template class Vector2d<double>;
// Operator []
template <typename T>
T Vector2d<T>::operator[](std::size_t index) const {
    if (index == 0) return x;
    if (index == 1) return y;
    throw std::out_of_range("Index must be 0 or 1");
}

template <typename T>
T& Vector2d<T>::operator[](std::size_t index) {
    if (index == 0) return x;
    if (index == 1) return y;
    throw std::out_of_range("Index must be 0 or 1");
}

// Setter
template <typename T>
void Vector2d<T>::set(T x_val, T y_val) {
    x = x_val;
    y = y_val;
}

// Operator +
template <typename T>
Vector2d<T> Vector2d<T>::operator+(const Vector2d& other) const {
    return Vector2d(x + other.x, y + other.y);
}

// Operator -
template <typename T>
Vector2d<T> Vector2d<T>::operator-(const Vector2d& other) const {
    return Vector2d(x - other.x, y - other.y);
}

// Operator *
template <typename T>
Vector2d<T> Vector2d<T>::operator*(T scalar) const {
    return Vector2d(x * scalar, y * scalar);
}

// Operator /
template <typename T>
Vector2d<T> Vector2d<T>::operator/(T scalar) const {
    if (scalar == T(0)) {
        throw std::invalid_argument("Division by zero is not allowed");
    }
    return Vector2d(x / scalar, y / scalar);
}

// Operator ==
template <typename T>
bool Vector2d<T>::operator==(const Vector2d& other) const {
    return x == other.x && y == other.y;
}