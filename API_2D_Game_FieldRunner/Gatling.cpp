#include "framework.h"
#include "Gatling.h"

void Gatling::Ready()
{
	Tower::Set_Pivot(0.f, -10.f);
	Tower::Ready();
}

void Gatling::LateUpdate()
{
}

void Gatling::Release()
{
}

Gatling::Gatling()
{
	cout << "Gatling Create" << endl;
}

Gatling::~Gatling()
{
	Release();
	cout << "Gatling Release" << endl;
}

void Gatling::UpgradeTower()
{
	switch (++m_Level)
	{
	case 1:
		m_iAttack = 10;
		m_iPriceArr[PRICE::CURRENT] = GatlingPrice;			// 초기는 그냥 넣어준다.
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_LevelMotion = m_tFrame.iSceneFrame = 0;
		m_tFrame.fFixTime = 0.2f;
		break;
	case 2:
		m_iAttack = 15;
		m_iPriceArr[PRICE::CURRENT] = m_iPriceArr[PRICE::UPGRADE];
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_LevelMotion = m_tFrame.iSceneFrame = 2;
		m_tFrame.fFixTime = 0.2f;
		break;
	case MAX_TOWER_LEVEL:
		m_iAttack = 20;
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::UPGRADE] / 1.5f);
		m_LevelMotion = m_tFrame.iSceneFrame = 4;
		m_tFrame.fFixTime = 0.1f;
		break;
	default:
		break;
	}
}
