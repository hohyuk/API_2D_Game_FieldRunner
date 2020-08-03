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

	if (KEY_MGR->Key_DOWN(VK_LBUTTON))
	{
		TILE_MGR->StartPointTile(KEY_MGR->Mouse_Point());
	}
	if (KEY_MGR->Key_DOWN(VK_RBUTTON))
	{
		TILE_MGR->EndPointTile(KEY_MGR->Mouse_Point());
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
