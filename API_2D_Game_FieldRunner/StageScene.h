#pragma once
#include "Scene.h"
class StageScene :
	public Scene
{
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Ready() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit StageScene();
	virtual~StageScene();
};
