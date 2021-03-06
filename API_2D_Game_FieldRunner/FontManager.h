#pragma once
class FontManager final
{
public:
	static FontManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new FontManager;
		return m_pInstance;
	}

	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void FontDraw(const HDC& hDC, const TCHAR* _szOut, int x, int y, DWORD _color, LPCWSTR pszFaceName, int _cHeight, int _fontWeight);
	void FontDraw(const HDC& hDC, const TCHAR* _szOut, RECT _rc, DWORD _color, LPCWSTR pszFaceName, int _cHeight, int _fontWeight);
private:
	explicit FontManager();
	~FontManager();
private:
	static FontManager* m_pInstance;

private:
	HFONT m_hFont, m_oldFont;
};

