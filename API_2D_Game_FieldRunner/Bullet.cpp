#include "framework.h"
#include "Bullet.h"

void Bullet::Render(const HDC & hDC)
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, 2);

	Actor::Render(hDC);
}

Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}
