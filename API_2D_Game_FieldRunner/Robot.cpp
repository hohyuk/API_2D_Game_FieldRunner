#include "framework.h"
#include "Robot.h"

void Robot::Ready()
{
	Enemy::Ready();
	Init_Stat();
}

Robot::Robot()
{
}

Robot::~Robot()
{
}

void Robot::Init_Stat()
{
	m_tInfo.iCX = m_tInfo.iCY = 200;
	m_fSpeed = 150.f;
	m_iHP = m_iMaxHP = 1000;
	m_HpBarLength = m_tInfo.iCX >> 1;
	m_iGold = 30;
	m_iScore = 20;
}

void Robot::Change_Anim()
{
	if (m_eCurState != m_vecState[++m_StateIndex])
	{
		switch (m_vecState[m_StateIndex])
		{
		case OBJECT::STATE::RIGHT:
			m_tFrame.iEnd = 6;
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJECT::STATE::LEFT:
			m_tFrame.iEnd = 6;
			m_tFrame.iSceneFrame = 1;
			break;
		case OBJECT::STATE::UP:
			m_tFrame.iEnd = 4;
			m_tFrame.iSceneFrame = 2;
			break;
		case OBJECT::STATE::DOWN:
			m_tFrame.iEnd = 4;
			m_tFrame.iSceneFrame = 3;
			break;
		default:
			m_tFrame.iEnd = 6;
			m_tFrame.iSceneFrame = 0;
			break;
		}
		m_tFrame.iStart = 0;
		m_tFrame.fFrameSpeed = 0.f;
		m_tFrame.fFixTime = 0.2f;
		m_eCurState = m_vecState[m_StateIndex];
	}
}

void Robot::Dead_Anim()
{
	switch (m_vecState[m_StateIndex])
	{
	case OBJECT::STATE::RIGHT:
		m_tFrame.iEnd = 10;
		m_tFrame.iSceneFrame = 6;
		break;
	case OBJECT::STATE::LEFT:
		m_tFrame.iEnd = 10;
		m_tFrame.iSceneFrame = 7;
		break;
	case OBJECT::STATE::UP:
		m_tFrame.iEnd = 5;
		m_tFrame.iSceneFrame = 4;
		break;
	case OBJECT::STATE::DOWN:
		m_tFrame.iEnd = 7;
		m_tFrame.iSceneFrame = 5;
		break;
	default:
		m_tFrame.iEnd = 10;
		m_tFrame.iSceneFrame = 6;
		break;
	}
	m_tFrame.iStart = 0;
	m_tFrame.fFrameSpeed = 0.f;
	m_tFrame.fFixTime = 0.2f;
	SOUND_MGR->PlaySound(TEXT("explosion_01.mp3"), SOUND_MGR->ENEMY_DIE);
}
