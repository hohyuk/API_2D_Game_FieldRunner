#include "framework.h"
#include "Effect.h"

void Effect::Ready()
{
	m_eRenderID = OBJECT::EFFECT_RENDER;
	m_tInfo.iCX = 80;
	m_tInfo.iCY = 80;
	m_tFrame.iSceneFrame = 0;
	m_tFrame.iStart = 0;
	m_tFrame.iEnd = 16;
	MakeRect(m_tRect, m_tInfo);
}

int Effect::Update()
{
	m_tFrame.fFrameSpeed += DELTA_TIME;
	if (m_tFrame.fFrameSpeed >= 0.05f)
	{
		m_tFrame.iStart = Clamp(0, ++m_tFrame.iStart, m_tFrame.iEnd);
		m_tFrame.fFrameSpeed = 0;

		if (!isSound)
		{
			SOUND_MGR->PlaySound(SOUND_ID::EFFECT);
			isSound = true;
		}
	}


	if (m_tFrame.iStart == m_tFrame.iEnd - 1)
		return OBJ_DEAD;
	return OBJ_NOEVENT;
}

Effect::Effect()
{
}

Effect::~Effect()
{
}
