#pragma once
#include "Enemy.h"
class HeavySoldier :
	public Enemy
{
public:
	virtual void Ready() override;
	virtual int Update() override;
public:
	explicit HeavySoldier();
	virtual ~HeavySoldier();

protected:
	virtual void Change_Anim() override;
};

