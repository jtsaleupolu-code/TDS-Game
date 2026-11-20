#ifndef BASELEVEL_H_
#define BASELEVEL_H_


class BaseLevel {
    private:
        int width;
        int height;

        std::vector<int> tiles;
    public:

        BaseLevel() {};
        ~BaseLevel() {};

        int getWidth() {return width;}
        int getHeight() {return height;}
        std::vector<int> getTiles() {return tiles;}

        void setWidth(int w) : width(w) {};
        void setHeight(int h) : height(h) {};
        void setTiles(std::vector<int> t) : tiles(t) {};
};


#endif