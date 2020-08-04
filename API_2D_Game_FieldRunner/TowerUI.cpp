#include "framework.h"
#include "TowerUI.h"

void TowerUI::Set_TowerKey(UI_TYPE::BUTTON _type)
{
	switch (_type)
	{
	case UI_TYPE::BUTTON::GATLING_BTN:
		m_pTowerKey = TEXT("GatlingTower");
		m_tTowerInfo.iCX = m_tTowerInfo.iCY = 200;
		break;
	case UI_TYPE::BUTTON::GOO_BTN:
		m_pTowerKey = TEXT("GooTower");
		m_tTowerInfo.iCX = m_tTowerInfo.iCY = 200;
		break;
	case UI_TYPE::BUTTON::FLAME_BTN:
		m_pTowerKey = TEXT("FlameTower");
		m_tTowerInfo.iCX = m_tTowerInfo.iCY = 200;
		break;
	case UI_TYPE::BUTTON::MORTAR_BTN:
		m_pTowerKey = TEXT("MortarTower");
		break;
	default:
		break;
	}
}

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
		if (KEY_MGR->Key_DOWN(VK_LBUTTON) )
		{
			//SOUND_MGR->PlaySound(TEXT("UI_button.wav"), SOUND_MGR->UI);
			isClick = true;
		}
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
		isButtonSound = false;
	}

	if (isClick)
	{
		if (KEY_MGR->Key_Pressing(VK_LBUTTON))
		{
			m_tTowerInfo.fX = static_cast<float>(pt.x);
			m_tTowerInfo.fY = static_cast<float>(pt.y);
		/*	if (TILE_MGR->IsBuild(pt))
				m_Color = RGB(0, 255, 0);
			else
				m_Color = RGB(255, 0, 0);*/
		}
		//if (KEY_MGR->Key_UP(VK_LBUTTON))
		//{
		//	isClick = false;
		//	if (m_Color == RGB(255, 0, 0))
		//	{
		//		SOUND_MGR->PlaySound(TEXT("invalid.mp3"), SOUND_MGR->UI);
		//		return;
		//	}

		//	// 여기서 플레이어 생성하자, true이면 돈계산하기
		//	if (TILE_MGR->Change_TIle(KEY_MGR->Mouse_Point(), m_eTower, m_pPlayerObjectKey, 1))
		//	{
		//		USER_MGR->Set_Buy(m_iPrice);
		//		SOUND_MGR->PlaySound(TEXT("tower_upgrade.mp3"), SOUND_MGR->UI);
		//	}
		//	else
		//	{
		//		SOUND_MGR->PlaySound(TEXT("invalid.mp3"), SOUND_MGR->UI);
		//	}
		//}
	}
}

void TowerUI::Render(const HDC & hDC)
{
	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Ellipse, RGB(255, 0, 0));

	ButtonUI::Render(hDC);

	if (isClick)
	{
		MakeRect(m_tTowerRect, m_tTowerInfo);

		//Render_RangeObject(hDC);

		// 이미지
		HDC hMemDC = BMP_MGR->Find_Image(m_pTowerKey);
		GdiTransparentBlt(hDC, m_tTowerRect.left, m_tTowerRect.top,
			m_tTowerInfo.iCX, m_tTowerInfo.iCY, hMemDC, 0, 0,
			m_tTowerInfo.iCX,
			m_tTowerInfo.iCY, RGB(255, 0, 255));
	}
}

TowerUI::TowerUI()
{
}

TowerUI::~TowerUI()
{
}
