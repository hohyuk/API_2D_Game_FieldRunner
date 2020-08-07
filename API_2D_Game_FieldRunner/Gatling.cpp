#include "framework.h"
#include "Gatling.h"

#include "Enemy.h"

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
		m_tFrame.fFixTime = 0.1f;
		break;
	case 2:
		m_iAttack = 15;
		m_iPriceArr[PRICE::CURRENT] = m_iPriceArr[PRICE::UPGRADE];
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_LevelMotion = m_tFrame.iSceneFrame = 2;
		m_tFrame.fFixTime = 0.1f;
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
	m_iAttackRange = 200 + (m_Level * 50);
	MakeRect(m_AttackRangeRect, m_tInfo, m_iAttackRange, m_iAttackRange, 1);
}

void Gatling::Attack(float fDist)
{
	if (fDist < m_iAttackRange / 2)
	{
		// 적과 포신의 각도 구하기
		int degree = static_cast<int>(atan2f(m_tInfo.fDirY, m_tInfo.fDirX) * RADIAN);
		degree = (degree + 90) / 10;	// 이미지 각도 맞게
		m_tFrame.iStart = Wrap(0, degree, 36);

		m_tFrame.fFrameSpeed += DELTA_TIME;
		if (m_tFrame.fFrameSpeed >= m_tFrame.fFixTime)
		{
			/*if (m_TowerLevel == 1)
				SOUND_MGR->PlaySound(TEXT("tower_gatling_fire_loop_01.mp3"), SOUND_MGR->PLAYER);
			else if (m_TowerLevel == 2)
				SOUND_MGR->PlaySound(TEXT("tower_gatling_fire_loop_02.mp3"), SOUND_MGR->PLAYER);
			else if (m_TowerLevel == 3)
				SOUND_MGR->PlaySound(TEXT("tower_gatling_fire_loop_03.mp3"), SOUND_MGR->PLAYER);*/

			m_tFrame.iSceneFrame = Wrap(m_LevelMotion, ++m_tFrame.iSceneFrame, m_LevelMotion + 2);

			m_tFrame.fFrameSpeed = 0;
			if (m_tFrame.iSceneFrame == m_LevelMotion + 1)
				dynamic_cast<Enemy*>(m_pTarget)->Set_Damage(m_iAttack);
		}
	}
	else
		m_tFrame.iSceneFrame = m_LevelMotion;
}
