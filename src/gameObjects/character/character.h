#ifndef CHAR_H
#define CHAR_H
#include <gameobject.h>
#include <utils/jsonReader.h>

#include <string>


typedef struct {
    int x, y, w, h;
} RECT;

typedef struct{
    std::vector<RECT> hbs;
    int frameSkip;
} FRAME;

class HitBox{
public:
    std::string name;
    std::vector<FRAME> frames;
};

class Character : public Engine::GameObject{
private:
    typedef Engine::GameObject super;
    std::vector<HitBox*> hitBoxes;

    int currentHitBox = -1;
public:
    std::string playerChar;

    Character(std::string, std::string hitboxDat, std::string);

    void update() override;

    void loadHitBox(std::string name);
    void loadHitBoxNum(int num);

    void initScript() override;

#if USE_SDL
    void draw(SDL_Renderer* window) override;
#endif

};
#endif