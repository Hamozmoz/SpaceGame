#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
struct CollisionBox{
double m_LeftCorner{0};
double m_RightCorner{0};
double m_TopCorner{0};
double m_BottomCorner{0};
CollisionBox(const double& x,const double& y,const double& width ,const double& height);
};

class Entity : public QObject
{
    Q_OBJECT

enum EntityType{
Null,
Player
};
Q_ENUM(EntityType)
public:
EntityType m_EntityType ;
double m_Width ;
double m_Height;
double m_x;
double m_y;
CollisionBox m_CollisionBox;
Entity(const EntityType& EntityType = EntityType::Null,const double& x = 0,const double& y = 0,const double& width = 0,const double& height = 0);
};

#endif // ENTITY_H
