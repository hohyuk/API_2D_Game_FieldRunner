#pragma once
#include "StageScene.h"
class VolcanoScene :
	public StageScene
{
public:
	virtual void Ready() override;
	virtual void Update() override;
	virtual void Render(const HDC & hDC) override;
public:
	explicit VolcanoScene();
	virtual ~VolcanoScene();
};

