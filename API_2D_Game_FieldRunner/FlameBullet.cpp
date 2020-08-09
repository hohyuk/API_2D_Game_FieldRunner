#include "framework.h"
#include "FlameBullet.h"

void FlameBullet::Ready()
{
	m_tInfo.iCX = 64;
	m_tInfo.iCY = 64;
	m_fLifeTime = 0.f;
	m_iBulletSize = 0;
}

int FlameBullet::Update()
{
	++m_iBulletSize;
	m_fLifeTime += DELTA_TIME;
	if (m_fLifeTime > 0.5f)
		return OBJ_DEAD;

	m_tInfo.fX += cosf(m_fRadAngle) * DELTA_TIME * 150.f;
	m_tInfo.fY += sinf(m_fRadAngle) * DELTA_TIME * 150.f;
	
	return OBJ_NOEVENT;
}

void FlameBullet::Render(const HDC & hDC)
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, 2);

	HDC hMemDC = BMP_MGR->Find_Image(m_pFrameKey);
	GdiTransparentBlt(hDC, m_tRect.left - m_iBulletSize, m_tRect.top - m_iBulletSize,
		m_tInfo.iCX + m_iBulletSize * 2, m_tInfo.iCY + m_iBulletSize * 2, hMemDC, 0, 0,
		m_tInfo.iCX, m_tInfo.iCY, RGB(255, 0, 255));
}

FlameBullet::FlameBullet()
{
}

FlameBullet::~FlameBullet()
{
}
