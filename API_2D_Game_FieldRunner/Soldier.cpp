#include "framework.h"
#include "Soldier.h"

void Soldier::Ready()
{
	Enemy::Ready();
	m_tInfo.iCX = 64;
	m_tInfo.iCY = 64;
	m_fSpeed = 100.f;
}

int Soldier::Update()
{
	Move();
	return OBJ_NOEVENT;
}

Soldier::Soldier()
{
}

Soldier::~Soldier()
{
}

void Soldier::Change_Anim()
{
	if (m_eCurState != m_vecState[m_StateIndex])
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
		m_tFrame.fFixTime = 0.2f;
		m_eCurState = m_vecState[m_StateIndex];
		++m_StateIndex;
	}
}
