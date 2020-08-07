#include "framework.h"
#include "HeavySoldier.h"

void HeavySoldier::Ready()
{
	Enemy::Ready();
	Init_Stat();
}

int HeavySoldier::Update()
{
	Actor::Update_Anim();

	if (!isDie)	Move();

	if (DeleteEnemy()) return OBJ_DEAD;
	return OBJ_NOEVENT;
}

HeavySoldier::HeavySoldier()
{
}

HeavySoldier::~HeavySoldier()
{
}

void HeavySoldier::Init_Stat()
{
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;
	m_iGold = 6;
	m_iScore = 10;
	m_fSpeed = 100.f;
	m_iMaxHP = m_iHP = 200;
	m_HpBarLength = m_tInfo.iCX >> 1;
}

void HeavySoldier::Change_Anim()
{
	if (m_eCurState != m_vecState[++m_StateIndex])
	{
		switch (m_vecState[m_StateIndex])
		{
		case OBJECT::STATE::RIGHT:
			m_tFrame.iEnd = 10;
			m_tFrame.iSceneFrame = 0;
			break;
		case OBJECT::STATE::LEFT:
			m_tFrame.iEnd = 10;
			m_tFrame.iSceneFrame = 1;
			break;
		case OBJECT::STATE::UP:
			m_tFrame.iEnd = 10;
			m_tFrame.iSceneFrame = 2;
			break;
		case OBJECT::STATE::DOWN:
			m_tFrame.iEnd = 7;
			m_tFrame.iSceneFrame = 3;
			break;
		default:
			m_tFrame.iEnd = 10;
			m_tFrame.iSceneFrame = 0;
			break;
		}
		m_tFrame.iStart = 0;
		m_tFrame.fFrameSpeed = 0.f;
		m_tFrame.fFixTime = 0.1f;
		m_eCurState = m_vecState[m_StateIndex];
	}
}

void HeavySoldier::Dead_Anim()
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
	m_tFrame.iEnd = 8;
	m_tFrame.fFrameSpeed = 0.f;
	m_tFrame.fFixTime = 0.1f;
}
