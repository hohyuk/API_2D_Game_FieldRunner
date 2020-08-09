#include "framework.h"
#include "Flame.h"

void Flame::Ready()
{
	Tower::Set_Pivot(0.f, -20.f);
	Tower::Ready();
	m_fBarrelRad = 60;
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
		m_iAttack = 10;
		m_iPriceArr[PRICE::CURRENT] = FlamePrice;			// 초기는 그냥 넣어준다.
		m_iPriceArr[PRICE::SELL] = static_cast<int>(m_iPriceArr[PRICE::CURRENT] / 1.5f);
		m_iPriceArr[PRICE::UPGRADE] = m_iPriceArr[PRICE::CURRENT] * 2;
		m_LevelMotion = m_tFrame.iSceneFrame = 0;
		m_tFrame.fFixTime = 0.3f;
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
	m_iAttackRange = 200 + (m_Level * 50);
	MakeRect(m_AttackRangeRect, m_tInfo, m_iAttackRange, m_iAttackRange, 1);
}

void Flame::Attack(float fDist)
{
	if (fDist < m_iAttackRange / 2)
	{
		TowerAnim();

		m_tFrame.fFrameSpeed += DELTA_TIME;
		if (m_tFrame.fFrameSpeed >= m_tFrame.fFixTime)
		{
			MakeBullet();
			SOUND_MGR->PlaySound(SOUND_ID::FLAME_ATTACK);
			m_tFrame.iSceneFrame = Wrap(m_LevelMotion, ++m_tFrame.iSceneFrame, m_LevelMotion + 2);
			m_tFrame.fFrameSpeed = 0;
		}
	}
	else
		m_tFrame.iSceneFrame = m_LevelMotion;
}

void Flame::MakeBullet()
{
	float angle = static_cast<float>((m_tFrame.iStart * 10) - 90.f);
	float rad = DEGREE_RADIAN(angle);
	m_fBarrelX = (m_fBarrelRad * cosf(rad) + m_tInfo.fX) + 5;
	m_fBarrelY = m_fBarrelRad * sinf(rad) + m_tInfo.fY;

	CreateBullet(BULLET_ID::FLAME2_BULLET, m_fBarrelX, m_fBarrelY, rad);
	CreateBullet(BULLET_ID::FLAME2_BULLET, m_fBarrelX, m_fBarrelY, DEGREE_RADIAN(angle - 10));
	CreateBullet(BULLET_ID::FLAME2_BULLET, m_fBarrelX, m_fBarrelY, DEGREE_RADIAN(angle + 10));
	CreateBullet(BULLET_ID::FLAME1_BULLET, m_fBarrelX, m_fBarrelY, DEGREE_RADIAN(angle - 15));
	CreateBullet(BULLET_ID::FLAME1_BULLET, m_fBarrelX, m_fBarrelY, DEGREE_RADIAN(angle + 15));
}
