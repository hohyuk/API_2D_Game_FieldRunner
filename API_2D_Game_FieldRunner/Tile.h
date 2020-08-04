#pragma once
#include "GameObject.h"
class Tile final :
	public GameObject
{
public:
	void Set_TileType(OBJECT::TILE_TYPE _eID) { m_TileType = _eID; }
	OBJECT::TILE_TYPE Get_TileType()const { return m_TileType; }
public:
	// GameObject을(를) 통해 상속됨
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit Tile();
	virtual ~Tile();

private:
	void SelectColor();
private:
	OBJECT::TILE_TYPE m_TileType{ OBJECT::TILE_TYPE::NONE };
	DWORD m_dwColor;
};

