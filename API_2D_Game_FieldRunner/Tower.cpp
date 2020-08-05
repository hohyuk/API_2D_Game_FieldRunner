#include "framework.h"
#include "Tower.h"



void Tower::Ready()
{
	m_tInfo.iCX = m_tInfo.iCY = 200;
	m_tFrame.iStart = 0;
	m_tFrame.iEnd = 36;
	MakeRect(m_tRect, m_tInfo);
}

int Tower::Update()
{
	return 0;
}

void Tower::LateUpdate()
{
}

void Tower::Render(const HDC & hDC)
{
	Actor::Render(hDC);
}

void Tower::Release()
{
}

Tower::Tower()
{
}


Tower::~Tower()
{
}
