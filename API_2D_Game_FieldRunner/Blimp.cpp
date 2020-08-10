#include "framework.h"
#include "Blimp.h"

void Blimp::Ready()
{
	Init_Stat();
}

int Blimp::Update()
{
	Move_Wave();
	if (DeleteEnemy())
		return OBJ_DEAD;
	return OBJ_NOEVENT;
}

Blimp::Blimp()
{
}

Blimp::~Blimp()
{
}

void Blimp::Init_Stat()
{
	m_iGold = 15;
	m_iScore = 35;
	m_ftempX = m_tInfo.fX;
	m_ftempY = m_tInfo.fY;
	m_tInfo.iCX = m_tInfo.iCY = 400;
	m_tFrame.iStart = 0;
	m_tFrame.iEnd = 16;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.fFixTime = 0.2f;

	m_fSpeed = 1.f;
	m_iMaxHP = m_iHP = 1000;
	m_HpBarLength = 200;
	m_eRenderID = OBJECT::AIR_OBJECT_RENDER;
}

void Blimp::Change_Anim()
{
	if (m_iHP <= 0)
		isDie = true;
	else if (m_iHP < 200)
		m_tFrame.iSceneFrame = 2;
	else if (m_iHP < 400)
		m_tFrame.iSceneFrame = 1;
}

void Blimp::Dead_Anim()
{
	m_tFrame.fFrameSpeed += DELTA_TIME;
	if (m_tFrame.fFrameSpeed >= m_tFrame.fFixTime)
	{
		m_tFrame.iSceneFrame = Wrap(3, ++m_tFrame.iSceneFrame, m_tFrame.iEnd);
		m_tFrame.fFrameSpeed = 0;
	}
}

bool Blimp::DeleteEnemy()
{
	// 1. ¹üÀ§¿¡ ¹þ¾î ³µÀ» ¶§
	if (m_tInfo.fX >= WINCX + 50)
	{
		// »ý¸íÀ» ±ï¾Æ¾ßÇÑ´Ù.
		USER_MGR->Set_LifeMinus();
		return true;
	}

	// 2. Á×Àº ¾Ö´ÔÀÌ ³¡³ª¸é »èÁ¦
	if (isDie)
	{
		if (m_tFrame.iSceneFrame == m_tFrame.iEnd - 1)
		{
			USER_MGR->Set_Gain(m_iGold, m_iScore);
			SOUND_MGR->PlaySound(TEXT("explosion_01.mp3"), SOUND_MGR->ENEMY_DIE);
			return true;
		}
		else
			Dead_Anim();
	}
	return false;
}

void Blimp::Move_Wave()
{
	if (isDie) return;

	Change_Anim();
	m_fSpeed = TIME_MGR->IsDubleSpeed() == true ? 2.f : 1.f;

	m_ftempX += m_fSpeed;

	// Move
	m_iMoveAngle = static_cast<int>(m_iMoveAngle + m_fSpeed) % 360;
	float radian = DEGREE_RADIAN(static_cast<float>(m_iMoveAngle));
	m_tInfo.fX = cosf(radian) * 20 + m_ftempX;

	m_tInfo.fY = sinf(radian) * 20 + m_ftempY;
}
