#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <QObject>
#include "Types.h"
class InputManager : public QObject
{
Q_OBJECT
Q_PROPERTY(Enums::ButtonState UpPressed READ ReadUpPressed WRITE WriteUpPressed NOTIFY UpPressedChanged)
Q_PROPERTY(Enums::ButtonState DownPressed READ ReadDownPressed WRITE WriteDownPressed NOTIFY DownPressedChanged)
Q_PROPERTY(Enums::ButtonState RightPressed READ ReadRightPressed WRITE WriteRightPressed NOTIFY RightPressedChanged)
Q_PROPERTY(Enums::ButtonState LeftPressed READ ReadLeftPressed WRITE WriteLeftPressed NOTIFY LeftPressedChanged)
Q_PROPERTY(Enums::ButtonState XPressed READ ReadXPressed WRITE WriteXPressed NOTIFY XPressedChanged)
public:
InputManager();
Enums::ButtonState UpPressed = Enums::NotPressed;
Enums::ButtonState DownPressed = Enums::NotPressed;
Enums::ButtonState RightPressed = Enums::NotPressed;
Enums::ButtonState LeftPressed = Enums::NotPressed;
Enums::ButtonState XPressed = Enums::NotPressed;
void WriteUpPressed(Enums::ButtonState val);
void WriteDownPressed(Enums::ButtonState val);
void WriteRightPressed(Enums::ButtonState val);
void WriteLeftPressed(Enums::ButtonState val);
void WriteXPressed(Enums::ButtonState val);
Enums::ButtonState ReadUpPressed();
Enums::ButtonState ReadDownPressed();
Enums::ButtonState ReadRightPressed();
Enums::ButtonState ReadLeftPressed();
Enums::ButtonState ReadXPressed();
signals:
void UpPressedChanged();
void DownPressedChanged();
void RightPressedChanged();
void LeftPressedChanged();
void XPressedChanged();
private:
};

#endif // INPUTMANAGER_H
