#include "framework.h"
#include "HelpScene.h"

int g_iHelpSceneOrder;

void HelpScene::Ready()
{
	m_szBGKey = TEXT("Help1");
	g_iHelpSceneOrder = 0;

	int iSrcX = 88, iSrcY = 242;
	int iCX = iSrcX + 40;
	int iCY = iSrcY + 30;
	Create_UI(TEXT("Next"), INFO(170, 520, iCX, iCY, iSrcX, iSrcY),
		UI_TYPE::CLASS_ID::HELP_UI, UI_TYPE::BUTTON::NEXT_BTN);

	Create_UI(TEXT("Back"), INFO(1290, 515, iCX, iCY, iSrcX, iSrcY),
		UI_TYPE::CLASS_ID::HELP_UI, UI_TYPE::BUTTON::BACK_BTN);

	Create_UI(TEXT("Exit"), INFO(1350, 70, 88*2, 84*2-20, 88, 84),
		UI_TYPE::CLASS_ID::EXIT_UI);
}

void HelpScene::Update()
{
	OBJ_MGR->Update();
}

void HelpScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();

	switch (g_iHelpSceneOrder)
	{
	case 0:
		m_szBGKey = TEXT("Help1");
		break;
	case 1:
		m_szBGKey = TEXT("Help2");
		break;
	case 2:
		m_szBGKey = TEXT("Help3");
		break;
	default:
		break;
	}
}

void HelpScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);

	OBJ_MGR->Render(hDC);
}

void HelpScene::Release()
{
	OBJ_MGR->Delete_Object(OBJECT::UI);
}

HelpScene::HelpScene()
{
	cout << "HelpScene Create()" << endl;
}


HelpScene::~HelpScene()
{
	Release();
	cout << "HelpScene Release()" << endl;
}
