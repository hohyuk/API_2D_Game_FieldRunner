#include "framework.h"
#include "LogoScene.h"

void LogoScene::Ready()
{
	m_szBGKey = TEXT("LogoTitle");
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
