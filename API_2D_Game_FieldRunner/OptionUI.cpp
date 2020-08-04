#include "framework.h"
#include "OptionUI.h"
#include "SceneManager.h"
void OptionUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, 150, 100);

	isShowUI = false;
}

void OptionUI::LateUpdate()
{
	POINT pt = KEY_MGR->Mouse_Point();

	if (IsPointInRect(pt, m_tColliderRC))
	{
		if (KEY_MGR->Key_UP(VK_LBUTTON))
		{
			SCENE_MGR->Change_Scene(SceneManager::LOGO);
		}
	}
	else
	{
		//isShowUI = false;
	}
}

void OptionUI::Render(const HDC & hDC)
{
	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Rectangle, RGB(255, 0, 0));

	//if (!isShowUI) return;
	ButtonUI::Render(hDC);
}

OptionUI::OptionUI()
{
}

OptionUI::~OptionUI()
{
}
