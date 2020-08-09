#include "framework.h"
#include "MortarBullet.h"

void MortarBullet::Ready()
{
	m_eRenderID = OBJECT::EFFECT_RENDER;
	m_tInfo.iCX = 100;
	m_tInfo.iCY = 100;
	m_fLifeTime = 0.f;
	m_tFrame.iStart = 0;
	m_tFrame.iEnd = 11;

	m_StartPoint = POINT{ static_cast<LONG>(m_tInfo.fX), static_cast<LONG>(m_tInfo.fY) };
	m_MiddlePoint = POINT{ static_cast<LONG>(m_tInfo.fX), static_cast<LONG>(m_tInfo.fY - 200) };
}

int MortarBullet::Update()
{
	m_fTime += DELTA_TIME * 2.f;
	m_fTime = Clamp(0.f, m_fTime, 1.f);
	m_tInfo.fX = QuadraticBezierCurve(m_fTime, m_StartPoint.x, m_MiddlePoint.x, m_EndPoint.x);
	m_tInfo.fY = QuadraticBezierCurve(m_fTime, m_StartPoint.y, m_MiddlePoint.y, m_EndPoint.y);

	
	if (isBomb)
	{
		m_tFrame.fFrameSpeed += DELTA_TIME;
		if (m_tFrame.fFrameSpeed >= 0.2f)
		{
			m_tFrame.iStart = Clamp(0, ++m_tFrame.iStart, m_tFrame.iEnd);
		}
	}
	else if (m_fTime == 1.f)
		isBomb = true;

	if (m_tFrame.iStart == m_tFrame.iEnd - 1)
		return OBJ_DEAD;
	return OBJ_NOEVENT;
}

void MortarBullet::Render(const HDC & hDC)
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo);

	Actor::Render(hDC);
}

MortarBullet::MortarBullet()
{
}

MortarBullet::~MortarBullet()
{
}

float MortarBullet::QuadraticBezierCurve(float t, LONG start, LONG middle, LONG end)
{
	return static_cast<float>((1.f - t) * (1.f - t) * start + 2.f * t * (1.f - t)*middle + t * t * end);
}
