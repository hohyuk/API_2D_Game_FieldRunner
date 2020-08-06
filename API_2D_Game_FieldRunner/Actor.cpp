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
	Render_Debug(hDC, m_tRect, Rectangle);
	Render_Debug(hDC, m_tColliderRC, Rectangle, RGB(255, 0, 0));

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

void Actor::Update_Anim()
{
	m_tFrame.fFrameSpeed += DELTA_TIME;
	if (m_tFrame.fFrameSpeed >= m_tFrame.fFixTime)
	{
		m_tFrame.iStart = Wrap(0, ++m_tFrame.iStart, m_tFrame.iEnd);
		m_tFrame.fFrameSpeed = 0;
	}
}
