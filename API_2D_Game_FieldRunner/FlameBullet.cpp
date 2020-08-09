#include "framework.h"
#include "FlameBullet.h"

void FlameBullet::Ready()
{
	m_tInfo.iCX = 64;
	m_tInfo.iCY = 64;
	m_fLifeTime = 0.f;
}

int FlameBullet::Update()
{
	m_fLifeTime += DELTA_TIME;
	if (m_fLifeTime > 0.5f)
		return OBJ_DEAD;

	m_tInfo.fX += cosf(m_fRadAngle) * DELTA_TIME * 150.f;
	m_tInfo.fY += sinf(m_fRadAngle) * DELTA_TIME * 150.f;
	
	return OBJ_NOEVENT;
}

FlameBullet::FlameBullet()
{
}

FlameBullet::~FlameBullet()
{
}
