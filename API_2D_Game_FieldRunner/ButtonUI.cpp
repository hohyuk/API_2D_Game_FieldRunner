#include "framework.h"
#include "ButtonUI.h"

#include "SceneManager.h"

void ButtonUI::Ready()
{
	
}

int ButtonUI::Update()
{
	return 0;
}

void ButtonUI::LateUpdate()
{
	POINT pt = KEY_MGR->Mouse_Point();

	if (IsPointInRect(pt, m_tColliderRC))
	{
		isShowUI = true;
		if (!isButtonSound)
		{
			SOUND_MGR->PlaySound(SOUND_ID::BUTTON2);
			isButtonSound = true;
		}
		if (KEY_MGR->Key_DOWN(VK_LBUTTON))
			isClick = true;
		if (KEY_MGR->Key_UP(VK_LBUTTON))
		{
			SOUND_MGR->PlaySound(SOUND_ID::BUTTON1);
			Click_Button();
		}
	}
	else
	{
		isShowUI = false;
		isClick = false;
		isButtonSound = false;
	}
}

void ButtonUI::Render(const HDC & hDC)
{
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

void ButtonUI::Click_Button()
{
	switch (m_tBtn)
	{
	case UI_TYPE::PLAY_BTN:
		SCENE_MGR->Change_Scene(SceneManager::SELECT);
		break;
	case UI_TYPE::HELP_BTN:
		SCENE_MGR->Change_Scene(SceneManager::HELP);
		break;
	case UI_TYPE::EDIT_BTN:
		SCENE_MGR->Change_Scene(SceneManager::EDIT);
		break;
	case UI_TYPE::STAGE1_BTN:
		SCENE_MGR->Change_Scene(SceneManager::STAGE_1);
		break;
	case UI_TYPE::STAGE2_BTN:
		SCENE_MGR->Change_Scene(SceneManager::STAGE_2);
		break;
	case UI_TYPE::STAGE3_BTN:
		SCENE_MGR->Change_Scene(SceneManager::STAGE_3);
		break;
	case UI_TYPE::EXIT_BTN:
		SCENE_MGR->Change_Scene(SceneManager::LOGO);
		break;
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
