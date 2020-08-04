#include "framework.h"
#include "TileManager.h"

#include "Tile.h"

TileManager* TileManager::m_pInstance{ nullptr };

void TileManager::Change_TileType(const POINT & pt, OBJECT::TILE_TYPE _eID)
{
	int index = -1;
	if (!IsIndexState(pt, index)) return;

	dynamic_cast<Tile*>(m_vecTile[index])->Set_TileType(_eID);
	cout << "Index : " << index << endl;
}

void TileManager::Ready()
{
	float fX = 0.f, fY = 0.f;

	m_vecTile.reserve(TILEX * TILECY);

	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			fX = static_cast<float>(TILE_START_PX + (TILECX * j) + (TILECX >> 1));
			fY = static_cast<float>(TILE_START_PY + (TILECY * i) + (TILECY >> 1));
			m_vecTile.emplace_back(AbstractFactory<Tile>::Create(fX, fY));
		}
	}
}

void TileManager::Render(const HDC & hDC)
{
	for (const auto& pTile : m_vecTile)
		pTile->Render(hDC);
}

void TileManager::Release()
{
	for (auto& pTile : m_vecTile)
		Safe_Delete(pTile);

	m_vecTile.clear();
	m_vecTile.shrink_to_fit();
}

bool TileManager::IsIndexState(const POINT & pt, int & index)
{
	// 전체 Rect를 벗어나면 리턴
	if (TILE_START_PX > pt.x || TILE_START_PY > pt.y || TILE_START_PX + (TILEX* TILECX) < pt.x)
		return false;
	int x = (pt.x - TILE_START_PX) / TILECX;
	int y = (pt.y - TILE_START_PY) / TILECY;

	index = (y * TILEX) + x;

	// 현재 인덱스보다 넘어가버리면 리턴
	if (0 > index || static_cast<int>(m_vecTile.size()) <= index)	return false;

	return true;
}

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
	Release();
}
