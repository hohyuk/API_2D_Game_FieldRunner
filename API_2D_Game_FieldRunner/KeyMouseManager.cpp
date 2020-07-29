#include "framework.h"
#include "KeyMouseManager.h"

KeyMouseManager* KeyMouseManager::m_pInstance{ nullptr };
POINT KeyMouseManager::Mouse_Point()
{
	return POINT();
}
bool KeyMouseManager::Key_UP(int iKey)
{
	return false;
}
bool KeyMouseManager::Key_DOWN(int iKey)
{
	return false;
}
bool KeyMouseManager::Key_Pressing(int iKey)
{
	return false;
}
bool KeyMouseManager::ToggleKeyDown(int KeyCode)
{
	return false;
}
void KeyMouseManager::Ready()
{
}
void KeyMouseManager::Update()
{
}
void KeyMouseManager::Render(const HDC & hDC)
{
}
KeyMouseManager::KeyMouseManager()
{
}

KeyMouseManager::~KeyMouseManager()
{
}
