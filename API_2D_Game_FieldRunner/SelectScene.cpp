#include "framework.h"
#include "SelectScene.h"

void SelectScene::Ready()
{
	m_szBGKey = TEXT("SelectTitle");

	Create_UI(TEXT("Exit"), INFO(1300, 110, 88 * 2 - 30, 84 * 2 - 40, 88, 84),
		UI_TYPE::CLASS_ID::EXIT_UI, UI_TYPE::BUTTON::EXIT_BTN);

	Create_UI(TEXT("Grasslands_icon"), INFO(500, 350, 400, 300, 400, 300),
		UI_TYPE::CLASS_ID::SELECT_UI, UI_TYPE::BUTTON::STAGE1_BTN);

	Create_UI(TEXT("lavaflow_icon"), INFO(1000, 350, 400, 300, 400, 300),
		UI_TYPE::CLASS_ID::SELECT_UI, UI_TYPE::BUTTON::STAGE2_BTN);

	Create_UI(TEXT("Cave_icon"), INFO(750, 650, 400, 300, 400, 300),
		UI_TYPE::CLASS_ID::SELECT_UI, UI_TYPE::BUTTON::STAGE3_BTN);
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
	cout << "SelectScene Create()" << endl;
}

SelectScene::~SelectScene()
{
	Release();
	cout << "SelectScene Release()" << endl;
}
