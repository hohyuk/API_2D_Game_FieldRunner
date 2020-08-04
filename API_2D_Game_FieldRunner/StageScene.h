#pragma once
#include "Scene.h"
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
	void Fixed_UI(const HDC & hDC, const TCHAR * _pKey, int x, int y, int cx, int cy);
	void Fixed_UI(const HDC& hDC, const TCHAR * _pKey, int x, int y, int cx, int cy, int wSrc, int hSrc);
};

