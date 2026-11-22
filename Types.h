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
Enemy,
Obstacle,
PlayerProjectile,
EnemyProjectile
};
enum Activity : uint8_t{
Inactive,
Active
};
enum EntityId : uint8_t{
NoId,
PlayerId,
SpaceRockId,
SpaceBoltId
};
enum EntityState : uint8_t
{
NoState,
Seeking,
Attacking
};

enum GameState : uint8_t{
OpeningScreen,
GameRunning,
GamePaused,
};
Q_ENUM_NS(GameState)
Q_ENUM_NS(EntityType)
Q_ENUM_NS(EntityId)
Q_ENUM_NS(ButtonState)
Q_ENUM_NS(Activity)
Q_ENUM_NS(EntityState)
}



#endif // TYPES_H
