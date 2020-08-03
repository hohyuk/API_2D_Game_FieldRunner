#pragma once
#include "Scene.h"
class EditScene :
	public Scene
{
public:
	enum ID { GRASSLANDS_EDIT, VOLCANO_EDIT, CAVE_EDIT, NONE };
public:
	// Scene��(��) ���� ��ӵ�
	virtual void Ready() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit EditScene();
	virtual~EditScene();
};

