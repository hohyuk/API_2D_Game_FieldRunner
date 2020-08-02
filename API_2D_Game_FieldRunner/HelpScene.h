#pragma once
#include "Scene.h"

class HelpScene final :
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
	explicit HelpScene();
	virtual ~HelpScene();
};

