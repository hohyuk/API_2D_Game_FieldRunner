#include "framework.h"
#include "ButtonUI.h"

void ButtonUI::Ready()
{
}

int ButtonUI::Update()
{
	return 0;
}

void ButtonUI::LateUpdate()
{
}

void ButtonUI::Render(const HDC & hDC)
{
	MakeRect(m_tRect, m_tInfo);

	Render_Debug(hDC, m_tRect, Rectangle);

	HDC hMemDC = BMP_MGR->Find_Image(m_pFrameKey);
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0,
		m_tInfo.iSrcX, m_tInfo.iSrcY, PINK_COLOR);
}

void ButtonUI::Release()
{
}

ButtonUI::ButtonUI()
{
}

ButtonUI::~ButtonUI()
{
	Release();
}
