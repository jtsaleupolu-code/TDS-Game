#include <Player.h>

//Player::Player() {};

void Player::setTrans(Transform transform) {this->transform = transform;}
void Player::setTrans(float angle) {this->transform.localAngle = angle;}
void Player::setTex(Texture texture) {this->tex = texture;}
void Player::setVel(Vec2 velocity) {this->velocity = velocity;}
void Player::setTargetAngle(float targetAngle) {this->targetAngle = targetAngle;}


void Player::renderPlayer() {
    drawTexture(tex, getTrans().localPosition - getTrans().localScale/2, getTrans().localScale, getTrans().localAngle);
}

void Player::playerController(float dt) {

    Vec2 mxy = mousePosition();

    mxy.x *= scaleX;  //scaleX
    mxy.y *= scaleY;  //scaleY

    Vec2 forward = mxy - getTrans().localPosition;
    float targetAngle = atan2(forward.y, forward.x)  * 180.0f / M_PI; 

    setTrans(targetAngle);
}
