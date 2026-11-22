#include "Entity.h"

void Entity::TakeDamage(uint16_t Damage)
{
    if(Damage < m_Health){
       m_Health -= Damage;
    }else {
       m_Health = 0;
       m_EntityActive = Enums::Activity::Inactive;
    }
}

void Entity::Die()
{
    m_Health = 0;
    m_EntityActive = Enums::Activity::Inactive;
}

QString Entity::Color() const
{
    switch(m_EntityType){
    case Enums::EntityType::Player:
        return "black";
        break;
    case Enums::EntityType::PlayerProjectile:
        return "green";
        break;
    case Enums::EntityType::Enemy:
        return "red";
        break;
    case Enums::EntityType::EnemyProjectile:
        return "darkred";
        break;
    case Enums::EntityType::Obstacle:
        return "blue";
        break;
    default:
        return "white";
        break;
    }


}

void Entity::PrintEntityData(const Entity entity)
{

    qDebug() << " Entity Type : " << entity.m_EntityType <<
        "\n Entity Id : " << entity.m_Entityid <<
        "\n Entity Health : "<< entity.m_Health <<
        "\n Entity Height : " << entity.m_Height <<
        "\n Entity Width : " << entity.m_Width <<
        "\n Entity Speed : " << entity.m_Speed <<
        "\n Entity X Position : " << entity.m_x <<
        "\n Entity Y Position : " << entity.m_y <<
        "\n Entity X Velocity : " << entity.m_xVelocity <<
        "\n Entity Y Velocity : " << entity.m_yVelocity <<
        "\n Entity ProjectilePiercing : " << entity.m_ProjPiercing <<
        "\n Last Collided Entity Index :  " << entity.m_LastCollidedIndex <<
        "\n Entity Unique Index : " << entity.m_UniqueIndex <<
        "\n Entity Activity : " << entity.m_EntityActive <<
        "\n Entity State : " << entity.m_EntityState;

}



Entity &Entity::operator=(const CollisionBox box){

    this->m_CollisionBox = box;
    this->m_x = box.m_LeftCorner;
    this->m_y = box.m_TopCorner;
    return *this;
}

void Entity::SetValues(const Enums::EntityType EntityType, const uint16_t Health , const float x, const float y, const float width, const float height, const float speed , const float xvelocity, const float yvelocity, const Enums::EntityId entityid, const uint8_t projectilepiercing, const Enums::Activity entityActive , const Enums::EntityState entityState){
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
    m_EntityActive = entityActive;
    m_EntityState = entityState;
}

void Entity::SetValues(Entity Entity)
{
Entity.m_UniqueIndex = this->m_UniqueIndex;
    *this = Entity;
}


CollisionBox::CollisionBox(const Entity &Entity):
m_LeftCorner(Entity.m_x),m_RightCorner(Entity.m_x+Entity.m_Width),m_TopCorner(Entity.m_y),m_BottomCorner(Entity.m_y + Entity.m_Height)
{}

bool CollisionBox::OverLap(const CollisionBox &Box){
    return(this->m_LeftCorner < Box.m_RightCorner && this->m_RightCorner > Box.m_LeftCorner
            && this->m_TopCorner < Box.m_BottomCorner && this->m_BottomCorner > Box.m_TopCorner);
}
