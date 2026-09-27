#include "Entity.h"



Entity::Entity(const EntityType& EntityType,const double &x, const double &y, const double &width, const double &height) :
    m_EntityType(EntityType),m_x(x),m_y(y),m_Width(width),m_Height(height),m_CollisionBox(x,y,width,height)
{}

CollisionBox::CollisionBox(const double &x, const double &y, const double &width, const double &height) :
    m_LeftCorner(x),m_RightCorner(x + width),m_TopCorner(y),m_BottomCorner(y + height)
{}
