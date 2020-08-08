#include "framework.h"
#include "Tower.h"

#include "TileManager.h"
#include "ObjectManager.h"
#include "Enemy.h"
#include "GooBullet.h"
#include "FlameBullet.h"
#include "MortarBullet.h"

bool Tower::isTowerClick{ false };

void Tower::Ready()
{
	m_tInfo.iCX = m_tInfo.iCY = 200;
	m_tFrame.iStart = 0;
	m_tFrame.iEnd = 36;
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_ClickRangeRect, m_tInfo, 150, 150);
	MakeRect(m_SellRect, m_tInfo.fX - 100, m_tInfo.fY, 50, 50);
	MakeRect(m_UpgradeRect, m_tInfo.fX + 100, m_tInfo.fY, 50, 50);

	UpgradeTower();
}

int Tower::Update()
{
	Attack_EnemyRanger();

	POINT pt = KEY_MGR->Mouse_Point();
	Click_Tower(pt);
	UnClick_Tower(pt);
	
	Click_Upgrage(pt);
	if(Click_Sell(pt)) return OBJ_DEAD;
	return OBJ_NOEVENT;
}

void Tower::LateUpdate()
{
}

void Tower::Render(const HDC & hDC)
{
	// Click - Sell, Upgrade
	if (isClick)
	{
		Render_Debug(hDC, m_ClickRangeRect, Ellipse, RGB(255, 0, 0));
		Render_Alpha(hDC, m_AttackRangeRect, m_iAttackRange, RGB(1, 250, 1), Ellipse);

		Render_Debug(hDC, m_SellRect, Ellipse, RGB(255, 0, 0));
		Render_TowerUI(hDC, TEXT("Sell"), m_SellRect.left - 5, m_SellRect.top - 5, 133, 117);
		TCHAR m_Tmp[128];

		_stprintf_s(m_Tmp, 128, TEXT("$ %d"), m_iPriceArr[PRICE::SELL]);
		FONT_MGR->FontDraw(hDC, m_Tmp, m_SellRect.right - 50, m_SellRect.bottom - 30, BLACK_COLOR, TEXT("���"), 30, FW_BOLD);

	
		if (m_Level != MAX_TOWER_LEVEL)
		{
			Render_Debug(hDC, m_UpgradeRect, Ellipse, RGB(255, 0, 0));
			Render_TowerUI(hDC, TEXT("Upgrade"), m_UpgradeRect.left - 5, m_UpgradeRect.top - 5, 120, 117, m_UpgradePossibe);

			_stprintf_s(m_Tmp, 128, TEXT("$ %d"), m_iPriceArr[PRICE::UPGRADE]);
			FONT_MGR->FontDraw(hDC, m_Tmp, m_UpgradeRect.right - 45, m_UpgradeRect.bottom - 30, BLACK_COLOR, TEXT("���"), 30, FW_BOLD);
		}	
	}

	Actor::Render(hDC);
}

void Tower::Release()
{
}

void Tower::CreateBullet(BULLET_ID eID, float fX, float fY, float rad)
{
	GameObject* pInstance = nullptr;

	switch (eID)
	{
	case Tower::GOO_BULLET:
		pInstance = AbstractFactory<GooBullet>::Create(TEXT("Goo_Bullet"), fX, fY);
		break;
	case Tower::FLAME1_BULLET:
		pInstance = AbstractFactory<GooBullet>::Create(TEXT("FireBullet1"), fX, fY);
		break;
	case Tower::FLAME2_BULLET:
		pInstance = AbstractFactory<GooBullet>::Create(TEXT("FireBullet2"), fX, fY);
		break;
	case Tower::MORTAR_BULLET:
		break;
	default:
		break;
	}

	if (nullptr == pInstance) return;

	dynamic_cast<Bullet*>(pInstance)->Set_Attack(m_iAttack);
	dynamic_cast<Bullet*>(pInstance)->Set_RadianAngle(rad);
	OBJ_MGR->Add_Object(pInstance, OBJECT::BULLET);
}

void Tower::Click_Tower(const POINT & pt)
{
	// static������ ���� ��ü Ÿ�� �� �Ѱ� Ŭ�������� ����
	if (isTowerClick)return;

	if (IsPointInRect(pt, m_tColliderRC))
	{
		if (KEY_MGR->Key_DOWN(VK_LBUTTON))
		{
			m_eRenderID = OBJECT::RENDER::CLICK_TOWER;
			isClick = true;
			isTowerClick = true;
		}
	}
}

void Tower::UnClick_Tower(const POINT & pt)
{
	if (!IsPointInCircle(pt, m_ClickRangeRect) && isClick)
	{
		m_eRenderID = OBJECT::RENDER::GROUND_OBJECT_RENDER;
		isClick = false;
		isTowerClick = false;
	}
}

void Tower::Click_Upgrage(const POINT & pt)
{
	if (m_Level == MAX_TOWER_LEVEL) return;

	if (USER_MGR->Get_Gold() < m_iPriceArr[PRICE::UPGRADE])
	{
		m_UpgradePossibe = 0;
		return;
	}

	m_UpgradePossibe = 1;
	if (IsPointInCircle(pt, m_UpgradeRect) && isClick)
	{
		if (KEY_MGR->Key_DOWN(VK_LBUTTON))
		{
			USER_MGR->Set_Buy(m_iPriceArr[PRICE::UPGRADE]);
			UpgradeTower();
			SOUND_MGR->PlaySound(SOUND_ID::UPGRADE);
		}
	}
}

bool Tower::Click_Sell(const POINT & pt)
{
	if (IsPointInCircle(pt, m_SellRect) && isClick)
	{
		if (KEY_MGR->Key_DOWN(VK_LBUTTON))
		{
			isTowerClick = false;
			TILE_MGR->Remove_TowerIndex(m_iIndex);
			USER_MGR->Set_Sell(m_iPriceArr[PRICE::SELL]);
			SOUND_MGR->PlaySound(SOUND_ID::SELL);
			return true;
		}
	}
	return false;
}

void Tower::Attack_EnemyRanger()
{
	// ������ ������ ��
	if (USER_MGR->Get_GameStop()) return;

	m_pTarget = OBJ_MGR->Get_Target(this, OBJECT::ENEMY);

	if (nullptr == m_pTarget || dynamic_cast<Enemy*>(m_pTarget)->IsTargetDead())
	{
		m_tFrame.iSceneFrame = m_LevelMotion;
		return;
	}

	/*������ ���콺 ���󰡱� �����*/
	m_tInfo.fDirX = m_pTarget->Get_PosX() - m_tInfo.fX;
	m_tInfo.fDirY = m_pTarget->Get_PosY() - m_tInfo.fY;

	float fDist = sqrt(m_tInfo.fDirX * m_tInfo.fDirX + m_tInfo.fDirY * m_tInfo.fDirY);

	Attack(fDist);
}

void Tower::TowerAnim()
{
	// ���� ������ ���� ���ϱ�
	int degree = static_cast<int>(atan2f(m_tInfo.fDirY, m_tInfo.fDirX) * RADIAN);
	degree = (degree + 90) / 10;	// �̹��� ���� �°�
	m_tFrame.iStart = Wrap(0, degree, 36);
}

void Tower::Render_TowerUI(const HDC & hDC, const TCHAR * _pKey, int x, int y, int cx, int cy, int _state)
{
	HDC hMemDC = BMP_MGR->Find_Image(_pKey);
	GdiTransparentBlt(hDC, x, y, cx, cy, hMemDC, cx * _state, 0, cx, cy, RGB(255, 0, 255));
}

void Tower::Render_TowerUI(const HDC & hDC, const TCHAR * _pKey, int x, int y, int w, int h, int _wSrc, int _hSrc, int _state /* = 0*/)
{
	HDC hMemDC = BMP_MGR->Find_Image(_pKey);
	GdiTransparentBlt(hDC, x, y, w, h, hMemDC, _wSrc * _state, 0, _wSrc, _hSrc, RGB(255, 0, 255));
}

Tower::Tower()
{
	m_eRenderID = OBJECT::RENDER::GROUND_OBJECT_RENDER;
}


Tower::~Tower()
{
	Release();
}
