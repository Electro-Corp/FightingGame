/*
*/
#include <game.h>

static int segfaults = 0;

Game::SF::SF(){
    this->renderer = new Rendering::Renderer(std::string(GAME_NAME), 800, 600, this);
    scriptMan = new Scripting::ScriptManager("../assets/scripts", renderer, this);

    #ifdef __linux__
    signal(SIGINT, endGame);
    signal(SIGSEGV, segFault);
    signal(SIGABRT, endGame);
    signal(SIGKILL, endGame);
    #endif
    
    std::cout << GAME_NAME << "\n";
}

/**
 * Load script for a gameObject
*/
void Game::SF::loadScript(Engine::GameObject* obj, std::string path){
    this->scriptMan->loadScriptForObject(obj, path);
}

void Game::SF::initScripts(){
    this->scriptMan->initScripts();
}

void Game::SF::tick(Engine::Scene* scene){
    this->renderer->update(scene);
}

float Game::SF::getTime(){
    return this->renderer->getDeltaTime();
}

float Game::SF::getDelta(){
    return this->renderer->getDelta();
}

void Game::SF::changeWindowTitle(std::string title){
    this->renderer->changeTitle(title);
}

lua_State* Game::SF::getLuaState(){
    return scriptMan->getLuaState();
}

void Game::SF::mainMenuLoop(){
    //tick(mainMenu);
}

void Game::SF::tick(){
    // TODO: SWITCH STATMENT
    //this->renderer->update(*mainMenu);
    if(scenes[tickNum]->loaded){
        if(deloading){
            deloading = false;
            printf("Ticking %d\n", tickNum);
        }else{
            this->renderer->update((scenes[tickNum]).get());
        }
    }
}

void Game::SF::setTickNum(int num){
    if(tickNum != -1){
        printf("Deload scene %d\n", tickNum);
        //while(this->renderer->rendering){}
        deloading = true;
        scenes[tickNum]->deload();
        printf("Deload is %d\n", scenes[tickNum]->loaded);
    }
    this->tickNum = num;
    printf("Load scene %d\n", num);
    scenes[tickNum]->load(this);
}


void Game::SF::endGame(int s){
    // Confirm
    // Exit
    // Print bye bye
    std::cout << "Cleaning up..\n";
    // clean up
    std::cout << "Exiting " << GAME_NAME << ". Loser.\n";
    exit(1);
}

void Game::SF::segFault(int s){
    segfaults++;
    if(segfaults < 5){
        std::cout << "Segmentation fault (" << segfaults << ")! Attempting to continue game...\n";
    }else{
        std::cout << "Too many segfaults! Clearly this situation is unrecoverable. Exiting game.\n";
        endGame(-1);
    }
}