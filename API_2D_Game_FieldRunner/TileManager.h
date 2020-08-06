#pragma once

class AStar;
class TileManager final
{
public:
	vector<GameObject*> Get_Tile() { return m_vecTile; }			// 인덱스값을 편하게 쓰기위함
	void Change_TileType(const POINT& pt, OBJECT::TILE_TYPE _eID);
	bool Create_Tower(const POINT& pt, UI_TYPE::BUTTON _type, const TCHAR* _pKey);
	bool IsBuild(const POINT& pt);
	void Remove_TowerIndex(int _index);
	int Get_TileIndex(const float& fX, const float& fY);
public:
	static TileManager* Get_Instance()
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
	void Console_TileState();
private:
	explicit TileManager();
	~TileManager();
private:
	static TileManager* m_pInstance;
	vector<GameObject*> m_vecTile;

	AStar* m_pAStar{ nullptr };
};

