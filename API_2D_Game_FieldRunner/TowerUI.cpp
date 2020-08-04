#include "framework.h"
#include "TowerUI.h"

void TowerUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo);
	m_tFrame.iEnd = 2;
}

void TowerUI::LateUpdate()
{
	POINT pt = KEY_MGR->Mouse_Point();

	if (IsPointInCircle(pt, m_tColliderRC))
	{
		if (!isButtonSound)
		{
			SOUND_MGR->PlaySound(SOUND_ID::BUTTON2);
			isButtonSound = true;
		}
		if (KEY_MGR->Key_UP(VK_LBUTTON))
		{
			Click_Button();
		}
	}
	else
	{
		isClick = false;
		isButtonSound = false;
	}
}

void TowerUI::Render(const HDC & hDC)
{
	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Ellipse, RGB(255, 0, 0));

	ButtonUI::Render(hDC);
}

TowerUI::TowerUI()
{
}

TowerUI::~TowerUI()
{
}
