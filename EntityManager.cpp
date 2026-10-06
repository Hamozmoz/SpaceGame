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
    Roles[roles::Height] = "height";
    Roles[roles::Width] = "width";
    Roles[roles::x] = "x";
    Roles[roles::y] = "y";
    return Roles;
}

bool EntityManager::AddEntity(const Enums::EntityType &EntityType, uint16_t Health, const float x, const float y, const float width, const float height, const float speed, const float xvelocity, const float yvelocity)
{
    if(m_EntityCount >= m_Entities.size()){
        return false;
    }
    m_Entities[m_EntityCount].SetValues(EntityType,Health,x,y,width,height,speed,xvelocity,yvelocity);
    ++m_EntityCount;

    return true;
}

void EntityManager::MoveEntities(const double deltaTime)
{
    for(int i{0}; i < m_EntityCount;++i)
    {
if(m_Entities[i].m_xVelocity == 0 && m_Entities[i].m_yVelocity == 0){
continue;
}
QModelIndex curIndex = createIndex(i,0);
float NextxMovement = m_Entities[i].m_x + m_Entities[i].m_xVelocity * deltaTime;
float NextyPosition = m_Entities[i].m_y + m_Entities[i].m_yVelocity * deltaTime;;
CollisionBox xProjectedBox(NextxMovement,m_Entities[i].m_y,m_Entities[i].m_Width,m_Entities[i].m_Height);
bool CanMovex = true;
bool CanMovey = true;
std::vector<uint16_t> NearbyEntities = m_CollisionGrid.getNearbyEntities(xProjectedBox);
for(auto entity : NearbyEntities){
if(entity == i){
continue;
}
if(xProjectedBox.OverLap(m_Entities[entity])){
if(m_Entities[i].m_x < m_Entities[entity].m_x){
m_Entities[i].m_x = m_Entities[entity].m_CollisionBox.m_LeftCorner - m_Entities[i].m_Width;
}else{
m_Entities[i].m_x = m_Entities[entity].m_CollisionBox.m_RightCorner;
}
CanMovex = false;
}
}
NextyPosition = m_Entities[i].m_y + m_Entities[i].m_yVelocity * deltaTime;
CollisionBox yProjectedBox(m_Entities[i].m_x,NextyPosition,m_Entities[i].m_Width,m_Entities[i].m_Height);
NearbyEntities = m_CollisionGrid.getNearbyEntities(yProjectedBox);
for(auto entity : NearbyEntities){
if(entity == i){
continue;
}
if(yProjectedBox.OverLap(m_Entities[entity])){
if(m_Entities[i].m_y <m_Entities[entity].m_y){
m_Entities[i].m_y = m_Entities[entity].m_CollisionBox.m_TopCorner - m_Entities[i].m_Height;
}else{
m_Entities[i].m_y = m_Entities[entity].m_CollisionBox.m_BottomCorner;
}
CanMovey = false;
}
}
if(CanMovex){
m_Entities[i].m_x = NextxMovement;
}
if(CanMovey){
m_Entities[i].m_y = NextyPosition;
}
m_Entities[i].m_CollisionBox = CollisionBox{m_Entities[i]};
dataChanged(curIndex,curIndex,{x,y});
}}


int EntityManager::LastActiveIndex()
{
    if(m_EntityCount > 0){
        return m_EntityCount -1;
    }
    return 0;
}

void EntityManager::DeleteEntity(const uint IndextoDelete){

    m_Entities[IndextoDelete] = m_Entities[LastActiveIndex()];
    --m_EntityCount;
    QModelIndex changedIndex = createIndex(IndextoDelete,0);
    dataChanged(changedIndex,changedIndex);
}

void EntityManager::ResetCollisionGrid()
{
    m_CollisionGrid.CalculateEntityLocations(this->m_Entities,m_EntityCount);
}
Entity &EntityManager::operator[](int index)
{
    return m_Entities[index];
}

const Entity &EntityManager::operator[](int index) const
{
    return m_Entities[index];
}

EntityManager::EntityManager()
{
for(int i {0}; i < m_Entities.size();++i){
m_Entities[i].EntityIndex = i;
}
}
