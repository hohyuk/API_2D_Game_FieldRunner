#include "framework.h"
#include "HeavyBike.h"

#include "HeavySoldier.h"
#include "ObjectManager.h"
void HeavyBike::Ready()
{
	Enemy::Ready();
	Init_Stat();
}

HeavyBike::HeavyBike()
{
}

HeavyBike::~HeavyBike()
{
}

void HeavyBike::Init_Stat()
{
	m_tInfo.iCX = m_tInfo.iCY = 140;
	m_iGold = 10;
	m_iScore = 15;
	m_fSpeed = 200.f;
	m_iMaxHP = m_iHP = 300;
	m_HpBarLength = m_tInfo.iCX >> 1;
}

void HeavyBike::Change_Anim()
{
	if (m_eCurState != m_vecState[++m_StateIndex])
	{
		switch (m_vecState[m_StateIndex])
		{
		case OBJECT::STATE::RIGHT:
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJECT::STATE::LEFT:
			m_tFrame.iSceneFrame = 1;
			break;
		case OBJECT::STATE::UP:
			m_tFrame.iSceneFrame = 2;
			break;
		case OBJECT::STATE::DOWN:
			m_tFrame.iSceneFrame = 3;
			break;
		default:
			m_tFrame.iSceneFrame = 0;
			break;
		}
		m_tFrame.iStart = 0;
		m_tFrame.iEnd = 4;
		m_tFrame.fFrameSpeed = 0.f;
		m_tFrame.fFixTime = 0.1f;
		m_eCurState = m_vecState[m_StateIndex];
	}
}

void HeavyBike::Dead_Anim()
{
	switch (m_vecState[m_StateIndex])
	{
	case OBJECT::STATE::RIGHT:
		m_tFrame.iSceneFrame = 5;
		break;
	case OBJECT::STATE::LEFT:
		m_tFrame.iSceneFrame = 4;
		break;
	default:
		m_tFrame.iSceneFrame = 5;
		break;
	}
	m_tFrame.iStart = 0;
	m_tFrame.iEnd = 4;
	m_tFrame.fFrameSpeed = 0.f;
	m_tFrame.fFixTime = 0.2f;
	SOUND_MGR->PlaySound(TEXT("explosion_01.mp3"), SOUND_MGR->ENEMY_DIE);
}

bool HeavyBike::DeleteEnemy()
{
	// 1. ¹üÀ§¿¡ ¹þ¾î ³µÀ» ¶§
	if (m_tInfo.fX >= WINCX + 50)
	{
		// »ý¸íÀ» ±ï¾Æ¾ßÇÑ´Ù.
		USER_MGR->Set_LifeMinus();
		return true;
	}
	// 2. Á×Àº ¾Ö´ÔÀÌ ³¡³ª¸é »èÁ¦
	else if (isDie && m_tFrame.iStart == m_tFrame.iEnd - 1)
	{
		CreateEnemy();
		USER_MGR->Set_Gain(m_iGold, m_iScore);
		return true;
	}
	return false;
}

void HeavyBike::CreateEnemy()
{
	GameObject* pTempObj = nullptr;
	pTempObj = AbstractFactory<HeavySoldier>::Create(TEXT("HeavySoldier"), m_tInfo.fX, m_tInfo.fY);
	dynamic_cast<HeavySoldier*>(pTempObj)->ReSearch();
	OBJ_MGR->Add_Object(pTempObj, OBJECT::ENEMY);
}
