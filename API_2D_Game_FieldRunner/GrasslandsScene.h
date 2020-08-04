#pragma once
#include "StageScene.h"
class GrasslandsScene :
	public StageScene
{
public:
	virtual void Ready() override;
	virtual void Update() override;
public:
	explicit GrasslandsScene();
	virtual ~GrasslandsScene();
};

