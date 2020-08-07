#pragma once
#include "Enemy.h"
class Robot :
	public Enemy
{
public:
	virtual void Ready() override;
public:
	explicit Robot();
	virtual ~Robot();

protected:
	virtual void Init_Stat() override;
	virtual void Change_Anim() override;
	virtual void Dead_Anim() override;
};

