#include "framework.h"
#include "Flame.h"

void Flame::Ready()
{
	Tower::Set_Pivot(0.f, -20.f);
	Tower::Ready();

}

void Flame::LateUpdate()
{
}

void Flame::Release()
{
}

Flame::Flame()
{
}

Flame::~Flame()
{
}

void Flame::UpgradeTower()
{
	switch (++m_Level)
	{
	case 1:
		m_iAttack = 15;
		m_iPriceArr[PRICE::CURRENT] = FlamePrice;			// 초기는 그냥 넣어준다.
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_LevelMotion = m_tFrame.iSceneFrame = 0;
		m_tFrame.fFixTime = 0.3f;
		break;
	case 2:
		m_iAttack = 20;
		m_iPriceArr[PRICE::CURRENT] = m_iPriceArr[PRICE::UPGRADE];
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_LevelMotion = m_tFrame.iSceneFrame = 2;
		m_tFrame.fFixTime = 0.2f;
		break;
	case MAX_TOWER_LEVEL:
		m_iAttack = 35;
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::UPGRADE] / 1.5f);
		m_LevelMotion = m_tFrame.iSceneFrame = 4;
		m_tFrame.fFixTime = 0.1f;
		break;
	default:
		break;
	}
}
