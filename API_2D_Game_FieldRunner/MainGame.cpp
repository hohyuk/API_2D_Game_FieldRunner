#include "framework.h"
#include "MainGame.h"

#include "InsertBitMap.h"


void MainGame::Ready()
{
	m_hDC = GetDC(g_hWND);
	Insert_BitMap();		// BitMap 리소스를 불러서 Map에 먼저 저장한다.
}

void MainGame::Update()
{
}

void MainGame::LateUpdate()
{
}

void MainGame::Render()
{
	/* 더블버퍼링하기 위해 BackBuffer에다가 먼저 그린다.*/
	HDC hBackDC = BMP_MGR->Find_Image(TEXT("BackBuffer"));	//BackBuffer에다가 그린 후 m_hDC에 최종으로 보냄
	///////////////////////////////////////////

	//// RenderBox_OnOff
	//if (KEY_MGR->Key_DOWN('D'))
	//	USER_MGR->Set_DebugRenderBox();

	//SCENE_MGR->Render(hBackDC);
	//TIME_MGR->Measure_FPS();
	//KEY_MGR->Render(hBackDC);
	/////////////////////////////////////////
	BitBlt(m_hDC, 0, 0, WINCX, WINCY, hBackDC, 0, 0, SRCCOPY);
}

void MainGame::Release()
{
	ReleaseDC(g_hWND, m_hDC);
	BmpManager::Destroy_Instance();
}

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
	Release();
}
