-- Player control file

-- Variables
x = 0
y = 0

space = false
jump = false
goDown = false

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

function init(player)

end

function update(player)

    if(Graphics:getKeyboardState()[SDL_SCANCODE_D] == 1) then
        player.transform.position.x = player.transform.position.x + 10
    end

    if(Graphics:getKeyboardState()[SDL_SCANCODE_A] == 1) then
        player.transform.position.x = player.transform.position.x - 10
    end

    if Graphics:getKeyboardState()[SDL_SCANCODE_SPACE] == 1 and jump == false and goDown == false then
        space = true
        jump = true
        count = 0
    end
    if Graphics:getKeyboardState()[SDL_SCANCODE_SPACE] == 0 then
        space = false
    end

    if jump == true then
        player.transform.position.y = player.transform.position.y - (0.5 * 5.8 * (count * count))
        if count > 5 then 
            count = 0
            jump = false
            goDown = true
        end
        count = count + 1
    end

    if goDown == true then 
        player.transform.position.y = player.transform.position.y + (0.5 * 5.8 * (count * count))
        if count > 5 then 
            count = 0
            goDown = false
        end
        count = count + 1
    end

end

function onKeyPressed(player, key, keys)
    -- if key == 'd' then
    --     player.transform.position.x = player.transform.position.x + 10
    -- end
    -- if key == 'a' then
    --     player.transform.position.x = player.transform.position.x - 10
    -- end
    -- if key ~= ' ' then
    --     space = false
    -- end
    -- if key == ' '  and jump == false and goDown == false then
    --     space = true
    --     jump = true
    --     count = 0
    -- end
    -- print(space)
    -- print(jump)
    -- print(goDown)
    
end