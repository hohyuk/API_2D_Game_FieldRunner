#include "framework.h"
#include "LogoScene.h"

void LogoScene::Ready()
{
	m_szBGKey = TEXT("LogoTitle");
	Create_UI(TEXT("Play_Button"), INFO(300, 300, 128, 64), UI_TYPE::ID::LOGO_UI, UI_TYPE::BUTTON::PLAY_BTN);
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

	RECT rc;
	MakeRect(rc, INFO(50, 790, 128, 64));
	HDC hMemDC = BMP_MGR->Find_Image(TEXT("Play_Button"));
	GdiTransparentBlt(hDC, rc.left, rc.top,
		128*3 - 20, 64*3 + 26, hMemDC, 0, 0,
		128, 64, PINK_COLOR);
}

void LogoScene::Release()
{
}

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
	Release();
}
