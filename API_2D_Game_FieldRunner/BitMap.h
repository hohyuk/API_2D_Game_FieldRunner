#pragma once
class BitMap final
{
public:
	void LoadBmp(const TCHAR* pFileName);
	HDC Get_MemDC()const { return m_MemDC; }
	void Release();

public:
	explicit BitMap();
	~BitMap();

private:
	HDC			m_MemDC;
	HBITMAP		m_bitMap, m_oldbitMap;
};