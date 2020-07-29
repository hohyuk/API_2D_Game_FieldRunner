#include "framework.h"
#include "KeyMouseManager.h"

KeyMouseManager* KeyMouseManager::m_pInstance{ nullptr };
POINT KeyMouseManager::Mouse_Point()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWND, &pt);
	return pt;
}
bool KeyMouseManager::Key_UP(int iKey)
{
	if (!Key_Pressing(iKey))
	{
		if (PrevKey == iKey)
		{
			PrevKey = NULL;
			return true;
		}
	}
	return false;
}
bool KeyMouseManager::Key_DOWN(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
	{
		if (!KeyDown[iKey])
		{
			KeyDown[iKey] = true;
			return true;
		}
	}
	else KeyDown[iKey] = false;

	return false;
}
bool KeyMouseManager::Key_Pressing(int iKey)
{
	if (GetAsyncKeyState(iKey) & 0x8000)
	{
		PrevKey = iKey;
		return true;
	}
	return false;
}
bool KeyMouseManager::ToggleKeyDown(int KeyCode)
{
	if (GetKeyState(KeyCode) & 0x0001)
		return true;
	return false;
}
void KeyMouseManager::Ready()
{
	m_tInfo.iCX = 36;
	m_tInfo.iCY = 30;
	ShowCursor(false);
}
void KeyMouseManager::Update()
{
	m_tInfo.fX = static_cast<float>(Mouse_Point().x);
	m_tInfo.fY = static_cast<float>(Mouse_Point().y);

	if(m_tInfo.fY<= m_tInfo.iCY)ShowCursor(true);
	else ShowCursor(false);
}
void KeyMouseManager::Render(const HDC & hDC)
{
	MakeRect(m_tRect, m_tInfo);

	HDC hMemDC = BMP_MGR->Find_Image(TEXT("Mouse"));
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top + 10,
		m_tInfo.iCX, m_tInfo.iCY,
		hMemDC, 0, 0,
		36, 33, PINK_COLOR);
}
KeyMouseManager::KeyMouseManager()
{
	ZeroMemory(KeyDown, sizeof(KeyDown));
	PrevKey = NULL;
}

KeyMouseManager::~KeyMouseManager()
{
}
