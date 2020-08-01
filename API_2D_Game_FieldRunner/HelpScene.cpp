#include "framework.h"
#include "HelpScene.h"


void HelpScene::Ready()
{
	m_szBGKey = TEXT("Help1");
	int iSrcX = 88, iSrcY = 242;
	int iCX = iSrcX * 2;
	int iCY = iSrcY * 2;
	Create_UI(TEXT("Next"), INFO(200, 460, iCX, iCY + 30, iSrcX, iSrcY),
		UI_TYPE::ID::LOGO_UI, UI_TYPE::BUTTON::PLAY_BTN);
	//Create_UI(TEXT("Back"), BUTTON_INFO{ 60,245,100,200,88,242,RECT{ 75,258,150,430 } });
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
