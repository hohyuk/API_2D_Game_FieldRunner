#include "framework.h"
#include "Goo.h"

#include "ObjectManager.h"
#include "GooBullet.h"

void Goo::Ready()
{
	Tower::Set_Pivot(0.f, -10.f);
	Tower::Ready();
	m_fBarrelRad = 70.f;
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
		m_tFrame.iSceneFrame = m_LevelMotion = 0;
		m_tFrame.fFixTime = 0.3f;
		break;
	case 2:
		m_iAttack = 20;
		m_iPriceArr[PRICE::CURRENT] = m_iPriceArr[PRICE::UPGRADE];
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_tFrame.iSceneFrame = m_LevelMotion = 1;
		m_tFrame.fFixTime = 0.2f;
		break;
	case MAX_TOWER_LEVEL:
		m_iAttack = 20;
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::UPGRADE] / 1.5f);
		m_tFrame.iSceneFrame = m_LevelMotion = 2;
		m_tFrame.fFixTime = 0.2f;
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
			MakeBullet();
			m_tFrame.fFrameSpeed = 0;
		}
	}
}

void Goo::MakeBullet()
{
	float angle = static_cast<float>((m_tFrame.iStart * 10) - 90.f);
	float rad = DEGREE_RADIAN(angle);
	m_fBarrelX = m_fBarrelRad * cosf(rad) + m_tInfo.fX;
	m_fBarrelY = m_fBarrelRad * sinf(rad) + m_tInfo.fY;

	
	if (m_Level == MAX_TOWER_LEVEL)
	{
		float temp = fabs(angle);		// 절대값
		float x = 0, y = 0;				// 위치 조절
		if ((temp <= 10 && temp >= 0) || temp >= 170 && temp <= 180)
			y = 10;
		else
			x = 10;

		CreateBullet(BULLET_ID::GOO_BULLET, m_fBarrelX - x, m_fBarrelY - y, rad);
		CreateBullet(BULLET_ID::GOO_BULLET, m_fBarrelX + x, m_fBarrelY + y, rad);
	}
	else
		CreateBullet(BULLET_ID::GOO_BULLET, m_fBarrelX, m_fBarrelY, rad);
}

