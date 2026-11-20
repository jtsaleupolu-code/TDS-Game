#ifndef COLLISION_H_
#define COLLISION_H_

#include <engine.h>
#include <algorithm>

// Collision (Point-Circle)
bool collision(Vec2 pos0, Vec2 pos1, float radius1);

// Collision (Circle-Circle)
bool collision(Vec2 pos0, float radius0, Vec2 pos1, float radius1);

// Collision (Point-AABB)
bool collision(Vec2 pos0, Vec2 pos1, Vec2 size1);

// Collision (AABB-AABB)
bool collision(Vec2 pos0, Vec2 size0, Vec2 pos1, Vec2 size1);

// Collision (AABB-Circle)
bool collision(Vec2 pos0, float radius0, Vec2 pos1, Vec2 size1);

// Circle-Rectangle
bool collision(Vec2 pos0, float radius0, Vec2 pos1, Vec2 size1, float angle1);

// Collision (AABB-Rectangle)
// (Not to be used directly)
bool collisionAABBRectangle(Vec2 pos0, Vec2 size0, Vec2 pos1, Vec2 size1, float angle1);

// Collision (Point-Rectangle)
bool collision(Vec2 pos0, Vec2 pos1, Vec2 size1, float angle1);

// Collision (Rectangle-Rectangle)
bool collision(Vec2 pos0, Vec2 size0, float angle0, Vec2 pos1, Vec2 size1, float angle1);

#endif