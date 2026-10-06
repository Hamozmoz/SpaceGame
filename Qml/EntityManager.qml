import QtQuick
import Game.Manager
import Game
Repeater {
model : GameManager.entityManager
delegate:
Rectangle{
x : model.x
y : model.y
width: model.width
height: model.height
color : model.EntityType === Enums.Obstacle?"red" : "black"
}
}
