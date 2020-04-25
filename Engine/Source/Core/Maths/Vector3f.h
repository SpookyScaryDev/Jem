#pragma once

namespace Jem {

class Vector3f {
public:
                        Vector3f();                         // Initialises each element to 0;
                        Vector3f(float fx, float fy, float fz);

    float               x;
    float               y;
    float               z;

    void                Set(float fx, float fy, float fz);

    float               Magnitude() const;
    void                Normalise();
    float               Dot(const Vector3f& vector)       const;
    Vector3f&           Cross(const Vector3f& vector)     const;

    Vector3f&           operator=(const Vector3f& vector);

    Vector3f            operator+(const Vector3f& vector) const;
    Vector3f&           operator+=(const Vector3f& vector);

    Vector3f            operator-(const Vector3f& vector) const;
    Vector3f&           operator-=(const Vector3f& vector);

    Vector3f            operator*(const float scalar)     const;
    Vector3f&           operator*=(float scalar);

    Vector3f            operator/(const float scalar)     const;
    Vector3f&           operator/=(float scalar);
};
    
}
