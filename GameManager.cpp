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

GameManager::GameManager() {}
