#include "framework.h"
#include "Scene.h"

#include "ButtonUI.h"
#include "LogoUI.h"
Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Create_UI(const TCHAR * _key, INFO _info, UI_TYPE::ID eID, UI_TYPE::BUTTON eBtn)
{
	GameObject* pTempObj = nullptr;
	switch (eID)
	{
	case UI_TYPE::LOGO_UI:
		pTempObj = AbstractFactory<LogoUI>::Create(_key,_info);
		break;
	/*case UI_TYPE::GAME_UI:
		pTempObj = AbstractFactory<GameBtnUI>::Create(_key);
		break;
	case UI_TYPE::SELECT_UI:
		pTempObj = AbstractFactory<OptionBtnUI>::Create(_key);
		break;
	case UI_TYPE::COMMON_UI:
		pTempObj = AbstractFactory<MapSelectBtnUI>::Create(_key);
		break;
	case UI_TYPE::END_UI:
		break;*/
	default:
		break;
	}

	dynamic_cast<ButtonUI*>(pTempObj)->Set_ButtonType(eBtn);
	OBJ_MGR->Add_Object(pTempObj, OBJECT::UI);
}

void Scene::Render_BackGround(const HDC & hDC, int x, int y, int cx, int cy)
{
	HDC hMemDC = BMP_MGR->Find_Image(m_szBGKey);
	BitBlt(hDC, x, y, cx, cy, hMemDC, 0, 0, SRCCOPY);
}
