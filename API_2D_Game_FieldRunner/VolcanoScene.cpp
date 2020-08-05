#include "framework.h"
#include "VolcanoScene.h"

void VolcanoScene::Ready()
{
	m_szBGKey = TEXT("VolcanoStage");
	StageScene::Ready();
}

void VolcanoScene::Update()
{
}

void VolcanoScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);
}

VolcanoScene::VolcanoScene()
{
}

VolcanoScene::~VolcanoScene()
{
}
