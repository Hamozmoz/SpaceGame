import QtQuick
import Game.Manager
Repeater {
model : GameManager.entityManager
delegate:
Rectangle{
x : model.x
y : model.y
width: model.width
height: model.height
color : "black"
}
}
