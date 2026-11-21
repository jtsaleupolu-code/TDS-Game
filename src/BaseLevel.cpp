#include <BaseLevel.h>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

void BaseLevel::Load(const std::string& filename) {

    // get csv file and open
    std::ifstream file(filename);

    // need to catch exception for file not found
    //if (!file.is_open) {return;}

    // set tilemap to 0 and clear
    //tilemap.tiles.clear();
    tilemap.setWidth(0);
    tilemap.setHeight(0);

    std::string line;
    std::vector<int> newTiles;

    // loop through csv and insert values into vector
    while (std::getline(file, line)) {
        std::stringstream ss(line);
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
    
}