#include "framework.h"
#include "HelpUI.h"

void HelpUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo);

	isShowUI = false;
}

void HelpUI::LateUpdate()
{
	POINT pt = KEY_MGR->Mouse_Point();

	if (IsPointInRect(pt, m_tColliderRC))
	{
		isShowUI = true;
	}
	else
	{
		isShowUI = false;
	}
}

void HelpUI::Render(const HDC & hDC)
{
	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Rectangle, RGB(255, 0, 0));

	if (!isShowUI) return;
	ButtonUI::Render(hDC);
}

HelpUI::HelpUI()
{
}

HelpUI::~HelpUI()
{
}
