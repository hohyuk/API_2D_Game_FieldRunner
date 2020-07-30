#include "framework.h"
#include "LogoScene.h"

void LogoScene::Ready()
{
	m_szBGKey = TEXT("LogoTitle");
	Create_UI(TEXT("Play_Button"), INFO(166, 860, 128 * 3, 64 * 3 + 30, 128, 64),
		UI_TYPE::ID::LOGO_UI, UI_TYPE::BUTTON::PLAY_BTN);
}

void LogoScene::Update()
{
	OBJ_MGR->Update();
}

void LogoScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
}

void LogoScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);

	OBJ_MGR->Render(hDC);
}

void LogoScene::Release()
{
	OBJ_MGR->Delete_Object(OBJECT::UI);
}

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
	Release();
}
