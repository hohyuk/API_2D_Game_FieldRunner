#include "framework.h"
#include "GrasslandsScene.h"

void GrasslandsScene::Ready()
{
	m_szBGKey = TEXT("GrasslandsStage");
	StageScene::Ready();
}

void GrasslandsScene::Update()
{
	OBJ_MGR->Update();
}

void GrasslandsScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);
	OBJ_MGR->Render(hDC);
}

GrasslandsScene::GrasslandsScene()
{
}

GrasslandsScene::~GrasslandsScene()
{
}
