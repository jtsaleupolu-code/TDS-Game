#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include <vector>

#include <engine.h>

enum SPACE {GLOBAL, LOCAL};

class Transform {
    public:
    // 
    Transform();
    Transform(Transform *par, Vec2 pos, float angle, Vec2 scale=Vec2(1,1));

    Transform *parent;
    std::vector<Transform*> children;

    Vec2 localPosition;
    float localAngle;
    Vec2 localScale;

    void addChild(Transform *child);

    Vec2 up(SPACE space=GLOBAL);
    Vec2 right(SPACE space=GLOBAL);
    Vec2 position(SPACE space=GLOBAL);
    float angle(SPACE space=GLOBAL);
    Vec2 scale(SPACE space=GLOBAL);

    void translate(Vec2 t, SPACE space=LOCAL);
    void rotate(float angle, SPACE space=LOCAL);
    void scale(Vec2 s, SPACE space=LOCAL);
};

#endif //TRANSFORM_H_