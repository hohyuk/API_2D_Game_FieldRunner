#pragma once
#include "GameObject.h"
class Tile final :
	public GameObject
{
public:
	void IsNotTowerInstall() { isNotTowerInstall = !isNotTowerInstall; }
	void IsStartPoint() { isStartPoint = !isStartPoint; }
	void IsEndPoint() { isEndPoint = !isEndPoint; }

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
	bool isNotTowerInstall{ false };	//  true인 곳은 타일 검색 시작점 과 끝점
	bool isStartPoint{ false };
	bool isEndPoint{ false };
	DWORD m_dwColor;
};

