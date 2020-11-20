#include "JemPCH.h"
#include "Collision.h"

#include <Renderer/Renderer.h>

namespace Jem {

namespace Collision {

    // ==================
    // Jem::Collision::RotatePoint
    // 
    //     Rotate one point around another. Angles are in degrees.
    //
    // ==================
    Vector2d RotatePoint(Vector2d point, double angle, const Vector2d& center) {
        Vector2d rotatedPoint;

        point.x -= center.x;
        point.y -= center.y;

        rotatedPoint.x = cos(angle * 3.14 / 180) * point.x - sin(angle * 3.14 / 180) * point.y; // TODO: Fix degrees to radians
        rotatedPoint.y = sin(angle * 3.14 / 180) * point.x + cos(angle * 3.14 / 180) * point.y;

        rotatedPoint.x += center.x;
        rotatedPoint.y += center.y;

        return rotatedPoint;
    }

    // ==================
    // Jem::Collision::CreateAABBFromCollisionRect
    // ==================
    AABB CreateAABBFromCollisionRect(const CollisionRect& rect) {
        AABB aabb;
        aabb.min = rect.position;
        aabb.max = rect.size;

        return aabb;
    }

    // ==================
    // Jem::Collision::CreatePolyFromCollisionRect
    // ==================
    Poly CreatePolyFromCollisionRect(const CollisionRect& rect) {
        Vector2d center;
        center.x = rect.position.x + rect.size.x * rect.center.x;
        center.y = rect.position.y + rect.size.y * rect.center.y;

        Poly poly;
        poly.position = center;
        poly.positions[0] = RotatePoint(rect.position, rect.rotation, center);
        poly.positions[3] = RotatePoint({ rect.position.x + rect.size.x, rect.position.y }, rect.rotation, center);
        poly.positions[1] = RotatePoint({ rect.position.x, rect.position.y + rect.size.y }, rect.rotation, center);
        poly.positions[2] = RotatePoint({ rect.position.x + rect.size.x, rect.position.y + rect.size.y }, rect.rotation, center);

        return poly;
    }
    
    // ==================
    // Jem::Collision::AABBVsAABB
    //
    //     Returns true if the two AABBs are overlapping.
    //
    // ==================
    bool AABBVsAABB(const AABB& aabb1, const AABB& aabb2) {
        return (aabb1.min.x < aabb2.min.x + aabb2.max.x
             && aabb1.min.x + aabb1.max.x > aabb2.min.x
             && aabb1.min.y < aabb2.min.y + aabb2.max.y
             && aabb1.min.y + aabb1.max.y > aabb2.min.y);
    }

    // ==================
    // Jem::Collision::CollisionPolyVsPoly
    //
    //     Returns true if the two polys are overlapping. Made using separated axis theorem.
    //
    // ==================
    bool PolyVsPoly(Poly& poly1, Poly& poly2) {
        // Debug lines
        //Renderer::DrawLine(poly1.positions[0], poly1.positions[1], { 255, 0, 0});
        //Renderer::DrawLine(poly1.positions[1], poly1.positions[2], { 255, 0, 0});
        //Renderer::DrawLine(poly1.positions[2], poly1.positions[3], { 255, 0, 0});
        //Renderer::DrawLine(poly1.positions[3], poly1.positions[0], { 255, 0, 0});

        //Renderer::DrawLine(poly2.positions[0], poly2.positions[1], { 255, 0, 0 });
        //Renderer::DrawLine(poly2.positions[1], poly2.positions[2], { 255, 0, 0 });
        //Renderer::DrawLine(poly2.positions[2], poly2.positions[3], { 255, 0, 0 });
        //Renderer::DrawLine(poly2.positions[3], poly2.positions[0], { 255, 0, 0 });

        Poly* first = &poly1;
        Poly* second = &poly2;

        // Try for both shapes.
        for (int shape = 0; shape < 2; shape++) {
            if (shape == 1) {
                first = &poly2;
                second = &poly1;
            }

            // Check each side.
            for (int a = 0; a < 4; a++) {
                int b = (a + 1) % 4;
                Vector2d axisProj = { -(first->positions[b].y - first->positions[a].y), first->positions[b].x - first->positions[a].x };
                float d = sqrtf(axisProj.x * axisProj.x + axisProj.y * axisProj.y);
                axisProj = { axisProj.x / d, axisProj.y / d };

                // Work out min and max 1D points for r1.
                float min_r1 = INFINITY, max_r1 = -INFINITY;
                for (int p = 0; p < 4; p++) {
                    float q = (first->positions[p].x * axisProj.x + first->positions[p].y * axisProj.y);
                    min_r1 = std::min(min_r1, q);
                    max_r1 = std::max(max_r1, q);
                }

                // Work out min and max 1D points for r2.
                float min_r2 = INFINITY, max_r2 = -INFINITY;
                for (int p = 0; p < 4; p++) {
                    float q = (second->positions[p].x * axisProj.x + second->positions[p].y * axisProj.y);
                    min_r2 = std::min(min_r2, q);
                    max_r2 = std::max(max_r2, q);
                }

                if (!(max_r2 >= min_r1 && max_r1 >= min_r2)) {
                    return false;
                }
            }
        }

        return true;
    }

    // ==================
    // Jem::Collision::RectVsRect
    // 
    //     Returns true if the two rects are overlapping.
    // ==================
    bool RectVsRect(const CollisionRect& rect1, const CollisionRect& rect2) {
        if (!rect1.rotation && !rect2.rotation) {
            // Not rotated, so use AABB.
            return AABBVsAABB(CreateAABBFromCollisionRect(rect1), CreateAABBFromCollisionRect(rect2));
        }
        else {
            // Rotated, so use polygons.
            return PolyVsPoly(CreatePolyFromCollisionRect(rect1), CreatePolyFromCollisionRect(rect2));
        }
    }
}

}
