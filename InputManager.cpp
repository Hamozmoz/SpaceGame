#include "InputManager.h"

InputManager::InputManager() {}

void InputManager::WriteUpPressed(Enums::ButtonState val){
    if(val != UpPressed)
        UpPressed = val;
    UpPressedChanged();
}



void InputManager::WriteDownPressed(Enums::ButtonState val)
{
    if(val != DownPressed){
        DownPressed = val;
        DownPressedChanged();
    }
}

void InputManager::WriteRightPressed(Enums::ButtonState val){
    if(val != RightPressed){
        RightPressed = val;
        RightPressedChanged();
    }
}

void InputManager::WriteLeftPressed(Enums::ButtonState val){
    if(LeftPressed != val){
        LeftPressed = val;
        LeftPressedChanged();
    }
}

Enums::ButtonState InputManager::ReadUpPressed()
{
    return UpPressed;
}

Enums::ButtonState InputManager::ReadDownPressed(){
    return DownPressed;
}

Enums::ButtonState InputManager::ReadRightPressed()
{
    return RightPressed;
}

Enums::ButtonState InputManager::ReadLeftPressed(){
    return LeftPressed;
}
