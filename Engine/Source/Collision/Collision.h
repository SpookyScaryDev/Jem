#pragma once
#include <Core/Maths/Vector2d.h>
#include <Collision/AABB.h>
#include <Collision/CollisionRect.h>
#include <Collision/CollisionPoly.h>

namespace Jem {

namespace Collision {
    bool        RectVsRect(const CollisionRect& rect1, const CollisionRect& rect2);
    bool        AABBVsAABB(const AABB& aabb1, AABB& aabb2);
    bool        PolyVsPoly(Poly& poly1, Poly& poly2);

    AABB        CreateAABBFromCollisionRect(const CollisionRect& rect);
    Poly        CreatePolyFromCollisionRect(const CollisionRect& rect);
    Vector2d    RotatePoint(const Vector2d point, double angle, const Vector2d& center);
}

}
