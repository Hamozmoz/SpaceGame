 #ifndef ENTITY_H
#define ENTITY_H
#include "Types.h"
#include <QObject>
#include <QDebug>
constexpr int EntityCount = 2500;
class Entity;
struct CollisionBox{
float m_LeftCorner;
float m_RightCorner;
float m_TopCorner;
float m_BottomCorner;

constexpr CollisionBox(const float x,const float y,const float width ,const float height):
    m_LeftCorner(x),m_RightCorner(x + width),m_TopCorner(y),m_BottomCorner(y + height)
{}
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
uint16_t m_Health;
uint16_t m_LastCollidedIndex{25000};
uint16_t m_UniqueIndex{0};
Enums::EntityType m_EntityType;
Enums::Activity m_EntityActive = Enums::Active;
Enums::EntityId m_Entityid;
Enums::EntityState m_EntityState;
uint8_t m_ProjPiercing;
Entity& operator=(const CollisionBox box);
void SetValues(const Enums::EntityType EntityType = Enums::NoType, const uint16_t Health = 0, const float x = 0.0f, const float y = 0.0f,const float width = 0.0f,
               const float height = 0.0f, const float speed = 0.0f, const float xvelocity =0.0f,const float yvelocity =0.0f, const Enums::EntityId entityid = Enums::NoId,
               const uint8_t projectilepiercing = 0, const Enums::Activity entityActive = Enums::Activity::Active,const Enums::EntityState entityState = Enums::NoState);
void SetValues(Entity Entity);
constexpr Entity(const Enums::EntityType EntityType = Enums::NoType, const uint16_t Health = 0, const float x = 0.0f,
       const float y = 0.0f, const float width = 0.0f, const float height = 0.0f , Enums::Activity EntityActive = Enums::Inactive, const float xvelocity = 0.0f,
       const float yvelocity = 0.0f, const float speed = 0.0f, const Enums::EntityId entityid = Enums::NoId, const uint8_t projectilepiercing = 0, const Enums::EntityState entityState = Enums::NoState):
    m_EntityType(EntityType),m_Health(Health),m_x(x),m_y(y),m_Width(width),m_Height(height),m_CollisionBox(x,y,width,height),m_xVelocity(xvelocity),m_EntityActive(EntityActive),m_yVelocity(yvelocity),m_Entityid(entityid),m_ProjPiercing(projectilepiercing),m_EntityState(entityState),m_Speed(speed)
{}

void TakeDamage(uint16_t Damage);
void Die();
QString Color() const;
static void PrintEntityData(const Entity entity);
template<Enums::EntityId entityId>
static const constexpr Entity EntityData(float x = 0, float y = 0);

};

template<Enums::EntityId entityId>
const constexpr Entity Entity::EntityData(float x , float y)
{
if constexpr(entityId == Enums::NoId)
{
return Entity();
}else if(entityId == Enums::EntityId::PlayerId)
{
return Entity(Enums::Player,1000,x,y,40,40,Enums::Active,0,0,160,Enums::PlayerId);
}else if(entityId == Enums::EntityId::SpaceBoltId)
{
return Entity(Enums::PlayerProjectile,10,x,y,15,30,Enums::Active,0,-165.0f,30,Enums::SpaceBoltId,1);
}else if(entityId == Enums::EntityId::SpaceRockId)
{
return Entity(Enums::Obstacle,50,x,y,90,90,Enums::Active,0,0,0,Enums::SpaceRockId);
}
}
#endif // ENTITY_H
