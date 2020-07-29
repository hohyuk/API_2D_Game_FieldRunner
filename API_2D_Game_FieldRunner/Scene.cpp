#include "framework.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Render_BackGround(const HDC & hDC, int x, int y, int cx, int cy)
{
	HDC hMemDC = BMP_MGR->Find_Image(m_szBGKey);
	BitBlt(hDC, x, y, cx, cy, hMemDC, 0, 0, SRCCOPY);
}
