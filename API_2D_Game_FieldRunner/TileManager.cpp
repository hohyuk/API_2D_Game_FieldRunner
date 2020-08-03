#include "framework.h"
#include "TileManager.h"

#include "Tile.h"

TileManager* TileManager::m_pInstance{ nullptr };

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

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
	Release();
}
