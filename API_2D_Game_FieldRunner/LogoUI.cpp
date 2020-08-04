#include "framework.h"
#include "LogoUI.h"

void LogoUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, 2);

	isShowUI = false;
}

void LogoUI::Render(const HDC & hDC)
{
	GameObject::Render_Debug(hDC, m_tRect, Rectangle);
	GameObject::Render_Debug(hDC, m_tColliderRC, Rectangle, RGB(255, 0, 0));

	if (!isShowUI) return;
	ButtonUI::Render(hDC);
}

LogoUI::LogoUI()
{
	cout << "LogoUI Create()" << endl;
}

LogoUI::~LogoUI()
{
	cout << "LogoUI Release()" << endl;
}
