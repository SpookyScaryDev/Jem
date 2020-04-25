#include "JemPCH.h"
#include "Vector3f.h"

namespace Jem {

Vector3f::Vector3f() :
    x(0.0f), y(0.0f), z(0.0f) {}

Vector3f::Vector3f(float fx, float fy, float fz) :
    x(fx), y(fy), z(fx){}

void Vector3f::Set(float fx, float fy, float fz) {
    x = fx;
    y = fy;
    z = fz;
}

float Vector3f::Magnitude() const {
    return sqrt((x * x) + (y * y) + (z * z));
}

void Vector3f::Normalise() {
    x /= Magnitude();
    y /= Magnitude();
    z /= Magnitude();
}

float Vector3f::Dot(const Vector3f& vector) const {
    return x * vector.x + vector.y * y + vector.z * z;
}

Vector3f& Vector3f::Cross(const Vector3f& vector) const {
    return Vector3f(y * vector.z - z * vector.y,
                    z * vector.x - x * vector.z,
                    x * vector.y - y * vector.x);
}

Vector3f& Vector3f::operator=(const Vector3f& vector) {
    x = vector.x;
    y = vector.y;
    y = vector.z;

    return *this;
}

Vector3f Vector3f::operator+(const Vector3f& vector) const {
    return Vector3f(x + vector.x, y + vector.y, z + vector.z);
}

Vector3f& Vector3f::operator+=(const Vector3f& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}

Vector3f Vector3f::operator-(const Vector3f& vector) const {
    return Vector3f(x - vector.x, y - vector.y, z - vector.z);
}

Vector3f& Vector3f::operator-=(const Vector3f& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}

Vector3f Vector3f::operator*(const float scalar) const {
    return Vector3f(x * scalar, y * scalar, z * scalar);
}

Vector3f& Vector3f::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Vector3f Vector3f::operator/(const float scalar) const {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");

    return Vector3f(x / scalar, y / scalar, z / scalar);
}

Vector3f& Vector3f::operator/=(float scalar) {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}
}