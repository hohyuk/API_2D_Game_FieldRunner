#include "framework.h"
#include "Soldier.h"

void Soldier::Ready()
{
	Enemy::Ready();
	// Init Stat
	Init_Stat();
}

Soldier::Soldier()
{
}

Soldier::~Soldier()
{
}

void Soldier::Init_Stat()
{
	m_tInfo.iCX = m_tInfo.iCY = 64;
	m_fSpeed = 150.f;
	m_iHP = m_iMaxHP = 100;
	m_HpBarLength = m_tInfo.iCX >> 1;
	m_iGold = 3;
	m_iScore = 10;
}

void Soldier::Change_Anim()
{
	if (m_eCurState != m_vecState[++m_StateIndex])
	{
		switch (m_vecState[m_StateIndex])
		{
		case OBJECT::STATE::RIGHT:
			m_tFrame.iEnd = 8;
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJECT::STATE::LEFT:
			m_tFrame.iEnd = 8;
			m_tFrame.iSceneFrame = 1;
			break;
		case OBJECT::STATE::UP:
			m_tFrame.iEnd = 7;
			m_tFrame.iSceneFrame = 2;
			break;
		case OBJECT::STATE::DOWN:
			m_tFrame.iEnd = 9;
			m_tFrame.iSceneFrame = 3;
			break;
		case OBJECT::STATE::DIE_LEFT:
			m_tFrame.iEnd = 5;
			m_tFrame.iSceneFrame = 4;
			break;
		case OBJECT::STATE::DIE_RIGHT:
			m_tFrame.iEnd = 5;
			m_tFrame.iSceneFrame = 5;
			break;
		default:
			m_tFrame.iEnd = 8;
			m_tFrame.iSceneFrame = 0;
			break;
		}
		m_tFrame.iStart = 0;
		m_tFrame.fFrameSpeed = 0.f;
		m_tFrame.fFixTime = 0.1f;
		m_eCurState = m_vecState[m_StateIndex];
	}
}

void Soldier::Dead_Anim()
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
	m_tFrame.iEnd = 5;
	m_tFrame.fFrameSpeed = 0.f;
	m_tFrame.fFixTime = 0.1f;

	int rand = RAND_INT(4);

	switch (rand)
	{
	case 0:
		SOUND_MGR->PlaySound(TEXT("unit_soldier_death_02.mp3"), SOUND_MGR->ENEMY_DIE);
		break;
	case 1:
		SOUND_MGR->PlaySound(TEXT("unit_soldier_death_03.mp3"), SOUND_MGR->ENEMY_DIE);
		break;
	case 2:
		SOUND_MGR->PlaySound(TEXT("unit_soldier_death_04.mp3"), SOUND_MGR->ENEMY_DIE);
		break;
	case 3:
		SOUND_MGR->PlaySound(TEXT("unit_soldier_death_06.mp3"), SOUND_MGR->ENEMY_DIE);
		break;
	default:
		break;
	}
}
