/*
    A scene

*/
#pragma once
#include <vector>


#include <utils/jsonReader.h>
#include <game.h>
#include <gameobject.h>
//#include <gameObjects/character/character.h>

namespace Game{
    class SF;
}

namespace Engine{

    class Scene{
        private:    
            std::string name, json;

            std::vector<Engine::GameObject*> gameObjects;
        public:
            bool loaded = false;
    
            Scene(std::string name); 

            Scene(std::string name, std::string sceneJson);

            // Actually load in the scene
            void load(Game::SF* game);

            // Deload everything
            void deload();
    
    
            // Add object into current scene
            void addObject(Engine::GameObject* object);

            // Get all objects in scene
            std::vector<Engine::GameObject*> getObjs();

            std::string getName(){return name;}
    };
}

// namespace UI{
//     class Text : public Engine::GameObject {
    
//     };
// }