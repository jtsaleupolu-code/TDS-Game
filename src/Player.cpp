#include <Player.h>
#include <iostream>
//Player::Player() {};

void Player::setTrans(Transform transform) {this->transform = transform;}
void Player::setTrans(float angle) {this->transform.localAngle = angle;}
void Player::setTex(Texture texture) {this->tex = texture;}
void Player::setVel(Vec2 velocity) {this->velocity = velocity;}
void Player::setTargetAngle(float targetAngle) {this->targetAngle = targetAngle;}

void Player::setWorldPos(Vec2 pos) {this->WorldPosition = pos;}


void Player::renderPlayer(Camera cam) {
    Vec2 ScreenPos;
    ScreenPos.x = WorldPosition.x - cam.getPosition().x;
    ScreenPos.y = WorldPosition.y - cam.getPosition().y;
    //drawTexture(tex, getTrans().localPosition - getTrans().localScale/2, getTrans().localScale, getTrans().localAngle);
    drawTexture(tex, ScreenPos, getTrans().localScale, getTrans().localAngle);
}

void Player::playerController(float dt) {

    Vec2 mxy = mousePosition();

    mxy.x *= scaleX;  //scaleX
    mxy.y *= scaleY;  //scaleY
    printf("WorldPos of player: %d\n", WorldPosition);
    Vec2 forward = mxy - getTrans().localPosition; // WorldPosition;//
    float targetAngle = atan2(forward.y, forward.x)  * 180.0f / M_PI; 

    setTrans(targetAngle);
}
