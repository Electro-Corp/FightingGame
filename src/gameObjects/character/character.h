#ifndef CHAR_H
#define CHAR_H
#include <gameobject.h>


class Character : public Engine::GameObject{
private:
typedef Engine::GameObject super;
public:
    Character(std::string, std::string hitboxDat);

};
#endif