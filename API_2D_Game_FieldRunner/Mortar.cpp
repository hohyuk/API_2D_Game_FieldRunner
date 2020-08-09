#include "framework.h"
#include "Mortar.h"

void Mortar::Ready()
{
	m_tInfo.iCX = m_tInfo.iCY = 160;
	
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_ClickRangeRect, m_tInfo, 150, 150);
	MakeRect(m_SellRect, m_tInfo.fX - 100, m_tInfo.fY, 50, 50);
	MakeRect(m_UpgradeRect, m_tInfo.fX + 100, m_tInfo.fY, 50, 50);

	UpgradeTower();
}

int Mortar::Update()
{
	if (isAttackMotion)
	{
		m_tFrame.fFrameSpeed += DELTA_TIME;
		if (m_tFrame.fFrameSpeed >= m_tFrame.fFixTime)
		{
			m_tFrame.iStart = Wrap(0, ++m_tFrame.iStart, m_tFrame.iEnd);
			m_tFrame.fFrameSpeed = 0;
			if (m_tFrame.iStart == m_tFrame.iEnd - 1)
				isAttackMotion = false;
			else if (m_tFrame.iStart == 5)
			{
				//SOUND_MGR->PlaySound(TEXT("tower_mortar_attack_01.mp3"), SOUND_MGR->PLAYER);
				MakeBullet();
			}
		}
	}
	else
		Attack_EnemyRanger();

	POINT pt = KEY_MGR->Mouse_Point();
	Click_Tower(pt);
	UnClick_Tower(pt);

	if (Click_Sell(pt)) return OBJ_DEAD;
	return OBJ_NOEVENT;
}

Mortar::Mortar()
{
}

Mortar::~Mortar()
{
}

void Mortar::UpgradeTower()
{
	m_Level = MAX_TOWER_LEVEL;

	m_iAttack = 20;
	m_iPriceArr[PRICE::SELL] = static_cast<int>(MortarPrice / 1.5f);
	m_tFrame.iStart = 0;
	m_tFrame.iEnd = 10;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.fFixTime = 0.1f;
	m_iAttackRange = 200 + (m_Level * 70);
	MakeRect(m_AttackRangeRect, m_tInfo, m_iAttackRange, m_iAttackRange, 1);
}

void Mortar::Attack(float fDist)
{
	if (fDist < m_iAttackRange)
		isAttackMotion = true;

}

void Mortar::MakeBullet()
{
}
