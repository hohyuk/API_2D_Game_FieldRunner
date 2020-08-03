#include "framework.h"
#include "Tile.h"

void Tile::Ready()
{
	m_tInfo.iCX = 64;
	m_tInfo.iCY = 64;

	MakeRect(m_tRect, m_tInfo);
}

int Tile::Update()
{
	return 0;
}

void Tile::LateUpdate()
{
}

void Tile::Render(const HDC & hDC)
{
	GameObject::Render_Debug(hDC, m_tRect, Rectangle);
}

void Tile::Release()
{
}

Tile::Tile()
{
}

Tile::~Tile()
{
	Release();
}
