#include "framework.h"
#include "Tile.h"

#include "UserManager.h"
void Tile::Ready()
{
	m_tInfo.iCX = 64;
	m_tInfo.iCY = 64;
	m_dwColor = RGB(255, 255, 255);
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
	SelectColor();
	GameObject::Render_Debug(hDC, m_tRect, Rectangle, m_dwColor);

	if (USER_MGR->Get_DebugNoneTileBox() && OBJECT::NONE == m_TileType)
	{
		HPEN hPen = CreatePen(PS_SOLID, 1, RGB(0,0,0));
		HPEN oldPen = (HPEN)SelectObject(hDC, hPen);
		auto old = SelectObject(hDC, GetStockObject(NULL_BRUSH));

		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);

		SelectObject(hDC, old);
		SelectObject(hDC, oldPen);
		DeleteObject(hPen);
	}
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

void Tile::SelectColor()
{
	switch (m_TileType)
	{
	case OBJECT::START_POINT:
		m_dwColor = RGB(0, 255, 0);
		break;
	case OBJECT::ARRIVAL_POINT:
		m_dwColor = RGB(0, 0, 255);
		break;
	case OBJECT::TOWER_INSTALL:
		m_dwColor = RGB(255, 0, 255);
		break;
	case OBJECT::NOT_TOWER_INSTALL:
		m_dwColor = RGB(255, 0, 0);
		break;
	case OBJECT::LANDMARK:
		m_dwColor = RGB(255, 255, 0);
		break;
	case OBJECT::NONE:
		m_dwColor = RGB(255, 255, 255);
		break;
	default:
		break;
	}
}
