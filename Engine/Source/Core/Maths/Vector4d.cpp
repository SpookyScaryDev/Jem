#include "JemPCH.h"
#include "Vector4d.h"

namespace Jem {

// ==================
// Jem::Vector4d::Vector4d
// ==================
Vector4d::Vector4d(double dx, double dy, double dz, double dw) :
    x(dx), y(dy), z(dz), w(dw) {}

// ==================
// Jem::Vector4d::Set
// ==================
void Vector4d::Set(double dx, double dy, double dz, double dw) {
    x = dx;
    y = dy;
    z = dz;
    w = dw;
}

// ==================
// Jem::Vector4d::Magnitude
// ==================
double Vector4d::Magnitude() const {
    return sqrt((x * x) + (y * y) + (z * z) + (w * w));
}

// ==================
// Jem::Vector4d::Normalize
// ==================
void Vector4d::Normalize() {
    x /= Magnitude();
    y /= Magnitude();
    z /= Magnitude();
    w /= Magnitude();
}

// ==================
// Jem::Vector4d::Dot
// ==================
double Vector4d::Dot(const Vector4d& vector) const {
    return vector.x * x + vector.y * y + vector.z * z + vector.w * w;
}

// ==================
// Jem::Vector4d::operator+
// ==================
Vector4d Vector4d::operator+(const Vector4d& vector) const {
    return Vector4d(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
}

// ==================
// Jem::Vector4d::operator+=
// ==================
Vector4d& Vector4d::operator+=(const Vector4d& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;
    w += vector.w;

    return *this;
}

// ==================
// Jem::Vector4d::operator-
// ==================
Vector4d Vector4d::operator-(const Vector4d& vector) const {
    return Vector4d(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
}

// ==================
// Jem::Vector4d::operator-=
// ==================
Vector4d& Vector4d::operator-=(const Vector4d& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;
    w -= vector.w;

    return *this;
}

// ==================
// Jem::Vector4d::operator*
// ==================
Vector4d Vector4d::operator*(const double scalar) const {
    return Vector4d(x * scalar, y * scalar, z * scalar, w * scalar);
}

// ==================
// Jem::Vector4d::operator*=
// ==================
Vector4d& Vector4d::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;
    w *= scalar;

    return *this;
}

// ==================
// Jem::Vector4d::operator/
// ==================
Vector4d Vector4d::operator/(const double scalar) const {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");

    return Vector4d(x / scalar, y / scalar, z / scalar, w / scalar);
}

// ==================
// Jem::Vector4d::operator/=
// ==================
Vector4d& Vector4d::operator/=(double scalar) {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");
    x /= scalar;
    y /= scalar;
    z /= scalar;
    w /= scalar;

    return *this;
}
}