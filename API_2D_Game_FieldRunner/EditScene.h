#pragma once
#include "Scene.h"
class EditScene :
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
	explicit EditScene();
	virtual~EditScene();

private:
	bool isStartPointButton{ false };
};

