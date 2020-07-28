#include "framework.h"
#include "MainGame.h"

#include "InsertBitMap.h"


void MainGame::Ready()
{
	m_hDC = GetDC(g_hWND);
	Insert_BitMap();		// BitMap ���ҽ��� �ҷ��� Map�� ���� �����Ѵ�.
}

void MainGame::Update()
{
}

void MainGame::LateUpdate()
{
}

void MainGame::Render()
{
	/* ������۸��ϱ� ���� BackBuffer���ٰ� ���� �׸���.*/
	HDC hBackDC = BMP_MGR->Find_Image(TEXT("BackBuffer"));	//BackBuffer���ٰ� �׸� �� m_hDC�� �������� ����
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
