#include "framework.h"
#include "EditScene.h"
#include "TileManager.h"
void EditScene::Ready()
{
	m_szBGKey = TEXT("GrasslandsStage");
	TILE_MGR->Ready();

	Create_UI(TEXT("Option"), INFO(450, 900, 128, 128), UI_TYPE::CLASS_ID::OPTION_UI, UI_TYPE::BUTTON::EXIT_BTN);
}

void EditScene::Update()
{
	OBJ_MGR->Update();
}

void EditScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();

	if (KEY_MGR->Key_DOWN('1'))
	{
		m_szBGKey = TEXT("GrasslandsStage");
	}
	if (KEY_MGR->Key_DOWN('2'))
	{
		m_szBGKey = TEXT("VolcanoStage");
	}
	if (KEY_MGR->Key_DOWN('3'))
	{
		m_szBGKey = TEXT("CaveStage");
	}
	if (KEY_MGR->Key_DOWN('Q'))
	{
		isStartPointButton = !isStartPointButton;
	}
	if (KEY_MGR->Key_DOWN('W'))
	{
		isStartPointButton = !isStartPointButton;
	}
	if (KEY_MGR->Key_DOWN('S'))
	{
		if (Compare_Key(m_szBGKey, TEXT("GrasslandsStage")))
			FILE_MGR->SaveData(FileManager::TILE_STAGE1);
		if (Compare_Key(m_szBGKey, TEXT("VolcanoStage")))
			FILE_MGR->SaveData(FileManager::TILE_STAGE2);
		if (Compare_Key(m_szBGKey, TEXT("CaveStage")))
			FILE_MGR->SaveData(FileManager::TILE_STAGE3);
	}

	if (KEY_MGR->Key_DOWN(VK_LBUTTON))
	{
		if (isStartPointButton)
			TILE_MGR->Change_TileType(KEY_MGR->Mouse_Point(), OBJECT::TILE_TYPE::START_POINT);
		else
			TILE_MGR->Change_TileType(KEY_MGR->Mouse_Point(), OBJECT::TILE_TYPE::NOT_TOWER_INSTALL);
	}
	if (KEY_MGR->Key_DOWN(VK_RBUTTON))
	{
		if (isStartPointButton)
			TILE_MGR->Change_TileType(KEY_MGR->Mouse_Point(), OBJECT::TILE_TYPE::ARRIVAL_POINT);
		else
			TILE_MGR->Change_TileType(KEY_MGR->Mouse_Point(), OBJECT::TILE_TYPE::LANDMARK);
	}
}

void EditScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);

	TILE_MGR->Render(hDC);

	OBJ_MGR->Render(hDC);
}

void EditScene::Release()
{
	TileManager::Destroy_Instance();
	OBJ_MGR->Delete_Object(OBJECT::UI);
}

EditScene::EditScene()
{
}

EditScene::~EditScene()
{
	Release();
}
