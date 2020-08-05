#include "framework.h"
#include "TowerUI.h"

#include "TileManager.h"

void TowerUI::Set_TowerKey(UI_TYPE::BUTTON _type)
{
	m_tTowerInfo.iCX = m_tTowerInfo.iCY = TOWER_SIZE;
	switch (_type)
	{
	case UI_TYPE::BUTTON::GATLING_BTN:
		m_pTowerKey = TEXT("GatlingTower");
		break;
	case UI_TYPE::BUTTON::GOO_BTN:
		m_pTowerKey = TEXT("GooTower");
		break;
	case UI_TYPE::BUTTON::FLAME_BTN:
		m_pTowerKey = TEXT("FlameTower");
		break;
	case UI_TYPE::BUTTON::MORTAR_BTN:
		m_pTowerKey = TEXT("MortarTower");
		m_tTowerInfo.iCX = m_tTowerInfo.iCY = 160;
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
			if (TILE_MGR->IsBuild(pt))
				m_Color = RGB(0, 255, 0);
			else
				m_Color = RGB(255, 0, 0);
		}
		if (KEY_MGR->Key_UP(VK_LBUTTON))
		{
			isClick = false;
			if (m_Color == RGB(255, 0, 0))
			{
				SOUND_MGR->PlaySound(SOUND_ID::INVALID);
				return;
			}

			// ���⼭ �÷��̾� ��������, true�̸� ������ϱ�
			if (TILE_MGR->Create_Tower(KEY_MGR->Mouse_Point(), m_tBtn, m_pTowerKey))
			{
				//USER_MGR->Set_Buy(m_iPrice);
				//SOUND_MGR->PlaySound(TEXT("tower_upgrade.mp3"), SOUND_MGR->UI);
			}
			else
			{
				//SOUND_MGR->PlaySound(TEXT("invalid.mp3"), SOUND_MGR->UI);
			}
		}
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

		Render_Alpha(hDC, m_tTowerRect, m_tTowerInfo.iCX, m_Color, Ellipse);
		// �̹���
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
