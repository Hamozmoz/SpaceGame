import QtQuick
import Game
import Game.Manager
FocusScope {
id : inputHandlerRoot
focus : true
Keys.onPressed: (event)=>
{
if(event.key === Qt.Key_W || event.key === Qt.Key_Up){
 GameManager.inputManager.UpPressed = Enums.Pressed
 event.accepted = true;
}else if(event.key === Qt.Key_D || event.key === Qt.Key_Right){
GameManager.inputManager.RightPressed = Enums.Pressed
event.accepted = true;
}else if(event.key === Qt.Key_S || event.key === Qt.Key_Down){
GameManager.inputManager.DownPressed = Enums.Pressed
event.accepted = true;
}else if(event.key === Qt.Key_A || event.key === Qt.Key_Left){
GameManager.inputManager.LeftPressed = Enums.Pressed
event.accepted = true;
}
}

Keys.onReleased: (event)=>{
if(event.key === Qt.Key_W || event.key === Qt.Key_Up){
 GameManager.inputManager.UpPressed = Enums.NotPressed
 event.accepted = true;
}else if(event.key === Qt.Key_D || event.key === Qt.Key_Right){
GameManager.inputManager.RightPressed = Enums.NotPressed
event.accepted = true;
}else if(event.key === Qt.Key_S || event.key === Qt.Key_Down){
GameManager.inputManager.DownPressed = Enums.NotPressed
event.accepted = true;
}else if(event.key === Qt.Key_A || event.key === Qt.Key_Left){
GameManager.inputManager.LeftPressed = Enums.NotPressed
event.accepted = true;
}
}

}


