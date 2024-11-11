#include <gameObjects/character/character.h>

Character::Character(std::string texLoc, std::string hitBox, std::string player) : super(texLoc) {
    this->playerChar = player;
    std::cout << hitBox << " " << playerChar << "\n";

    // Load hitbox
    JsonReader reader(hitBox);
    Json::Value val = reader.read();

    int c;
    for(auto& hitData : val["hitboxes"]){
        std::string uniq = hitData["Name"].asString();
        
        HitBox* hitBox = new HitBox();
        hitBox->name = uniq;
        
        for(auto& frame : hitData["Frames"]){
            FRAME tmp;
            for(auto& boxes : frame["Boxes"]){
                RECT box;
                box.x = boxes["x"].asInt();
                box.y = boxes["y"].asInt();
                box.w = boxes["w"].asInt();
                box.h = boxes["h"].asInt();

                tmp.hbs.push_back(box);
            }

            tmp.frameSkip = frame["SkipFrames"].asInt();

            hitBox->frames.push_back(tmp);

        }

        hitBoxes.push_back(hitBox);

    }

}

void Character::initScript(){
    if(this->script){
        this->script->initfunc(this);
    };
}

void Character::loadHitBox(std::string name){
    for(int i = 0; i < hitBoxes.size(); i++){
        if(hitBoxes[i]->name.find(name) != std::string::npos){
            currentHitBox = i;
            return;
        }
    }
}

void Character::loadHitBoxNum(int num){
    currentHitBox = num;
}

void Character::update(){
#if USE_SFML
    // Update text transformation
    this->text.setPosition(
        sf::Vector2f(
            this->transform.position.x,
            this->transform.position.y
        )
    );
    this->text.setScale(
        sf::Vector2f(
            this->transform.scale.x,
            this->transform.scale.y
        )
    );
    this->text.setRotation(
        this->transform.angle
    );
#endif
#if USE_SDL
    texture_rect.x = this->transform.position.x; 
    texture_rect.y = this->transform.position.y;
    texture_rect.w = this->transform.scale.x;
    texture_rect.h = this->transform.scale.y;
#endif
    // run scripts
    //updateScript();
    if(this->script){
        this->script->update(this);
    }
}

void Character::draw(SDL_Renderer* window){
    // Original can run now
    if(drawable){
        // Massive optimization
        if(this->getSprite()->SD_texture == nullptr){
            SDL_Texture* tex = SDL_CreateTextureFromSurface(window, this->getSprite()->getSurface());
            if(!tex){
                printf("Failed to create texture from surface!\n");
                std::cout << SDL_GetError() << "\n";
                exit(-1);
            }
            this->getSprite()->SD_texture = tex;
        }
        // Micro optimization (not even sure if this is even necessary)
        if(this->transform.angle == 0) {
            // If the angle is 0, we can just draw the texture directly
            SDL_RenderCopy(window, this->getSprite()->SD_texture, NULL, &texture_rect); 
        }else{
            // Otherwise, we need to rotate the texture
            SDL_RenderCopyEx(window, this->getSprite()->SD_texture, NULL, &texture_rect, this->transform.angle, NULL, SDL_FLIP_NONE);
        }
    }

    // Draw rect 
    if(currentHitBox != -1){
        for(auto& rect : hitBoxes[currentHitBox]->frames[0].hbs){
            SDL_Rect drawRect;
            drawRect.x = rect.x + this->transform.position.x;
            drawRect.y = rect.y + this->transform.position.y;
            drawRect.w = rect.w;
            drawRect.h = rect.h;
            SDL_SetRenderDrawColor(window, 255, 0, 0, 255);
            SDL_RenderDrawRect(window, &drawRect);
        }
    }
}