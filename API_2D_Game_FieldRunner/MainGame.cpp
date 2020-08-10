#include "framework.h"
#include "MainGame.h"

#include "SceneManager.h"
#include "TileManager.h"
#include "ObjectManager.h"
#include "InsertBitMap.h"

void MainGame::Ready()
{
	m_hDC = GetDC(g_hWND);
	Insert_BitMap();		// BitMap 리소스를 불러서 Map에 먼저 저장한다.
	// Sound
	SOUND_MGR->Initialize();		// 사운드 초기화를 먼저해줘야한다.

	KEY_MGR->Ready();
	//SCENE_MGR->Change_Scene(SceneManager::LOGO);
	//SCENE_MGR->Change_Scene(SceneManager::HELP);
	//SCENE_MGR->Change_Scene(SceneManager::SELECT);
	//SCENE_MGR->Change_Scene(SceneManager::EDIT);
	//SCENE_MGR->Change_Scene(SceneManager::SCORE);
	SCENE_MGR->Change_Scene(SceneManager::STAGE_2);

}

void MainGame::Update()
{
	KEY_MGR->Update();
	SCENE_MGR->Update();
}

void MainGame::LateUpdate()
{
	SCENE_MGR->LateUpdate();

	// RenderBox_OnOff
	if (KEY_MGR->Key_DOWN('D'))
		USER_MGR->Set_GameState(USER_ID::DEBUG_RENDER_BOX);
}

void MainGame::Render()
{
	TIME_MGR->Set_SecTimeLoop();

	/* 더블버퍼링하기 위해 BackBuffer에다가 먼저 그린다.*/
	HDC hBackDC = BMP_MGR->Find_Image(TEXT("BackBuffer"));	//BackBuffer에다가 그린 후 m_hDC에 최종으로 보냄
	///////////////////////////////////////////

	SCENE_MGR->Render(hBackDC);
	KEY_MGR->Render(hBackDC);
	/////////////////////////////////////////
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBackDC, 0, 0, SRCCOPY);

	TIME_MGR->Measure_FPS();
}

void MainGame::Release()
{
	ReleaseDC(g_hWND, m_hDC);
	TimeManager::Destroy_Instance();
	BmpManager::Destroy_Instance();
	SceneManager::Destroy_Instance();
	KeyMouseManager::Destroy_Instance();
	TileManager::Destroy_Instance();
	ObjectManager::Destroy_Instance();
	SoundManager::Destroy_Instance();
	FontManager::Destroy_Instance();
	UserManager::Destroy_Instance();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
