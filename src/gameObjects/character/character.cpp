#include <gameObjects/character/character.h>

Character::Character(std::string texLoc, std::string hitBox, std::string player) : super(texLoc) {
    std::cout << hitBox << " " << player << "\n";
    this->player = player;

}