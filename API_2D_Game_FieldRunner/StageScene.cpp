#include "framework.h"
#include "StageScene.h"

#include "TileManager.h"
#include "Soldier.h"
#include "HeavySoldier.h"

void StageScene::Ready()
{
	SOUND_MGR->StopAll();
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
	if (KEY_MGR->Key_DOWN('T'))
		isTipShow = !isTipShow;
	if (KEY_MGR->Key_DOWN('P'))
		USER_MGR->Set_GameState(USER_ID::DEBUG_NONE_TILE);
	Create_Enemy_KeyDonw();
}

void StageScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);

	// Tile
	TILE_MGR->Render(hDC);

	OBJ_MGR->Render(hDC);

	Fixed_UI(hDC, TEXT("Money"), 30, 10, 71, 79);
	for (int i = 0; i < USER_MGR->Get_Life(); ++i)
		Fixed_UI(hDC, TEXT("Health"), (WINCX - 90) - (80 * i), 0, 90, 90);

	if (isTipShow)
		Fixed_UI(hDC, TEXT("Hud"), 0, 50, WINCX, 810);

	// Font
	TCHAR m_Tmp[128];
	RECT rc = RECT{ 100,0,200,100 };
	_stprintf_s(m_Tmp, 128, TEXT("%d"), USER_GOLD);
	FONT_MGR->FontDraw(hDC, m_Tmp, rc, RGB(240, 110, 1), TEXT("Arial Rounded MT Bold"), 70, FW_HEAVY);

	
	rc = RECT{ (WINCX>>1) - 100,0,(WINCX >> 1) + 100,100 };
	_stprintf_s(m_Tmp, 128, TEXT("SCORE %d"), USER_MGR->Get_Score());
	FONT_MGR->FontDraw(hDC, m_Tmp, rc, RGB(240, 110, 1), TEXT("Arial Rounded MT Bold"), 50, FW_MEDIUM);
}

void StageScene::Release()
{
	TileManager::Destroy_Instance();
	OBJ_MGR->Delete_Object(OBJECT::UI);
	OBJ_MGR->Delete_Object(OBJECT::ENEMY);
	OBJ_MGR->Delete_Object(OBJECT::OVERHANG);
	OBJ_MGR->Delete_Object(OBJECT::PLAYER);
	OBJ_MGR->Delete_Object(OBJECT::BULLET);
	SOUND_MGR->StopAll();
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

void StageScene::Create_Enemy(ENEMY_ID _eID)
{
	GameObject* pTempObj = nullptr;

	switch (_eID)
	{
	case StageScene::SOLDIER:
		pTempObj = AbstractFactory<Soldier>::Create(TEXT("Soldier"), ENEMY_POSX, ENEMY_POSY);
		break;
	case StageScene::HEAVY:
		pTempObj = AbstractFactory<HeavySoldier>::Create(TEXT("HeavySoldier"), ENEMY_POSX, ENEMY_POSY);
		break;
	case StageScene::BIKE:
		break;
	case StageScene::ROBOT:
		break;
	case StageScene::BLIMP:
		break;
	case StageScene::TRAIN:
		break;
	case StageScene::END:
		break;
	default:
		break;
	}

	OBJ_MGR->Add_Object(pTempObj, OBJECT::ENEMY);
}

void StageScene::Create_Enemy_KeyDonw()
{
	if (KEY_MGR->Key_DOWN('1'))
		Create_Enemy(SOLDIER);
	if (KEY_MGR->Key_DOWN('2'))
		Create_Enemy(HEAVY);
}

void StageScene::Spawn_Enemy()
{
}
