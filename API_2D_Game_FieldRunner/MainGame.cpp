#include "framework.h"
#include "MainGame.h"

#include "SceneManager.h"
#include "InsertBitMap.h"


void MainGame::Ready()
{
	m_hDC = GetDC(g_hWND);
	Insert_BitMap();		// BitMap ���ҽ��� �ҷ��� Map�� ���� �����Ѵ�.

	KEY_MGR->Ready();
	SCENE_MGR->Change_Scene(SceneManager::LOGO);
}

void MainGame::Update()
{
	KEY_MGR->Update();
	SCENE_MGR->Update();
}

void MainGame::LateUpdate()
{
	SCENE_MGR->LateUpdate();
}

void MainGame::Render()
{
	TIME_MGR->Set_SecTimeLoop();

	/* ������۸��ϱ� ���� BackBuffer���ٰ� ���� �׸���.*/
	HDC hBackDC = BMP_MGR->Find_Image(TEXT("BackBuffer"));	//BackBuffer���ٰ� �׸� �� m_hDC�� �������� ����
	///////////////////////////////////////////

	//// RenderBox_OnOff
	//if (KEY_MGR->Key_DOWN('D'))
	//	USER_MGR->Set_DebugRenderBox();

	SCENE_MGR->Render(hBackDC);
	//TIME_MGR->Measure_FPS();
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
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
