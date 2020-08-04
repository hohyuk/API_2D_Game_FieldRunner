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
	ButtonUI::LateUpdate();

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
	cout << "SelectUI Create()" << endl;
}

SelectUI::~SelectUI()
{
	Release();
	cout << "SelectUI Release()" << endl;
}
