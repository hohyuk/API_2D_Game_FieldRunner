#include "framework.h"
#include "LogoUI.h"

#include "SceneManager.h"

void LogoUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, 2);

	isShowUI = false;
}

void LogoUI::LateUpdate()
{
	POINT pt = KEY_MGR->Mouse_Point();

	if (IsPointInRect(pt, m_tColliderRC))
	{
		isShowUI = true;
		if (KEY_MGR->Key_DOWN(VK_LBUTTON))
			isClick = true;
		if (KEY_MGR->Key_UP(VK_LBUTTON))
		{
			switch (m_tBtn)
			{
			case UI_TYPE::PLAY_BTN:
				SCENE_MGR->Change_Scene(SceneManager::SELECT);
				break;
			case UI_TYPE::HELP_BTN:
				SCENE_MGR->Change_Scene(SceneManager::HELP);
				break;
			case UI_TYPE::SCORE_BTN:
				break;
			case UI_TYPE::EDIT_BTN:
				break;
			case UI_TYPE::END_BTN:
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

void LogoUI::Render(const HDC & hDC)
{
	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Rectangle, RGB(255, 0, 0));

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
