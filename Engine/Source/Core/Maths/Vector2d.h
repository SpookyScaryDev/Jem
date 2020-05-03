#pragma once

namespace Jem {

// ===============================================================================
//
//     Simple 2 dimensional vector, using doubles.
//
// ===============================================================================
class Vector2d {
public:
                        Vector2d(double dx = 0.0, double dy = 0.0);

    void                Set(double dx, double dy);

    double              Magnitude() const;
    void                Normalize();
    double              Dot(const Vector2d& vector)       const;


    Vector2d            operator+(const Vector2d& vector) const;
    Vector2d&           operator+=(const Vector2d& vector);

    Vector2d            operator-(const Vector2d& vector) const;
    Vector2d&           operator-=(const Vector2d& vector);

    Vector2d            operator*(const double scalar)     const;
    Vector2d&           operator*=(double scalar);

    Vector2d            operator/(const double scalar)     const;
    Vector2d&           operator/=(double scalar);

    double              x;
    double              y;
};
    
}
