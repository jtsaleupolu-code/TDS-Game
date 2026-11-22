#ifndef PLAYER_H_
#define PLAYER_H_

#include <engine.h>
#include <transform.h>
#include <collision.h>
#include <Camera.h>
#include <vector>


class Player {
    private:
        Transform transform;
        Vec2 WorldPosition;
        Vec2 velocity;
        float speed = 100;

        float targetAngle;
        Texture tex;

        // Bullets owned by player vector

    public:
        Player(Transform transform, Texture texture) : transform(transform), tex(texture) {};
        Player() {};
        ~Player() {};

        // getters
        Transform getTrans() {return transform;}
        Texture getTex() {return tex;}
        Vec2 getVel() {return velocity;}
        float gettargetAngle() {return targetAngle;}

        Vec2 getWorldPos() {return WorldPosition;}
        float getSpeed() {return speed;}
        // setters
        void setTrans(Transform transform);
        void setTrans(float angle);
        void setTex(Texture texture);
        void setVel(Vec2 velocity);
        void setTargetAngle(float targetAngle);

        void setWorldPos(Vec2 pos);
        // functions
        void renderPlayer(Camera cam);
        void playerController(float dt);


};

#endif