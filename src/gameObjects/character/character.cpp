#include <gameObjects/character/character.h>

Character::Character(std::string texLoc, std::string hitBox) : super(texLoc) {
    std::cout << hitBox << "\n";
    
}