#pragma once
#include "Enemy.h"
class Soldier :
	public Enemy
{
public:
	virtual void Ready() override;
public:
	explicit Soldier();
	virtual ~Soldier();

protected:
	virtual void Init_Stat() override;
	virtual void Change_Anim() override;
	virtual void Dead_Anim() override;
};

