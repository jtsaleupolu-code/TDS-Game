#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <engine.h>
#include <vector>

class TileMap {
    private:
        int width;
        int height;

        std::vector<int> tiles;
    public:

        //BaseLevel() {};
        //~BaseLevel() {};

        int getWidth() {return width;}
        int getHeight() {return height;}
        std::vector<int> getTiles() {return tiles;}

        void setWidth(int w) {width = w;}
        void setHeight(int h) {height = h;}
        void setTiles(std::vector<int> t) {tiles = t;}
};

class TileSet {
    public:
        Texture *texture;
        std::vector<Texture> tileTex;
};


#endif