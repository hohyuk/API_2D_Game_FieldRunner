#include "framework.h"
#include "EditScene.h"
#include "TileManager.h"
void EditScene::Ready()
{
	m_szBGKey = TEXT("GrasslandsStage");
	TILE_MGR->Ready();

	Create_UI(TEXT("Option"), INFO(450, 900, 128, 128, 128, 128),
		UI_TYPE::CLASS_ID::OPTION_UI);
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

	if (KEY_MGR->Key_DOWN('S'))
	{
		/*if (m_eEditState == ID::GRASSLANDS_EDIT)
			FileSystem::Get_Instance()->Save_Data(FileSystem::TILE_STAGE1);
		if (m_eEditState == ID::VOLCANO_EDIT)
			FileSystem::Get_Instance()->Save_Data(FileSystem::TILE_STAGE2);
		if (m_eEditState == ID::CAVE_EDIT)
			FileSystem::Get_Instance()->Save_Data(FileSystem::TILE_STAGE3);*/
	}

	if (KEY_MGR->Key_DOWN(VK_LBUTTON))
	{
		TILE_MGR->Change_TileType(KEY_MGR->Mouse_Point(), OBJECT::TILE_TYPE::START_POINT);
	}
	if (KEY_MGR->Key_DOWN(VK_RBUTTON))
	{
		TILE_MGR->Change_TileType(KEY_MGR->Mouse_Point(), OBJECT::TILE_TYPE::ARRIVAL_POINT);
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
	OBJ_MGR->Delete_Object(OBJECT::UI);
}

EditScene::EditScene()
{
}

EditScene::~EditScene()
{
	Release();
}
