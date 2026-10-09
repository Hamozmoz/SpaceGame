#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
#include "CollisionGrid.h"
#include "Entity.h"
#include <QObject>
#include <QAbstractListModel>
class EntityManager : public QAbstractListModel
{
Q_OBJECT
enum roles{
EntityType = Qt::UserRole +1,
Width,
Height,
x,
y,
color
};
CollisionGrid m_CollisionGrid{15,15,80,80};
public:
std::array<Entity,EntityCount> m_Entities;
int rowCount(const QModelIndex& parent = QModelIndex())const override;
QVariant data(const QModelIndex& index , int role) const override;
QHash<int,QByteArray> roleNames() const override;
void MoveEntities(const double deltaTime);
int LastActiveIndex();
void DeleteEntity(const uint IndextoDelete);
void ResetCollisionGrid();
bool CanMoveAfterCollisionAction(uint16_t collidingEntity , uint16_t otherEntity, bool &ActionDone);
void DeleteDeadEntities();
const Entity& operator[](int index) const;
Entity& operator[](int index);
EntityManager();
template<Enums::EntityId entityId>
bool AddEntity(const float x = 0 , const float y = 0);
private:
uint m_EntityCount{0};
bool AddEntityToArray(const Enums::EntityType& EntityType, uint16_t Health, const float x, const float y, const float width,
const float height, const float speed, const float xvelocity = 0, const float yvelocity = 0, const Enums::EntityId entityid = Enums::NoId, const uint8_t projectilepiercing = 0);

};
//Spawning Template Function
template<Enums::EntityId entityId>
bool EntityManager::AddEntity(const float x , const float y )
{
    if constexpr(entityId == Enums::EntityId::NoId)
    {
 return false;
    }else if(entityId == Enums::EntityId::PlayerId)
    {
 AddEntityToArray(Enums::Player,1000,x,y,40,40,160,0,0,entityId);
 return true;
    }else if(entityId == Enums::EntityId::SpaceBoltId)
    {
 AddEntityToArray(Enums::PlayerProjectile,10,x,y,30,30,30,90,0,entityId,1);
 return true;
    }else if(entityId == Enums::EntityId::SpaceRockId)
    {
 AddEntityToArray(Enums::Obstacle,10,x,y,90,90,0,0,0,entityId);
    return true;
    }

}

#endif // ENTITYMANAGER_H
