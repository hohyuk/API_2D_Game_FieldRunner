#pragma once
#include "StageScene.h"
class GrasslandsScene :
	public StageScene
{
public:
	virtual void Ready() override;
public:
	explicit GrasslandsScene();
	virtual ~GrasslandsScene();
};

