#ifndef ANIMATION_H_
#define ANIMATION_H_

#include <engine.h>

typedef struct Timer {
    float elasped, interval, start;
    int presses;
    bool active, isCooldown;
} Timer;

typedef struct Animation {
    std::vector<Texture> frames;
    int no_frames;
    float duration;
    bool loop;
    Timer time;
} Animation;





#endif