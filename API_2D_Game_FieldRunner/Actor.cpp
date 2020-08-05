#include "framework.h"
#include "Actor.h"

void Actor::Ready()
{
}

int Actor::Update()
{
	return 0;
}

void Actor::LateUpdate()
{
}

void Actor::Render(const HDC & hDC)
{
	HDC hMemDC = BMP_MGR->Find_Image(m_pFrameKey);
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY, hMemDC, m_tInfo.iCX * m_tFrame.iStart, m_tInfo.iCY * m_tFrame.iSceneFrame,
		m_tInfo.iCX,
		m_tInfo.iCY, PINK_COLOR);
}

void Actor::Release()
{
}

Actor::Actor()
{
}

Actor::~Actor()
{
}
