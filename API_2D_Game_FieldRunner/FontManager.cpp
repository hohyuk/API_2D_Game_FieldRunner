#include "framework.h"
#include "FontManager.h"

FontManager* FontManager::m_pInstance{ nullptr };

void FontManager::FontDraw(const HDC & hDC, const TCHAR * _szOut, int x, int y, DWORD _color, LPCWSTR pszFaceName, int _cHeight, int _fontWeight)
{
	m_hFont = CreateFont(_cHeight, 0, 0, 0, _fontWeight, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, pszFaceName);
	m_oldFont = (HFONT)SelectObject(hDC, m_hFont);
	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, _color);
	TextOut(hDC, x, y, _szOut, _tcslen(_szOut));
	SelectObject(hDC, m_oldFont);
	DeleteObject(m_hFont);
}

void FontManager::FontDraw(const HDC & hDC, const TCHAR * _szOut, RECT _rc, DWORD _color, LPCWSTR pszFaceName, int _cHeight, int _fontWeight)
{
	m_hFont = CreateFont(_cHeight, 0, 0, 0, _fontWeight, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, pszFaceName);
	m_oldFont = (HFONT)SelectObject(hDC, m_hFont);
	SetBkMode(hDC, TRANSPARENT);
	SetTextColor(hDC, _color);
	DrawText(hDC, _szOut, -1, &_rc, DT_SINGLELINE | DT_VCENTER | DT_NOCLIP);
	SelectObject(hDC, m_oldFont);
	DeleteObject(m_hFont);
}

FontManager::FontManager()
{
}

FontManager::~FontManager()
{
}
