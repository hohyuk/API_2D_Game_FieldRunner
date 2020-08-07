#include "framework.h"
#include "UserManager.h"

UserManager* UserManager::m_pInstance{ nullptr };

void UserManager::ReSet(int gold)
{
	m_iGold = gold;
	m_iScore = 0;
	m_iLife = 3;
	isGameState[GAME_OVER] = false;
	TIME_MGR->Set_ReSetSpeed();
	cout << "Reset" << endl;
}

void UserManager::Set_Gain(int _gold, int _score)
{
	m_iGold += _gold;
	m_iScore += _score;
}

UserManager::UserManager()
{
}

UserManager::~UserManager()
{
}
