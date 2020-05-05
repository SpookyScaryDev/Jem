#pragma once

namespace Jem {

// ===============================================================================
//
//     Simple 4 dimensional vector, using doubles.
//
// ===============================================================================
class Vector4d {
public:
                        Vector4d(double dx = 0.0, double dy = 0.0, double dz = 0.0, double dw = 0.0);

    void                Set(double dx, double dy, double dz, double dw);

    double              Magnitude() const;
    void                Normalize();
    double              Dot(const Vector4d& vector)        const;

    Vector4d            operator+(const Vector4d& vector)  const;
    Vector4d&           operator+=(const Vector4d& vector);

    Vector4d            operator-(const Vector4d& vector)  const;
    Vector4d&           operator-=(const Vector4d& vector);

    Vector4d            operator*(const double scalar)     const;
    Vector4d&           operator*=(double scalar);

    Vector4d            operator/(const double scalar)     const;
    Vector4d&           operator/=(double scalar);

    double              x;
    double              y;
    double              z;
    double              w;
};
    
}
