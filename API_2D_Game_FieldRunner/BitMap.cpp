#include "framework.h"
#include "BitMap.h"

void BitMap::LoadBmp(const TCHAR* pFileName)
{
	HDC hDC = GetDC(g_hWND);	// DC를 얻어오기

	// 도화지 준비.
	m_MemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWND, hDC);		//m_MemDC로 받아왔으니 해제시켜준다.

	// 물감 준비.
	m_bitMap = (HBITMAP)LoadImage(nullptr, pFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (!m_bitMap)
	{
		MESSAGE_BOX(pFileName, TEXT("BitMap::LoadBmp(Image Load Failed)"));
		return;
	}
	// 여기에 그림을 그림
	m_oldbitMap = (HBITMAP)SelectObject(m_MemDC, m_bitMap);
}

void BitMap::Release()
{
	// 선택되어 있는 GDI오브젝트는 지울수 있는 방법이 없다.
	// 그래서 원래 있던놈으로 끼워 집어 넣고 내가 만든걸 지워 줘야함. 
	// 그래서 OldBitmap이라는놈까지 만든거. 
	SelectObject(m_MemDC, m_oldbitMap);
	DeleteObject(m_bitMap);
	DeleteDC(m_MemDC);
}

BitMap::BitMap()
{
}

BitMap::~BitMap()
{
	Release();
}
