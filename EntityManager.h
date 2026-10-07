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
y
};
CollisionGrid m_CollisionGrid{15,15,80,80};
public:
std::array<Entity,EntityCount> m_Entities;
int rowCount(const QModelIndex& parent = QModelIndex())const override;
QVariant data(const QModelIndex& index , int role) const override;
QHash<int,QByteArray> roleNames() const override;
bool AddEntity(const Enums::EntityType& EntityType, uint16_t Health, const float x, const float y, const float width,
               const float height, const float speed, const float xvelocity = 0, const float yvelocity = 0, const Enums::EntityId entityid = Enums::NoId, const uint8_t projectilepiercing = 0);
void MoveEntities(const double deltaTime);
int LastActiveIndex();
void DeleteEntity(const uint IndextoDelete);
void ResetCollisionGrid();
bool CanMoveAfterCollisionAction(uint16_t collidingEntity , uint16_t otherEntity, bool &ActionDone);
void DeleteDeadEntities();
const Entity& operator[](int index) const;
Entity& operator[](int index);
EntityManager();
private:
uint m_EntityCount{0};
};

#endif // ENTITYMANAGER_H
