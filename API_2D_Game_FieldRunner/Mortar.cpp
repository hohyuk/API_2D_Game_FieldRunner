#include "framework.h"
#include "Mortar.h"

void Mortar::Ready()
{
	m_tInfo.iCX = m_tInfo.iCY = 160;
	m_tFrame.iEnd = 10;
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_ClickRangeRect, m_tInfo, 150, 150);
	MakeRect(m_SellRect, m_tInfo.fX - 100, m_tInfo.fY, 50, 50);
	MakeRect(m_UpgradeRect, m_tInfo.fX + 100, m_tInfo.fY, 50, 50);

	UpgradeTower();
}

void Mortar::LateUpdate()
{
}

void Mortar::Release()
{
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
	m_tFrame.iSceneFrame = 0;
	m_tFrame.fFixTime = 0.1f;
}

void Mortar::Attack(float fDist)
{
}

void Mortar::CreateBullet()
{
}
