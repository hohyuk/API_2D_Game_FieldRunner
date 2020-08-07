#pragma once
#include "Enemy.h"
class HeavySoldier :
	public Enemy
{
public:
	virtual void Ready() override;
public:
	explicit HeavySoldier();
	virtual ~HeavySoldier();

protected:
	virtual void Init_Stat() override;
	virtual void Change_Anim() override;
	virtual void Dead_Anim() override;
};

