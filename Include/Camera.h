#ifndef CAMERA_H_
#define CAMERA_H_

#include <engine.h>
#include <iostream>

class Camera {

    private:
        Vec2 PosXY = Vec2(0,0);

    public:
        Vec2 getPosition() {return PosXY;}
        void setPosition(Vec2 pos) {this->PosXY = pos;}

        void Follow(Vec2 targetPos, float dt) {
            float targetCamX = targetPos.x - (LOGICAL_W/2);
            float targetCamY = targetPos.y - (LOGICAL_H/2);

            PosXY.x += (targetCamX - PosXY.x) * 5 * dt;
            PosXY.y += (targetCamY - PosXY.y) * 5 * dt;
            printf("POSXY: %d, %d \n", PosXY.x, PosXY.y);
        }
};



#endif