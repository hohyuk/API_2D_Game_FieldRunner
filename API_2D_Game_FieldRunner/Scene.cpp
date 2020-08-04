#include "framework.h"
#include "Scene.h"

#include "ButtonUI.h"
#include "LogoUI.h"
#include "HelpUI.h"
#include "ExitUI.h"
#include "SelectUI.h"
#include "OptionUI.h"
#include "TowerUI.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Create_UI(const TCHAR * _key, INFO _info, UI_TYPE::CLASS_ID eID, UI_TYPE::BUTTON eBtn /* = UI_TYPE::BUTTON::END_BTN */)
{
	GameObject* pTempObj = nullptr;
	switch (eID)
	{
	case UI_TYPE::LOGO_UI:
		pTempObj = AbstractFactory<LogoUI>::Create(_key,_info);
		break;
	case UI_TYPE::HELP_UI:
		pTempObj = AbstractFactory<HelpUI>::Create(_key, _info);
		break;
	case UI_TYPE::EXIT_UI:
		pTempObj = AbstractFactory<ExitUI>::Create(_key, _info);
		break;
	case UI_TYPE::SELECT_UI:
		pTempObj = AbstractFactory<SelectUI>::Create(_key, _info);
		break;
	case UI_TYPE::OPTION_UI:
		pTempObj = AbstractFactory<OptionUI>::Create(_key, _info);
		break;
	case UI_TYPE::TOWER_UI:
		pTempObj = AbstractFactory<TowerUI>::Create(_key, _info);
		break;
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
