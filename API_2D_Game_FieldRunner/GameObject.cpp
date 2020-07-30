#include "framework.h"
#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Render_Debug(const HDC & hDC, const RECT & rc, BOOL(__stdcall * _ShapeFun)(HDC hDC, int left, int top, int right, int bottom)/*= Rectangle*/, DWORD _color /*= RGB(255, 255, 255)*/)
{
	HPEN hPen = CreatePen(PS_SOLID, 2, _color);
	HPEN oldPen = (HPEN)SelectObject(hDC, hPen);
	auto old = SelectObject(hDC, GetStockObject(NULL_BRUSH));

	_ShapeFun(hDC, rc.left, rc.top, rc.right, rc.bottom);

	SelectObject(hDC, old);
	SelectObject(hDC, oldPen);
	DeleteObject(hPen);
}
