#include "EntityManager.h"

int EntityManager::rowCount(const QModelIndex &parent) const
{
    return m_EntityCount;
}

QVariant EntityManager::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= m_EntityCount){
        return QVariant();
    }
if(role == roles::EntityType){return m_Entities[index.row()].m_EntityType;}
if(role == roles::Width){return m_Entities[index.row()].m_Width;}
if(role == roles::Height){return m_Entities[index.row()].m_Height;}
if(role == roles::x){return m_Entities[index.row()].m_x;}
if(role == roles::y){return m_Entities[index.row()].m_y;}

    return QVariant();
}

QHash<int, QByteArray> EntityManager::roleNames() const{
    QHash<int,QByteArray> Roles;
    Roles[roles::EntityType] = "EntityType";
    Roles[roles::Height] = "Height";
    Roles[roles::Width] = "Width";
    Roles[roles::x] = "x";
    Roles[roles::y] = "y";
    return Roles;
}

EntityManager::EntityManager() {}
