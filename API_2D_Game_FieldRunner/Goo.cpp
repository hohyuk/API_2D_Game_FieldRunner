#include "framework.h"
#include "Goo.h"

void Goo::Ready()
{
	Tower::Set_Pivot(0.f, -10.f);
	Tower::Ready();

}

void Goo::LateUpdate()
{
}

void Goo::Release()
{
}

Goo::Goo()
{
}

Goo::~Goo()
{
}

void Goo::UpgradeTower()
{
	switch (++m_Level)
	{
	case 1:
		m_iAttack = 15;
		m_iPriceArr[PRICE::CURRENT] = GooPrice;			// 초기는 그냥 넣어준다.
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_tFrame.iSceneFrame = 0;
		m_tFrame.fFixTime = 0.3f;
		break;
	case 2:
		m_iAttack = 20;
		m_iPriceArr[PRICE::CURRENT] = m_iPriceArr[PRICE::UPGRADE];
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_tFrame.iSceneFrame = 1;
		m_tFrame.fFixTime = 0.2f;
		break;
	case MAX_TOWER_LEVEL:
		m_iAttack = 35;
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::UPGRADE] / 1.5f);
		m_tFrame.iSceneFrame = 2;
		m_tFrame.fFixTime = 0.1f;
		break;
	default:
		break;
	}
	m_iAttackRange = 200 + (m_Level * 50);
	MakeRect(m_AttackRangeRect, m_tInfo, m_iAttackRange, m_iAttackRange, 1);
}

void Goo::Attack(float fDist)
{
	if (fDist < m_iAttackRange / 2)
	{
		TowerAnim();

		m_tFrame.fFrameSpeed += DELTA_TIME;
		if (m_tFrame.fFrameSpeed >= m_tFrame.fFixTime)
		{
			SOUND_MGR->PlaySound(SOUND_ID::GOO_ATTACK);
			CreateBullet();
			m_tFrame.fFrameSpeed = 0;
		}
	}
}

void Goo::CreateBullet()
{
	float angle = static_cast<float>((m_tFrame.iStart * 10) - 90.f);
	m_fBarrelX = m_fBarrelRad * cosf(DEGREE_RADIAN(angle)) + m_tInfo.fX;
	m_fBarrelY = m_fBarrelRad * sinf(DEGREE_RADIAN(angle)) + m_tInfo.fY;

	GameObject* pInstance = nullptr;
}
