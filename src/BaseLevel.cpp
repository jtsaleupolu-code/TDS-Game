#include <BaseLevel.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void BaseLevel::Load(const std::string &filename) {

    // get csv file and open
    std::ifstream file(filename);

    // need to catch exception for file not found
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
        printf("%s", line);
        std::string cell;
        int currentWidth = 0;
        while(std::getline(ss, cell, ',')) {
            newTiles.push_back(std::stoi(cell));
            
            currentWidth++;
        }
        if (tilemap.getWidth() == 0) {tilemap.setWidth(currentWidth);}

        tilemap.setHeight(tilemap.getHeight() + 1);
    }


}

void BaseLevel::Update(float dt) {

}

// render tiles from level
void BaseLevel::Render(Camera& camera) {
    
    // get cameras position

    int startX = camera.getPosition().x / 32;
    int startY = camera.getPosition().y / 32;

    int endX = startX + (WINDOW_WIDTH / 32); // +2
    int endY = startY + (WINDOW_HEIGHT / 32); // +2
    
    for (int y = startY; y < endY; y++) {
        for (int x = startX; x < endX; x++) {
            if (x < 0 || y < 0) {continue;}
            if (x >= tilemap.getWidth() || y >= tilemap.getHeight()) {continue;}
            

            int tileId = tilemap.getTiles()[y * tilemap.getWidth() + x];
            printf("Just before renderTile \n");
            float screenX = x * 32 - camera.getPosition().x;
            float screenY = y * 32 - camera.getPosition().y;

            Vec2 pos = Vec2(screenX, screenY);
            
            tilemap.getTileSet().RenderTile(tileId, pos);

            
        }
    }
}