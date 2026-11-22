#ifndef BASELEVEL_H_
#define BASELEVEL_H_

#include <TileMap.h>
#include <Camera.h>

/*
So far level is just a tile map but
we can probably add other info like spawn points,
enemy spawns and some other data
*/
class BaseLevel {

    public:
        TileMap tilemap;

        void Load(const std::string &filename);
        void Update(float dt);
        void Render(Camera& camera);
};

#endif