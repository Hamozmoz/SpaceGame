#include "GameManager.h"
GameManager &GameManager::Instance()
{
    static GameManager instance;
    return instance;
}

EntityManager* GameManager::readEntityManager()
{return &m_EntityManager;}
InputManager *GameManager::readInputManager()
{return &m_InputManager;}
const uint GameManager::CurFrame() const
{return CurrentFrame;}
const uint64_t GameManager::CurSecond() const
{return CurrentSecond;}
const uint64_t GameManager::CurGlobalFrame() const
{ return 60*CurrentSecond + CurrentFrame; }
const float GameManager::DTime() const
{return DeltaTime;}

GameManager::GameManager()
{
FrameTimer = new QChronoTimer(this);
DeltaTimer = new QElapsedTimer();
using namespace std::chrono_literals;
FrameTimer->setInterval(16ms);
connect(FrameTimer,&QChronoTimer::timeout,this,&GameManager::Frame);
FrameTimer->start();
DeltaTimer->start();
m_EntityManager.AddEntity<Enums::PlayerId>(750,600);
m_EntityManager.AddEntity<Enums::SpaceRockId>(800,80);

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

void GameManager::PlayerAttack()
{
    if(m_InputManager.XPressed == Enums::Pressed)
    {
        m_EntityManager.AddEntity<Enums::SpaceBoltId>(m_EntityManager.GetPlayer().m_x,m_EntityManager.GetPlayer().m_y - 30);
    }
}

void GameManager::Frame()
{
    DeltaTime = DeltaTimer->restart() / 1000.0;
    PlayerMovement();
    m_EntityManager.ResetCollisionGrid();
    m_EntityManager.MoveEntities(DeltaTime);
    ++CurrentFrame;
    if(CurrentFrame % 30 == 0)
    {
    PlayerAttack();
    }

    if(CurrentFrame == 60)
    {
    m_EntityManager.DeleteDeadEntities();

    CurrentFrame = 1;
    ++CurrentSecond;
    }

}
