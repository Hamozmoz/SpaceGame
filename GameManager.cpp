#include "GameManager.h"
GameManager &GameManager::Instance()
{
    static GameManager instance;
    return instance;
}

EntityManager* GameManager::readEntityManager()
{
    return &m_EntityManager;
}

InputManager *GameManager::readInputManager()
{
    return &m_InputManager;
}

GameManager::GameManager()
{
FrameTimer = new QChronoTimer(this);
DeltaTimer = new QElapsedTimer();
using namespace std::chrono_literals;
FrameTimer->setInterval(16ms);
FrameTimer->start();
DeltaTimer->start();
connect(FrameTimer,&QChronoTimer::timeout,this,&GameManager::Frame);
m_EntityManager.AddEntity(Enums::Player,10,1000,80,80,50,300);
m_EntityManager.AddEntity(Enums::Obstacle,11,800,80,90,90,0);
m_EntityManager.AddEntity(Enums::Projectile,10,0,80,30,30,10,90,0,Enums::NoId,2);
}

void GameManager::PlayerMovement()
{
    if(m_EntityManager[0].m_EntityType == Enums::Player){
    int SpeedMultiplier = m_InputManager.RightPressed -  m_InputManager.LeftPressed;
m_EntityManager[0].m_xVelocity = m_EntityManager[0].m_Speed  * SpeedMultiplier;
        SpeedMultiplier = m_InputManager.DownPressed - m_InputManager.UpPressed;
m_EntityManager[0].m_yVelocity = m_EntityManager[0].m_Speed * SpeedMultiplier;
    }
}

void GameManager::Frame()
{
    DeltaTime = DeltaTimer->restart() / 1000.0;
    PlayerMovement();
    m_EntityManager.ResetCollisionGrid();
    m_EntityManager.MoveEntities(DeltaTime);
    ++CurrentFrame;

    m_EntityManager.DeleteDeadEntities();

    if(CurrentFrame > 60){
    CurrentFrame = 1;
    }
}
