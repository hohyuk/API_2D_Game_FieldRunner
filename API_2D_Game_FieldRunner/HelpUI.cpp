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
		if (KEY_MGR->Key_DOWN(VK_LBUTTON))
			isClick = true;
		if (KEY_MGR->Key_UP(VK_LBUTTON) && isClick)
		{
			switch (m_tBtn)
			{
			case UI_TYPE::NEXT_BTN:
				g_iHelpSceneOrder = Wrap(0, ++g_iHelpSceneOrder, 3);
				break;
			case UI_TYPE::BACK_BTN:
				g_iHelpSceneOrder = Wrap(0, --g_iHelpSceneOrder, 3);
				break;
			default:
				break;
			}
		}
	}
	else
	{
		isShowUI = false;
		isClick = false;
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
	cout << "HelpUI Create()" << endl;
}

HelpUI::~HelpUI()
{
	cout << "HelpUI Release()" << endl;
}
