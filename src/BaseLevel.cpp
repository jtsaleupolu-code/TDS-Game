#include <BaseLevel.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void BaseLevel::Load(const std::string &filename) {

    // get csv file and open
    std::ifstream file(filename); //  "./assets/BasicTileMap.csv"

    // need to catch exception for file not found
    // csv may not be loading properly
    printf("filename: %s\n", filename);
    if (!file.is_open()) {printf("csv did not open\n");}

    // set tilemap to 0 and clear
    //tilemap.tiles.clear();
    tilemap.setWidth(0);
    tilemap.setHeight(0);

    std::string line;
    std::vector<int> newTiles;

    // loop through csv and insert values into vector
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        //printf("%s", line);
        std::string cell;
        int currentWidth = 0;
        while(std::getline(ss, cell, ',')) {
            printf(" %i ", std::stoi(cell));
            newTiles.push_back(std::stoi(cell));
            
            currentWidth++;
        }
        if (tilemap.getWidth() == 0) {tilemap.setWidth(currentWidth);}

        tilemap.setHeight(tilemap.getHeight() + 1);
    }
    tilemap.setTiles(newTiles);

    printf("\n tilemapWidth: %i   tilemapHeight: %i \n", tilemap.getWidth(), tilemap.getHeight());


}

void BaseLevel::Update(float dt) {

}

// render tiles from level
void BaseLevel::Render(Camera& camera) {
    
    // get cameras position

    int startX = camera.getPosition().x / 32;
    int startY = camera.getPosition().y / 32;

    int endX = startX + (LOGICAL_W / 32) + 2; // +2 WINDOW_WIDTH
    int endY = startY + (LOGICAL_H / 32) + 2; // +2  WINDOW_HEIGHT

    int tileCount = 0;
    
    for (int y = startY; y < endY; y++) {
        for (int x = startX; x < endX; x++) {
            if (x < 0 || y < 0) {continue;}
            if (x >= tilemap.getWidth() || y >= tilemap.getHeight()) {continue;}
            //printf("StartX: %i   StartY: %i   endX: %i    endY: %i \n", startX, startY, endX, endY);
            //printf("y: %i  x: %i   width: %i \n", y, x, tilemap.getWidth());
            //printf("Just before renderTile: [%i] \n", (y * tilemap.getWidth() + x));
            
            int tileId;
            //tileId = tilemap.getTiles()[y * tilemap.getWidth() + x];
            tileId = tilemap.getTileValue(y * tilemap.getWidth() + x);
            //printf("tileId: %i \n", tileId);
            
            float screenX = x * 32 - camera.getPosition().x;
            float screenY = y * 32 - camera.getPosition().y;

            Vec2 pos = Vec2(screenX, screenY);
            
            // this render not working, might need to work on loading csv
            tilemap.getTileSet().RenderTile(tileId, pos);
            tileCount++;
            
        }
    }
    char totalTiles[200];
    sprintf(totalTiles, "Tiles rendered: %i", tileCount);
    drawText(10,30,totalTiles,255,255,255,255);
}