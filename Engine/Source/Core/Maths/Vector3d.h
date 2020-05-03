#pragma once

namespace Jem {

// ===============================================================================
//
//     Simple 3 dimensional vector, using doubles.
//
// ===============================================================================
class Vector3d {
public:
                        Vector3d(double fx = 0.0, double fy = 0.0, double fz = 0.0);

    void                Set(double dx, double dy, double dz);

    double              Magnitude() const;
    void                Normalize();
    double              Dot(const Vector3d& vector)        const;
    Vector3d&           Cross(const Vector3d& vector)      const;

    Vector3d            operator+(const Vector3d& vector)  const;
    Vector3d&           operator+=(const Vector3d& vector);

    Vector3d            operator-(const Vector3d& vector)  const;
    Vector3d&           operator-=(const Vector3d& vector);

    Vector3d            operator*(const double scalar)     const;
    Vector3d&           operator*=(double scalar);

    Vector3d            operator/(const double scalar)     const;
    Vector3d&           operator/=(double scalar);

    double              x;
    double              y;
    double              z;
};
    
}
