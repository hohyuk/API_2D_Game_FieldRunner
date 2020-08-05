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
	// D�� ������ RenderBox�� On/Off
	if (!USER_MGR->Get_DebugRenderBox()) return;
	HPEN hPen = CreatePen(PS_SOLID, 2, _color);
	HPEN oldPen = (HPEN)SelectObject(hDC, hPen);
	auto old = SelectObject(hDC, GetStockObject(NULL_BRUSH));

	_ShapeFun(hDC, rc.left, rc.top, rc.right, rc.bottom);

	SelectObject(hDC, old);
	SelectObject(hDC, oldPen);
	DeleteObject(hPen);
}

void GameObject::Render_Alpha(const HDC & hDC, const RECT & rc, int _size, DWORD _color, BOOL(__stdcall * _ShapeFun)(HDC hDC, int left, int top, int right, int bottom))
{
	// ���� �̹���
	HBRUSH m_br = CreateSolidBrush(_color);
	HBITMAP Ahbmp = CreateCompatibleBitmap(hDC, _size, _size);			// ���ĺ����� �� ��Ʈ�� ����
	HDC Ahdc = CreateCompatibleDC(hDC);									// ��ȭ�� �غ�
	HBITMAP Aoldbmp = (HBITMAP)SelectObject(Ahdc, Ahbmp);				// ���⿡ �׸��� �׸�
	auto oldbr = SelectObject(Ahdc, m_br);
	_ShapeFun(Ahdc, 0, 0, _size, _size);
	SelectObject(Ahdc, oldbr);

	BLENDFUNCTION bf;

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = 50;										// ���� 255 -> 0

	GdiAlphaBlend(hDC, rc.left, rc.top, _size, _size, Ahdc, 0, 0, _size, _size, bf);
	SelectObject(Ahdc, Aoldbmp);
	DeleteObject(m_br);
	DeleteObject(Ahbmp);
	DeleteDC(Ahdc);
}
