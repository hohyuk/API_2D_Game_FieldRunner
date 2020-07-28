#include "framework.h"
#include "BitMap.h"

void BitMap::LoadBmp(const TCHAR* pFileName)
{
	HDC hDC = GetDC(g_hWND);	// DC�� ������

	// ��ȭ�� �غ�.
	m_MemDC = CreateCompatibleDC(hDC);
	ReleaseDC(g_hWND, hDC);		//m_MemDC�� �޾ƿ����� ���������ش�.

	// ���� �غ�.
	m_bitMap = (HBITMAP)LoadImage(nullptr, pFileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	if (!m_bitMap)
	{
		MESSAGE_BOX(pFileName, TEXT("BitMap::LoadBmp(Image Load Failed)"));
		return;
	}
	// ���⿡ �׸��� �׸�
	m_oldbitMap = (HBITMAP)SelectObject(m_MemDC, m_bitMap);
}

void BitMap::Release()
{
	// ���õǾ� �ִ� GDI������Ʈ�� ����� �ִ� ����� ����.
	// �׷��� ���� �ִ������� ���� ���� �ְ� ���� ����� ���� �����. 
	// �׷��� OldBitmap�̶�³���� �����. 
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
