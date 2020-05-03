#include "JemPCH.h"
#include "Vector2d.h"

namespace Jem {

// ==================
// Jem::Vector2d::Vector2d
// ==================
Vector2d::Vector2d(double dx, double dy) :
    x(dx), y(dy) {}

// ==================
// Jem::Vector2d::Set
// ==================
void Vector2d::Set(double dx, double dy) {
    x = dx;
    y = dy;
}

// ==================
// Jem::Vector2d::Magnitude
// ==================
double Vector2d::Magnitude() const {
    return sqrt((x * x) + (y * y));
}

// ==================
// Jem::Vector2d::Normalize
// ==================
void Vector2d::Normalize() {
    x /= Magnitude();
    y /= Magnitude();
}

// ==================
// Jem::Vector2d::Dot
// ==================
double Vector2d::Dot(const Vector2d& vector) const {
    return x * vector.x + y * vector.y;
}

// ==================
// Jem::Vector2d::operator+
// ==================
Vector2d Vector2d::operator+(const Vector2d& vector) const {
    return Vector2d(x + vector.x, y + vector.y);
}

// ==================
// Jem::Vector2d::operator+=
// ==================
Vector2d& Vector2d::operator+=(const Vector2d& vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}

// ==================
// Jem::Vector2d::operator-
// ==================
Vector2d Vector2d::operator-(const Vector2d& vector) const {
    return Vector2d(x - vector.x, y - vector.y);
}

// ==================
// Jem::Vector2d::operator-=
// ==================
Vector2d& Vector2d::operator-=(const Vector2d& vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}

// ==================
// Jem::Vector2d::operator*
// ==================
Vector2d Vector2d::operator*(const double scalar) const {
    return Vector2d(x * scalar, y * scalar);
}

// ==================
// Jem::Vector2d::operator*=
// ==================
Vector2d& Vector2d::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;

    return *this;
}

// ==================
// Jem::Vector2d::operator/
// ==================
Vector2d Vector2d::operator/(const double scalar) const {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");

    return Vector2d(x / scalar, y / scalar);
}

// ==================
// Jem::Vector2d::operator/=
// ==================
Vector2d& Vector2d::operator/=(double scalar) {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");
    x /= scalar;
    y /= scalar;

    return *this;
}
}