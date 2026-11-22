#ifndef TILEMAP_H_
#define TILEMAP_H_

#include <engine.h>
#include <vector>
#include <iostream>


class TileSet {
    public:
        Texture *texture;
        std::vector<Texture> tileTex;

        void RenderTile(int id, Vec2 pos) {
            printf("In rendertile \n");
            switch(id) {
                case 1:
                    drawTexture(tileTex[0], pos, Vec2(32,32), 0);
                    break;
                case 2:
                    drawTexture(tileTex[1], pos, Vec2(32,32), 0);
                    break;
                case 3:
                    drawTexture(tileTex[2], pos, Vec2(32,32), 0);
                    break;
            }
        }

        void LoadTiles(Texture &texture) {
            Texture floor = subTexture(texture, {0,0,32,32});
            tileTex.push_back(floor);
            Texture floor0 = subTexture(texture, {32,0,32,32});
            tileTex.push_back(floor0);
            Texture floor1 = subTexture(texture, {64,0,32,32});
            tileTex.push_back(floor1);
        }

        
};


class TileMap {
    private:
        int width;
        int height;

        TileSet tileSet;

        std::vector<int> tiles;
    public:

        //BaseLevel() {};
        //~BaseLevel() {};

        int getWidth() {return width;}
        int getHeight() {return height;}
        std::vector<int> getTiles() {return tiles;}
        TileSet getTileSet() {return tileSet;}

        void setTileSet(Texture texture) {tileSet.LoadTiles(texture);}

        void setWidth(int w) {width = w;}
        void setHeight(int h) {height = h;}
        void setTiles(std::vector<int> t) {tiles = t;}
};




#endif