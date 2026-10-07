#include "Entity.h"
Entity::Entity(const Enums::EntityType EntityType, const uint16_t Health, const float x, const float y, const float width, const float height, Enums::Activity colliderActive, const float xvelocity, const float yvelocity, const float speed, const Enums::EntityId entityid,const uint8_t projectilepiercing) :
    m_EntityType(EntityType),m_Health(Health),m_x(x),m_y(y),m_Width(width),m_Height(height),m_CollisionBox(x,y,width,height),m_xVelocity(xvelocity),m_ColliderActive(colliderActive),m_yVelocity(yvelocity),m_Entityid(entityid),m_ProjPiercing(projectilepiercing)
{}

void Entity::TakeDamage(uint16_t Damage)
{
    if(Damage > m_Health){
        m_Health = 0;
    }else {
        m_Health -= Damage;
    }
}



Entity &Entity::operator=(const CollisionBox box){

    this->m_CollisionBox = box;
    this->m_x = box.m_LeftCorner;
    this->m_y = box.m_TopCorner;
    return *this;
}

void Entity::SetValues(const Enums::EntityType EntityType, const uint16_t Health , const float x, const float y, const float width, const float height, const float speed , const float xvelocity, const float yvelocity, const Enums::EntityId entityid, const uint8_t projectilepiercing){
    m_EntityType = EntityType;
    m_Health = Health;
    m_x = x;
    m_y = y;
    m_Width = width;
    m_Height = height;
    m_xVelocity = xvelocity;
    m_yVelocity = yvelocity;
    m_Speed = speed;
    m_CollisionBox = CollisionBox(x,y,width,height);
    m_Entityid = entityid;
    m_ProjPiercing = projectilepiercing;
}
CollisionBox::CollisionBox(const float x, const float y, const float width, const float height) :
    m_LeftCorner(x),m_RightCorner(x + width),m_TopCorner(y),m_BottomCorner(y + height)
{}

CollisionBox::CollisionBox(const Entity &Entity):
m_LeftCorner(Entity.m_x),m_RightCorner(Entity.m_x+Entity.m_Width),m_TopCorner(Entity.m_y),m_BottomCorner(Entity.m_y + Entity.m_Height)
{}

bool CollisionBox::OverLap(const CollisionBox &Box){
    return(this->m_LeftCorner < Box.m_RightCorner && this->m_RightCorner > Box.m_LeftCorner
            && this->m_TopCorner < Box.m_BottomCorner && this->m_BottomCorner > Box.m_TopCorner);
}
