#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "EntityManager.h"
#include "InputManager.h"
#include <QChronoTimer>
#include <QElapsedTimer>
class GameManager : public QObject
{
Q_OBJECT
Q_PROPERTY(EntityManager* entityManager READ readEntityManager CONSTANT)
Q_PROPERTY(InputManager* inputManager READ readInputManager CONSTANT)
public:
static GameManager& Instance();
EntityManager* readEntityManager();
InputManager* readInputManager();
private:
uint CurrentFrame{1};
GameManager();
EntityManager m_EntityManager;
InputManager m_InputManager;
QChronoTimer* FrameTimer;
QElapsedTimer* DeltaTimer;
double DeltaTime {0};
void PlayerMovement();
void Frame();

};

#endif // GAMEMANAGER_H
