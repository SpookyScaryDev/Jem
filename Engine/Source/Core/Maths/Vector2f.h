#pragma once

namespace Jem {

class Vector2f {
public:
                        Vector2f();                         // Initialises each element to 0;
                        Vector2f(float fx, float fy);

    float               x;
    float               y;

    void                Set(float fx, float fy);

    float               Magnitude() const;
    void                Normalise();
    float               Dot(const Vector2f& vector)       const;

    Vector2f&           operator=(const Vector2f& vector);

    Vector2f            operator+(const Vector2f& vector) const;
    Vector2f&           operator+=(const Vector2f& vector);

    Vector2f            operator-(const Vector2f& vector) const;
    Vector2f&           operator-=(const Vector2f& vector);

    Vector2f            operator*(const float scalar)     const;
    Vector2f&           operator*=(float scalar);

    Vector2f            operator/(const float scalar)     const;
    Vector2f&           operator/=(float scalar);
};
    
}
