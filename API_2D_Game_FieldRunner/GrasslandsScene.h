#pragma once
#include "StageScene.h"
class GrasslandsScene :
	public StageScene
{
public:
	virtual void Ready() override;
	virtual void Update() override;
	virtual void Render(const HDC & hDC) override;
public:
	explicit GrasslandsScene();
	virtual ~GrasslandsScene();
};

