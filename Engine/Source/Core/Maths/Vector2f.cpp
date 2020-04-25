#include "JemPCH.h"
#include "Vector2f.h"

namespace Jem {

Vector2f::Vector2f() :
    x(0.0f), y(0.0f) {}

Vector2f::Vector2f(float fx, float fy) :
    x(fx), y(fy) {}

void Vector2f::Set(float fx, float fy) {
    x = fx;
    y = fy;
}

float Vector2f::Magnitude() const {
    return sqrt((x * x) + (y * y));
}

void Vector2f::Normalise() {
    x /= Magnitude();
    y /= Magnitude();
}

float Vector2f::Dot(const Vector2f& vector) const {
    return x * vector.x + vector.y * y;
}

Vector2f& Vector2f::operator=(const Vector2f& vector) {
    x = vector.x;
    y = vector.y;

    return *this;
}

Vector2f Vector2f::operator+(const Vector2f& vector) const {
    return Vector2f(x + vector.x, y + vector.y);
}

Vector2f& Vector2f::operator+=(const Vector2f& vector) {
    x += vector.x;
    y += vector.y;

    return *this;
}

Vector2f Vector2f::operator-(const Vector2f& vector) const {
    return Vector2f(x - vector.x, y - vector.y);
}

Vector2f& Vector2f::operator-=(const Vector2f& vector) {
    x -= vector.x;
    y -= vector.y;

    return *this;
}

Vector2f Vector2f::operator*(const float scalar) const {
    return Vector2f(x * scalar, y * scalar);
}

Vector2f& Vector2f::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;

    return *this;
}

Vector2f Vector2f::operator/(const float scalar) const {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");

    return Vector2f(x / scalar, y / scalar);
}

Vector2f& Vector2f::operator/=(float scalar) {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");
    x /= scalar;
    y /= scalar;

    return *this;
}
}