#include "framework.h"
#include "ExitUI.h"

#include "SceneManager.h"

void ExitUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo);

	isShowUI = false;
}

void ExitUI::Render(const HDC & hDC)
{
	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Rectangle, RGB(255, 0, 0));

	if (!isShowUI) return;
	ButtonUI::Render(hDC);
}

ExitUI::ExitUI()
{
	cout << "ExitUI Create()" << endl;
}

ExitUI::~ExitUI()
{
	cout << "ExitUI Release()" << endl;
}
