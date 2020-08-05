#include "framework.h"
#include "TileManager.h"

#include "ObjectManager.h"
#include "Tile.h"
#include "Gatling.h"
#include "Goo.h"
#include "Flame.h"
#include "Mortar.h"

TileManager* TileManager::m_pInstance{ nullptr };

void TileManager::Change_TileType(const POINT & pt, OBJECT::TILE_TYPE _eID)
{
	int index = -1;
	if (!IsIndexState(pt, index)) return;

	dynamic_cast<Tile*>(m_vecTile[index])->Set_TileType(_eID);
	cout << "Index : " << index << endl;
}

bool TileManager::Create_Tower(const POINT & pt, UI_TYPE::BUTTON _type, const TCHAR * _pKey)
{
	int index = -1;
	if (!IsIndexState(pt, index)) return false;
	if (!IsBuild(pt))return false;

	// 아무 조건이 안걸렸을때 타일 생성
	dynamic_cast<Tile*>(m_vecTile[index])->Set_TileType(OBJECT::TILE_TYPE::TOWER_INSTALL);

	// 길찾기 검색후 안되면 다시 타워 삭제 후 리턴.

	// Tower
	GameObject* pTempObj = nullptr;
	switch (_type)
	{
	case UI_TYPE::BUTTON::GATLING_BTN:
		pTempObj = AbstractFactory<Gatling>::Create(_pKey, m_vecTile[index]->Get_PosX(), m_vecTile[index]->Get_PosY());
		break;
	case UI_TYPE::BUTTON::GOO_BTN:
		pTempObj = AbstractFactory<Goo>::Create(_pKey, m_vecTile[index]->Get_PosX(), m_vecTile[index]->Get_PosY());
		break;
	case UI_TYPE::BUTTON::FLAME_BTN:
		pTempObj = AbstractFactory<Flame>::Create(_pKey, m_vecTile[index]->Get_PosX(), m_vecTile[index]->Get_PosY());
		break;
	case UI_TYPE::BUTTON::MORTAR_BTN:
		pTempObj = AbstractFactory<Mortar>::Create(_pKey, m_vecTile[index]->Get_PosX(), m_vecTile[index]->Get_PosY());
		break;
	default:
		cout << "Create_Tower() Faild" << endl;
		return false;
	}

	OBJ_MGR->Add_Object(pTempObj, OBJECT::PLAYER);

	system("cls");
	cout << "Index : " << index << endl;
	Console_TileState();
	return true;
}

bool TileManager::IsBuild(const POINT & pt)
{
	int index = -1;
	if (!IsIndexState(pt, index)) return false;
	
	// 지을수 있는 곳
	if (OBJECT::TILE_TYPE::NONE == dynamic_cast<Tile*>(m_vecTile[index])->Get_TileType())
		return true;
	return false;
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

void TileManager::Console_TileState()
{
	for (int i = 0; i < TILEY; ++i)
	{
		for (int j = 0; j < TILEX; ++j)
		{
			int DrawID = dynamic_cast<Tile*>(m_vecTile[(i*TILEX) + j])->Get_TileType();
			cout << DrawID << "  ";
		}
		cout << endl;
	}
	cout << endl;
}

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
	Release();
}
