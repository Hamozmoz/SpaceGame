#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "EntityManager.h"
class GameManager : public QObject
{
Q_OBJECT
Q_PROPERTY(EntityManager* EntityManager READ readEntityManager CONSTANT)
public:

static GameManager& Instance();
EntityManager* readEntityManager();
private:
GameManager();
EntityManager m_EntityManager;
};

#endif // GAMEMANAGER_H
