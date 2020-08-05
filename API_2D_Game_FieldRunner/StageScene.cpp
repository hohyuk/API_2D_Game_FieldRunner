#include "framework.h"
#include "StageScene.h"

#include "TileManager.h"
void StageScene::Ready()
{
	Create_UI(TEXT("Start_Stop"), INFO(100, 900, 128, 128), UI_TYPE::CLASS_ID::OPTION_UI, UI_TYPE::BUTTON::START_BTN);
	Create_UI(TEXT("FastForward"), INFO(275, 900, 128, 128), UI_TYPE::CLASS_ID::OPTION_UI, UI_TYPE::BUTTON::FAST_BTN);
	Create_UI(TEXT("Option"), INFO(450, 900, 128, 128), UI_TYPE::CLASS_ID::OPTION_UI, UI_TYPE::BUTTON::EXIT_BTN);

	// Tower UI
	Create_UI(TEXT("Gatling"), INFO(850, 900, 133, 117), UI_TYPE::CLASS_ID::TOWER_UI, UI_TYPE::BUTTON::GATLING_BTN);
	Create_UI(TEXT("Goo"), INFO(1000, 900, 133, 117), UI_TYPE::CLASS_ID::TOWER_UI, UI_TYPE::BUTTON::GOO_BTN);
	Create_UI(TEXT("Flame"), INFO(1150, 900, 133, 117), UI_TYPE::CLASS_ID::TOWER_UI, UI_TYPE::BUTTON::FLAME_BTN);
	Create_UI(TEXT("Mortar"), INFO(1300, 900, 133, 117), UI_TYPE::CLASS_ID::TOWER_UI, UI_TYPE::BUTTON::MORTAR_BTN);

	USER_MGR->ReSet(100);
	TILE_MGR->Ready();
}

void StageScene::Update()
{
	OBJ_MGR->Update();
}

void StageScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
}

void StageScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);

	// Tile
	TILE_MGR->Render(hDC);

	OBJ_MGR->Render(hDC);

	Fixed_UI(hDC, TEXT("Money"), 30, 10, 71, 79);


	// Font
	TCHAR m_Tmp[128];
	RECT rc = RECT{ 100,0,200,100 };
	_stprintf_s(m_Tmp, 128, TEXT("%d"), USER_GOLD);
	FONT_MGR->FontDraw(hDC, m_Tmp, rc, RGB(240, 110, 1), TEXT("Arial Rounded MT Bold"), 70, FW_HEAVY);

	
	rc = RECT{ (WINCX>>1) - 100,0,(WINCX >> 1) + 100,100 };
	_stprintf_s(m_Tmp, 128, TEXT("SCORE %d"), 100);
	FONT_MGR->FontDraw(hDC, m_Tmp, rc, RGB(240, 110, 1), TEXT("Arial Rounded MT Bold"), 50, FW_MEDIUM);
}

void StageScene::Release()
{
	TileManager::Destroy_Instance();
	OBJ_MGR->Delete_Object(OBJECT::UI);
}

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
	Release();
}

void StageScene::Fixed_UI(const HDC & hDC, const TCHAR * _pKey, int x, int y, int cx, int cy)
{
	HDC hMemDC = BMP_MGR->Find_Image(_pKey);
	GdiTransparentBlt(hDC, x, y, cx, cy, hMemDC, 0, 0, cx, cy, RGB(255, 0, 255));
}

void StageScene::Fixed_UI(const HDC & hDC, const TCHAR * _pKey, int x, int y, int cx, int cy, int wSrc, int hSrc)
{
	HDC hMemDC = BMP_MGR->Find_Image(_pKey);
	GdiTransparentBlt(hDC, x, y, cx, cy, hMemDC, 0, 0, wSrc, hSrc, RGB(255, 0, 255));
}
