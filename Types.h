#ifndef TYPES_H
#define TYPES_H
#include <qobjectdefs.h>
#include <qqmlintegration.h>
namespace Enums{
Q_NAMESPACE
QML_ELEMENT

enum ButtonState : uint8_t {
NotPressed = 0,
Pressed
};


Q_ENUM_NS(ButtonState)
}



#endif // TYPES_H
