#include "framework.h"
#include "SelectUI.h"

#include "SceneManager.h"

void SelectUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, 150, 100);

	isShowUI = false;
}

void SelectUI::LateUpdate()
{
	POINT pt = KEY_MGR->Mouse_Point();

	if (IsPointInRect(pt, m_tColliderRC))
	{
		isShowUI = true;
		if (KEY_MGR->Key_UP(VK_LBUTTON))
		{
			switch (m_tBtn)
			{
			case UI_TYPE::STAGE1_BTN:
				SCENE_MGR->Change_Scene(SceneManager::STAGE_1);
				return;
			case UI_TYPE::STAGE2_BTN:
				SCENE_MGR->Change_Scene(SceneManager::STAGE_2);
				return;
			case UI_TYPE::STAGE3_BTN:
				SCENE_MGR->Change_Scene(SceneManager::STAGE_3);
				return;
			default:
				break;
			}
			
		}
	}
	else
	{
		isShowUI = false;
	}

	switch (m_tBtn)
	{
	case UI_TYPE::STAGE1_BTN:
		m_pFrameKey = isShowUI == true ? TEXT("Map_thumb_grass") : TEXT("Grasslands_icon");
		break;
	case UI_TYPE::STAGE2_BTN:
		m_pFrameKey = isShowUI == true ? TEXT("Map_thumb_lavaflow") : TEXT("lavaflow_icon");
		break;
	case UI_TYPE::STAGE3_BTN:
		m_pFrameKey = isShowUI == true ? TEXT("Map_thumb_Cave") : TEXT("Cave_icon");
		break;
	default:
		break;
	}
}

void SelectUI::Render(const HDC & hDC)
{
	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Rectangle, RGB(255, 0, 0));

	ButtonUI::Render(hDC);
}

SelectUI::SelectUI()
{
}

SelectUI::~SelectUI()
{
}
