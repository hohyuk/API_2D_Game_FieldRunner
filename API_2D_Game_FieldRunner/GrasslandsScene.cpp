#include "framework.h"
#include "GrasslandsScene.h"

void GrasslandsScene::Ready()
{
	m_szBGKey = TEXT("GrasslandsStage");
}

void GrasslandsScene::Update()
{
}

void GrasslandsScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);
}

GrasslandsScene::GrasslandsScene()
{
}

GrasslandsScene::~GrasslandsScene()
{
}
