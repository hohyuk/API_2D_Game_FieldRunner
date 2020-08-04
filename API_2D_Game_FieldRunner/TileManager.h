#pragma once

class TileManager final
{
public:
	vector<GameObject*> Get_Tile() { return m_vecTile; }			// �ε������� ���ϰ� ��������
	void Change_TileType(const POINT& pt, OBJECT::TILE_TYPE _eID);

public:
	static TileManager*  Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new TileManager;
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
	void Ready();
	void Render(const HDC& hDC);
	void Release();

private:
	bool IsIndexState(const POINT& pt, int& index);
private:
	explicit TileManager();
	~TileManager();
private:
	static TileManager* m_pInstance;
	vector<GameObject*> m_vecTile;
};

