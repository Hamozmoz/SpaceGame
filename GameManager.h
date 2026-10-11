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
EntityManager *readEntityManager();
InputManager* readInputManager();
inline const uint CurFrame() const;
inline const uint64_t CurSecond() const;
inline const float DTime() const;
private:
uint CurrentFrame{1};
uint64_t CurrentSecond{0};
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
