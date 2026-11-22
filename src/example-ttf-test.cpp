#include <engine.h>
#include <iostream>

#include <Player.h>
#include <Camera.h>
#include <BaseLevel.h>
#include <string>
using namespace std;

// Swansea TTF font
Font swansea;

Player p1;
Texture PlayerTex;
Camera camera;

Texture tempLevel;

BaseLevel level;




// Initialise (called once at start)
void init() {
    setWindowTitle("Massey - Font Test");


    try {
        Transform trans(nullptr, Vec2(0,0), 0.0f, Vec2(60, 40));  //LOGICAL_W/2, LOGICAL_H/2

        //p1.setTrans(trans);
        //hero.getTransform() = trans;

        printf("%f \n", p1.getTrans().localScale.x);
        PlayerTex = loadTexture("./assets/character/Top_Down_Survivor/rifle/move/survivor-move_rifle_0.png");
        
        //p1.setTex(PlayerTex);
        p1 = Player(trans, PlayerTex);
        p1.setWorldPos(Vec2(0,0));

        // load level
        /*levelTexture = loadTexture("./assets/Levels/tempLevel.png");
        level.setTex(levelTexture);
        level.getTransform().localScale = Vec2(1920, 1080);
        start = getTimeInSeconds();*/

    } catch (const char* msg) {std::cout << "Error: " << msg;}

    Texture levelTex = loadTexture("./assets/tempTiles.png");

    level.tilemap.setTileSet(levelTex);
    level.Load("./assets/BasicTileMap.csv");

    tempLevel = loadTexture("./assets/tempLevel.png");

    swansea = loadFont("./assets/fonts/Swansea.ttf");
}

// Update Game
void update(float dt) {
    // update player rotation -- shooting
    p1.playerController(dt);

    camera.Follow(p1.getWorldPos(), dt);

    // update level -- traversal
    // need to sort out tile mapping
    
}

// Render Game
void render(float lag) {
    clear(0,0,0);

    // render level
    //drawTexture(tempLevel, Rect{0,0,1000,1000}, Rect{10, 10, 1000, 1000}, 0.0f, 255);
    level.Render(camera);

    // render player
    p1.renderPlayer(camera);


    /*drawText(50, 50, "Testing", 255, 0, 0, 255, swansea, 15);
    drawText(50, 250, "Test2", 0, 128, 0, 255, swansea, 30);
    drawText(50, 450, "Test3", 0, 0, 0, 255, swansea, 60, getTimeInSeconds() * 180.0f);
    drawText(250, 50, "Test4", 255, 0, 0, 255, swansea, 15);
    drawText(450, 50, "Test5", 64, 0, 64, 255, swansea, 15);
    char timer[200];
    sprintf(timer, "time: %f", getTimeInSeconds());
    drawText(50, 150, timer, 64, 0, 64, 255, swansea, 15);*/

    char pos[200];
    sprintf(pos, "PlayerPosition   : %f %f", p1.getWorldPos().x, p1.getWorldPos().y);
    drawText(10, 10, pos, 255, 255, 255, 255);
    char camPos[200];
    sprintf(camPos, "CamPosition      : %f %f", camera.getPosition().x, camera.getPosition().y);
    drawText(10, 20, camPos, 255,255,255,255);
}

// Close the Game
void close() {

}