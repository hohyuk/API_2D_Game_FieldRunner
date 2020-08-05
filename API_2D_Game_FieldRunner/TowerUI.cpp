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
		m_iPrice = GatlingPrice;
		MakeRect(m_tFontRect, m_tInfo.fX + 55, m_tInfo.fY + 35, 50, 50);
		break;
	case UI_TYPE::BUTTON::GOO_BTN:
		m_pTowerKey = TEXT("GooTower");
		m_iPrice = GooPrice;
		MakeRect(m_tFontRect, m_tInfo.fX + 45, m_tInfo.fY + 35, 50, 50);
		break;
	case UI_TYPE::BUTTON::FLAME_BTN:
		m_pTowerKey = TEXT("FlameTower");
		m_iPrice = FlamePrice;
		MakeRect(m_tFontRect, m_tInfo.fX + 45, m_tInfo.fY + 35, 50, 50);
		break;
	case UI_TYPE::BUTTON::MORTAR_BTN:
		m_pTowerKey = TEXT("MortarTower");
		m_tTowerInfo.iCX = m_tTowerInfo.iCY = 160;
		m_iPrice = MortarPrice;
		MakeRect(m_tFontRect, m_tInfo.fX + 40, m_tInfo.fY + 30, 50, 50);
		break;
	default:
		break;
	}
}

void TowerUI::Ready()
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, (m_tInfo.iCX>>2)+20, (m_tInfo.iCY >> 2)+20);
	m_tFrame.iEnd = 2;
}

void TowerUI::LateUpdate()
{
	POINT pt = KEY_MGR->Mouse_Point();

	if (IsPointInCircle(pt, m_tColliderRC))
	{
		if (KEY_MGR->Key_DOWN(VK_LBUTTON) )
		{
			SOUND_MGR->PlaySound(SOUND_ID::BUTTON2);
			isClick = true;
		}
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

			// 여기서 플레이어 생성하자, true이면 돈계산하기
			if (TILE_MGR->Create_Tower(KEY_MGR->Mouse_Point(), m_tBtn, m_pTowerKey))
			{
				//USER_MGR->Set_Buy(m_iPrice);
				SOUND_MGR->PlaySound(SOUND_ID::UPGRADE);
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
	ButtonUI::Render(hDC);

	ButtonUI::Render_Debug(hDC, m_tRect, Rectangle);
	ButtonUI::Render_Debug(hDC, m_tColliderRC, Ellipse, RGB(255, 0, 0));

	// Font
	TCHAR m_Tmp[128];
	_stprintf_s(m_Tmp, 128, TEXT("$ %d"), m_iPrice);
	FONT_MGR->FontDraw(hDC, m_Tmp, m_tFontRect, BLACK_COLOR, TEXT("고딕"), 30, FW_BOLD);


	if (isClick)
	{
		MakeRect(m_tTowerRect, m_tTowerInfo);

		Render_Alpha(hDC, m_tTowerRect, m_tTowerInfo.iCX, m_Color, Ellipse);
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
