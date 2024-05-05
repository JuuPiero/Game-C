#pragma once

struct Vector2D {
    int x, y;
    Vector2D() : x(0), y(0) {}
    Vector2D(int x, int y) : x(x), y(y) {}
    Vector2D operator+(const Vector2D& v) const;
    Vector2D operator+=(const Vector2D& v) const;

    Vector2D operator-(const Vector2D& v) const;

    Vector2D operator*(const Vector2D& v) const;
};
