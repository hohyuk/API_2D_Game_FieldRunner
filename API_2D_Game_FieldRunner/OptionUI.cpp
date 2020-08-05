#include "framework.h"
#include "OptionUI.h"
#include "SceneManager.h"
void OptionUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo);
	m_tFrame.iEnd = 2;
	isShowUI = false;
}

void OptionUI::LateUpdate()
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

void OptionUI::Render(const HDC & hDC)
{
	GameObject::Render_Debug(hDC, m_tRect, Rectangle);
	GameObject::Render_Debug(hDC, m_tColliderRC, Ellipse, RGB(255, 0, 0));

	ButtonUI::Render(hDC);
}

OptionUI::OptionUI()
{
}

OptionUI::~OptionUI()
{
}
