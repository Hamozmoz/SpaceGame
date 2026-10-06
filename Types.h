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
enum EntityType : uint8_t{
NoType,
Player,
Obstacle
};
enum Activity : uint8_t{
Inactive,
Active
};
enum EntityId : uint8_t{
NoId,
};

Q_ENUM_NS(EntityType)
Q_ENUM_NS(ButtonState)
}



#endif // TYPES_H
