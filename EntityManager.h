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
Entity& GetPlayer();
const Entity& GetPlayer() const;
const Entity& operator[](int index) const;
Entity& operator[](int index);
EntityManager();
template<Enums::EntityId entityId>
bool AddEntity(const float x = 0 , const float y = 0);
private:
uint m_EntityCount{0};
std::vector<uint16_t> m_DeleteLaterBuffer;
void DeleteDLEntities();
void AddToDLBuffer(const uint16_t index);
bool AddEntityToArray(const Enums::EntityType& EntityType, uint16_t Health, const float x, const float y, const float width,
const float height, const float speed, const float xvelocity = 0, const float yvelocity = 0, const Enums::EntityId entityid = Enums::NoId, const uint8_t projectilepiercing = 0);
bool AddEntityToArray(Entity Entity );
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
 AddEntityToArray(Entity::EntityData<Enums::PlayerId>(x,y));
 return true;
    }else if(entityId == Enums::EntityId::SpaceBoltId)
    {
 AddEntityToArray(Entity::EntityData<Enums::SpaceBoltId>(x,y));
 return true;
    }else if(entityId == Enums::EntityId::SpaceRockId)
    {
 AddEntityToArray(Entity::EntityData<Enums::SpaceRockId>(x,y));
    return true;
    }

}






#endif // ENTITYMANAGER_H
