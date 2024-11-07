-- Player control file

-- Variables
x = 0
y = 0

space = false
jump = false
goDown = false
inAir = false

SDL_SCANCODE_A = 4
SDL_SCANCODE_B = 5
SDL_SCANCODE_C = 6
SDL_SCANCODE_D = 7
SDL_SCANCODE_E = 8
SDL_SCANCODE_F = 9
SDL_SCANCODE_G = 10
SDL_SCANCODE_H = 11
SDL_SCANCODE_I = 12
SDL_SCANCODE_J = 13
SDL_SCANCODE_K = 14
SDL_SCANCODE_L = 15
SDL_SCANCODE_M = 16
SDL_SCANCODE_N = 17
SDL_SCANCODE_O = 18
SDL_SCANCODE_P = 19
SDL_SCANCODE_Q = 20
SDL_SCANCODE_R = 21
SDL_SCANCODE_S = 22
SDL_SCANCODE_T = 23
SDL_SCANCODE_U = 24
SDL_SCANCODE_V = 25
SDL_SCANCODE_W = 26
SDL_SCANCODE_X = 27
SDL_SCANCODE_Y = 28
SDL_SCANCODE_Z = 29
SDL_SCANCODE_SPACE = 44

count = 0

initialPosY = 0

jumpHeight = 10
jumpSpeed = 12
gravity = 9.8 

function init(player)
    initialPosY = player.transform.position.y
end

vel = 0
maxVel = 15
acceL = 5


yVel = 0

function update(player)
    
    if(Graphics:getKeyboardState()[SDL_SCANCODE_D] == 1) then
        if vel < maxVel then
            vel = vel + acceL
        end
    elseif (Graphics:getKeyboardState()[SDL_SCANCODE_A] == 1) then
        if vel > maxVel * -1 then
            vel = vel - acceL
        end
    else
        if vel > 0 then
            vel = vel - acceL
        elseif vel < 0 then
            vel = vel + acceL
        end
    end

    -- if(Graphics:getKeyboardState()[SDL_SCANCODE_S] == 1) then
    --     player.transform.scale.y = 200
    --     player.transform.position.y = 400
    --     initialPosY = player.transform.position.y 
    -- else
    --     player.transform.scale.y = 400
    --     player.transform.position.y = 200.
    --     initialPosY = player.transform.position.y 
    -- end


    if Graphics:getKeyboardState()[SDL_SCANCODE_W] == 1 and inAir == false and space == false and jump == false and goDown == false then
        space = true
        jump = true
        count = 0
        yVel = -20
    elseif Graphics:getKeyboardState()[SDL_SCANCODE_W] == 0 then
        space = false
    end

    -- if jump == true then
    --     yVel = yVel - 2
    --     if yVel < -15 then
    --         jump = false
    --         space = true
    --     end
    --     inAir = true
    --else
    

    player.transform.position.x = player.transform.position.x + vel
    player.transform.position.y = player.transform.position.y + yVel

    if player.transform.position.y < initialPosY then
        yVel = yVel + 2
        inAir = true
    else
        yVel = 0
        inAir = false
        space = false
        jump = false
    end

end

function onKeyPressed(player, key, keys)
    
end