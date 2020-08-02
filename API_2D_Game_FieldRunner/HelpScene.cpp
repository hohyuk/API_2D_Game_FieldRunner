#include "framework.h"
#include "HelpScene.h"


void HelpScene::Ready()
{
	m_szBGKey = TEXT("Help1");
	int iSrcX = 88, iSrcY = 242;
	int iCX = iSrcX + 40;
	int iCY = iSrcY + 30;
	Create_UI(TEXT("Next"), INFO(170, 520, iCX, iCY, iSrcX, iSrcY),
		UI_TYPE::ID::HELP_UI, UI_TYPE::BUTTON::PLAY_BTN);

	Create_UI(TEXT("Back"), INFO(1290, 515, iCX, iCY, iSrcX, iSrcY),
		UI_TYPE::ID::HELP_UI, UI_TYPE::BUTTON::PLAY_BTN);
}

void HelpScene::Update()
{
	OBJ_MGR->Update();
}

void HelpScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
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
