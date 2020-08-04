#include "framework.h"
#include "MainGame.h"

#include "SceneManager.h"
#include "TileManager.h"
#include "ObjectManager.h"
#include "InsertBitMap.h"

void MainGame::Ready()
{
	m_hDC = GetDC(g_hWND);
	Insert_BitMap();		// BitMap ���ҽ��� �ҷ��� Map�� ���� �����Ѵ�.

	KEY_MGR->Ready();
	//SCENE_MGR->Change_Scene(SceneManager::LOGO);
	//SCENE_MGR->Change_Scene(SceneManager::HELP);
	//SCENE_MGR->Change_Scene(SceneManager::SELECT);
	SCENE_MGR->Change_Scene(SceneManager::EDIT);

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
		USER_MGR->Set_GameState(USER_ID::DBUG_RENDER_BOX);
}

void MainGame::Render()
{
	TIME_MGR->Set_SecTimeLoop();

	/* ������۸��ϱ� ���� BackBuffer���ٰ� ���� �׸���.*/
	HDC hBackDC = BMP_MGR->Find_Image(TEXT("BackBuffer"));	//BackBuffer���ٰ� �׸� �� m_hDC�� �������� ����
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
