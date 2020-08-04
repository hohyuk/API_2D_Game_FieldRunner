#include "framework.h"
#include "LogoScene.h"

void LogoScene::Ready()
{
	m_szBGKey = TEXT("LogoTitle");
	// Sound
	SOUND_MGR->StopAll();
	SOUND_MGR->PlayBGM(SoundManager::CHANNELID::LOGO_BGM);

	int iSrcX = 128, iSrcY = 64;
	int iCX = iSrcX * 3;
	int iCY = iSrcY * 3;

	Create_UI(TEXT("Play_Button"), INFO(166, 860, iCX, iCY + 30, iSrcX, iSrcY),
		UI_TYPE::CLASS_ID::LOGO_UI, UI_TYPE::BUTTON::PLAY_BTN);

	Create_UI(TEXT("Resume_Button"), INFO(440, 860, iCX + 20, iCY + 25, iSrcX, iSrcY),
		UI_TYPE::CLASS_ID::LOGO_UI, UI_TYPE::BUTTON::END_BTN);

	Create_UI(TEXT("Help_Button"), INFO(740, 865, iCX - 15, iCY + 20, iSrcX, iSrcY),
		UI_TYPE::CLASS_ID::LOGO_UI, UI_TYPE::BUTTON::HELP_BTN);

	Create_UI(TEXT("Scores_Button"), INFO(1010, 865, iCX + 10, iCY + 25, iSrcX, iSrcY),
		UI_TYPE::CLASS_ID::LOGO_UI, UI_TYPE::BUTTON::SCORE_BTN);

	Create_UI(TEXT("More_Button"), INFO(1290, 860, iCX, iCY + 25, iSrcX, iSrcY),
		UI_TYPE::CLASS_ID::LOGO_UI, UI_TYPE::BUTTON::EDIT_BTN);
}

void LogoScene::Update()
{
	OBJ_MGR->Update();
}

void LogoScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
}

void LogoScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);

	OBJ_MGR->Render(hDC);
}

void LogoScene::Release()
{
	OBJ_MGR->Delete_Object(OBJECT::UI);
}

LogoScene::LogoScene()
{
	cout << "LogoScene Create()" << endl;
}

LogoScene::~LogoScene()
{
	Release();
	cout << "LogoScene Release()" << endl;
}
