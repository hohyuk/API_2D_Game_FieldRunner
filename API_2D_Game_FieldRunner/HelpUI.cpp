#include "framework.h"
#include "HelpUI.h"

void HelpUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo);

	isShowUI = false;
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
	cout << "HelpUI Create()" << endl;
}

HelpUI::~HelpUI()
{
	cout << "HelpUI Release()" << endl;
}
