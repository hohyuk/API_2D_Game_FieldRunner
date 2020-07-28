#pragma once
class BitMap;
class BmpManager final
{
public:
	HDC Find_Image(const TCHAR* _pKey);
	void Insert_Texture(const TCHAR* _pKey, const TCHAR* _pFilePath);
	void Release();
public:
	static BmpManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new BmpManager;
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
private:
	explicit BmpManager();
	~BmpManager();

private:
	static BmpManager* m_pInstance;
	map<const TCHAR*, BitMap*> m_mapBmp;
};