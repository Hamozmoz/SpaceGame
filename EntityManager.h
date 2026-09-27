#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H
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

uint m_EntityCount{0};
std::array<Entity,2500> m_Entities;
public:
int rowCount(const QModelIndex& parent = QModelIndex())const override;
QVariant data(const QModelIndex& index , int role) const override;
QHash<int,QByteArray> roleNames() const override;
EntityManager();
};

#endif // ENTITYMANAGER_H
