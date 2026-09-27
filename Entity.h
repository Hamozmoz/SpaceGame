#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
struct CollisionBox{
double LeftCorner{0};
double RightCorner{0};
double TopCorner{0};
double BottomCorner{0};


};

class Entity
{
    Q_OBJECT
public:
double Width {0};
double Height{0};
double x{0};
double y{0};
    Entity();
};

#endif // ENTITY_H
