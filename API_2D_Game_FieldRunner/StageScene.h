#pragma once
#include "Scene.h"

// Enemy 시작 위치
const float ENEMY_POSX{ -100.f };
const float ENEMY_POSY{ 500.f };

class StageScene :
	public Scene
{
public:
	// Scene을(를) 통해 상속됨
	virtual void Ready() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit StageScene();
	virtual~StageScene();

protected:
	enum ENEMY_ID { SOLDIER, HEAVY, BIKE, ROBOT, BLIMP, TRAIN, END };
protected:
	void Fixed_UI(const HDC & hDC, const TCHAR * _pKey, int x, int y, int cx, int cy);
	void Fixed_UI(const HDC& hDC, const TCHAR * _pKey, int x, int y, int cx, int cy, int wSrc, int hSrc);

	void Create_Enemy(ENEMY_ID _eID);
	void Create_Enemy_KeyDonw();
	void Spawn_Enemy();
};

