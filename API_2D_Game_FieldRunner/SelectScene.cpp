#include "framework.h"
#include "SelectScene.h"

void SelectScene::Ready()
{
	m_szBGKey = TEXT("SelectTitle");

	Create_UI(TEXT("Exit"), INFO(1350, 70, 88 * 2, 84 * 2 - 20, 88, 84),
		UI_TYPE::CLASS_ID::EXIT_UI);
}

void SelectScene::Update()
{
	OBJ_MGR->Update();
}

void SelectScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
}

void SelectScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);

	OBJ_MGR->Render(hDC);
}

void SelectScene::Release()
{
	OBJ_MGR->Delete_Object(OBJECT::UI);
}

SelectScene::SelectScene()
{
}

SelectScene::~SelectScene()
{
}
