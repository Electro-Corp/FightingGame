
function init(object)
  object.transform.scale.x = 45
  object.transform.scale.y = 50
end


function update(object)
  object.transform.position.x =  Graphics.mouseX - (object.transform.scale.x / 2)
  object.transform.position.y =  Graphics.mouseY - (object.transform.scale.y / 2)
end