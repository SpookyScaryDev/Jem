#include "JemPCH.h"
#include "Vector3d.h"

namespace Jem {

// ==================
// Jem::Vector3d::Vector3d
// ==================
Vector3d::Vector3d(double dx, double dy, double dz) :
    x(dx), y(dy), z(dz){}

// ==================
// Jem::Vector3d::Set
// ==================
void Vector3d::Set(double dx, double dy, double dz) {
    x = dx;
    y = dy;
    z = dz;
}

// ==================
// Jem::Vector3d::Magnitude
// ==================
double Vector3d::Magnitude() const {
    return sqrt((x * x) + (y * y) + (z * z));
}

// ==================
// Jem::Vector3d::Normalize
// ==================
void Vector3d::Normalize() {
    x /= Magnitude();
    y /= Magnitude();
    z /= Magnitude();
}

// ==================
// Jem::Vector3d::Dot
// ==================
double Vector3d::Dot(const Vector3d& vector) const {
    return vector.x * x + vector.y * y + vector.z * z;
}

// ==================
// Jem::Vector3d::Cross
// ==================
Vector3d& Vector3d::Cross(const Vector3d& vector) const {
    return Vector3d(y * vector.z - z * vector.y,
                    z * vector.x - x * vector.z,
                    x * vector.y - y * vector.x);
}

// ==================
// Jem::Vector3d::operator+
// ==================
Vector3d Vector3d::operator+(const Vector3d& vector) const {
    return Vector3d(x + vector.x, y + vector.y, z + vector.z);
}

// ==================
// Jem::Vector3d::operator+=
// ==================
Vector3d& Vector3d::operator+=(const Vector3d& vector) {
    x += vector.x;
    y += vector.y;
    z += vector.z;

    return *this;
}

// ==================
// Jem::Vector3d::operator-
// ==================
Vector3d Vector3d::operator-(const Vector3d& vector) const {
    return Vector3d(x - vector.x, y - vector.y, z - vector.z);
}

// ==================
// Jem::Vector3d::operator-=
// ==================
Vector3d& Vector3d::operator-=(const Vector3d& vector) {
    x -= vector.x;
    y -= vector.y;
    z -= vector.z;

    return *this;
}

// ==================
// Jem::Vector3d::operator*
// ==================
Vector3d Vector3d::operator*(const double scalar) const {
    return Vector3d(x * scalar, y * scalar, z * scalar);
}

// ==================
// Jem::Vector3d::operator*=
// ==================
Vector3d& Vector3d::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

// ==================
// Jem::Vector3d::operator/
// ==================
Vector3d Vector3d::operator/(const double scalar) const {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");

    return Vector3d(x / scalar, y / scalar, z / scalar);
}

// ==================
// Jem::Vector3d::operator/=
// ==================
Vector3d& Vector3d::operator/=(double scalar) {
    JEM_CORE_ASSERT(scalar != 0, "Tried to divide a vector by 0!");
    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}
}