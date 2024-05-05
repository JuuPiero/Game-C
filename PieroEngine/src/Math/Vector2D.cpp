#include "Math/Vector2D.h"

Vector2D Vector2D::operator+(const Vector2D& v) const { 
    return Vector2D(x + v.x, y + v.y); 
}
Vector2D Vector2D::operator+=(const Vector2D& v) const { 
    return Vector2D(x + v.x, y + v.y); 
}
Vector2D Vector2D::operator-(const Vector2D& v) const { 
    return Vector2D(x - v.x, y - v.y); 
}
Vector2D Vector2D::operator*(const Vector2D& v) const { 
    return Vector2D(x * v.x, y * v.y); 
}