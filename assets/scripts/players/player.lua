-- Player control file

-- Variables
x = 0
y = 0

function init(player)

end

function update(player)

end

function onKeyPressed(player, key)
    if key == 'd' then
        player.transform.position.x = player.transform.position.x + 10
    end
    if key == 'a' then
        player.transform.position.x = player.transform.position.x - 10
    end
end