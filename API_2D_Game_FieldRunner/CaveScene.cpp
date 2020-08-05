#include "framework.h"
#include "CaveScene.h"

void CaveScene::Ready()
{
	m_szBGKey = TEXT("CaveStage");
	StageScene::Ready();
}

void CaveScene::Update()
{
}

void CaveScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);
}

CaveScene::CaveScene()
{
}

CaveScene::~CaveScene()
{
}
