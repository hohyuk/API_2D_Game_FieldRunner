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
	HDC hMemDC = BMP_MGR->Find_Image(m_pFrameKey);
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top,
		m_tInfo.iCX, m_tInfo.iCY, hMemDC, 0, 0,
		m_tInfo.iCX, m_tInfo.iCY, PINK_COLOR);
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
