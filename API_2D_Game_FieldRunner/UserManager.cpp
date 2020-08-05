#include "framework.h"
#include "UserManager.h"

UserManager* UserManager::m_pInstance{ nullptr };

void UserManager::ReSet(int gold)
{
	m_iGold = gold;
	m_iScore = 0;
	m_iLife = 3;
	TIME_MGR->Set_ReSetSpeed();
	cout << "Reset" << endl;
}

UserManager::UserManager()
{
}

UserManager::~UserManager()
{
}
