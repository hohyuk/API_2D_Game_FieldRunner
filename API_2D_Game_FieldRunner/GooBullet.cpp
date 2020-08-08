#include "framework.h"
#include "GooBullet.h"

void GooBullet::Ready()
{
	m_eRenderID = OBJECT::BULLET_RENDER;
	m_tInfo.iCX = 60;
	m_tInfo.iCY = 60;
	m_fLifeTime = 0.f;
	m_tFrame.iSceneFrame = 0;
}

int GooBullet::Update()
{
	m_fLifeTime += DELTA_TIME;
	if (m_fLifeTime > 1.0f)
		return OBJ_DEAD;

	m_tInfo.fX += cosf(m_fRadAngle) *DELTA_TIME * 300.f;
	m_tInfo.fY += sinf(m_fRadAngle) *DELTA_TIME * 300.f;
	return OBJ_NOEVENT;
}

void GooBullet::LateUpdate()
{
}

void GooBullet::Release()
{
}

GooBullet::GooBullet()
{
}

GooBullet::~GooBullet()
{
}
