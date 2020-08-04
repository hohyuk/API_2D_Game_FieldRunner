#pragma once
class FileManager
{
public:
	enum ID { TILE_STAGE1, TILE_STAGE2, TILE_STAGE3, SCORE1, SCORE2, SCORE3, END };
public:
	void SaveData(ID eID);
	void Load_Data(ID eID);
public:
	static FileManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new FileManager;
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
	const TCHAR* DataPath(ID eID);
	void NewFile(ID eID);		// 파일이 없을시 만들기
private:
	explicit FileManager();
	~FileManager();
private:
	static FileManager* m_pInstance;
};

