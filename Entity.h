#ifndef ENTITY_H
#define ENTITY_H
#include "Types.h"
#include <QObject>
constexpr int EntityCount = 2500;
class Entity;
struct CollisionBox{
float m_LeftCorner;
float m_RightCorner;
float m_TopCorner;
float m_BottomCorner;

CollisionBox(const float x,const float y,const float width ,const float height);
CollisionBox(const Entity& Entity);
bool OverLap(const CollisionBox& Box);
};

class Entity
{
public:
float m_Width ;
float m_Height;
float m_x;
float m_y;
float m_xVelocity;
float m_yVelocity;
float m_Speed;
CollisionBox m_CollisionBox;
uint16_t EntityIndex;
uint16_t m_Health;
Enums::EntityType m_EntityType; //uint8_t
Enums::Activity m_ColliderActive = Enums::Inactive; //uint8_t

Entity& operator=(const CollisionBox box);
void SetValues(const Enums::EntityType EntityType = Enums::NoType,const uint16_t Health = 0, const float x = 0.0f, const float y = 0.0f,
               const float width = 0.0f, const float height = 0.0f, const float speed = 0.0f, const float xvelocity =0.0f, const float yvelocity =0.0f);
Entity(const Enums::EntityType EntityType = Enums::NoType, const uint16_t Health = 0,const float x = 0.0f,
       const float y = 0.0f, const float width = 0.0f, const float height = 0.0f , Enums::Activity colliderActive = Enums::Inactive,
       const float xvelocity = 0.0f, const float yvelocity = 0.0f, const float speed = 0.0f);
void Damage(Entity& entityToDamage);
};

#endif // ENTITY_H
