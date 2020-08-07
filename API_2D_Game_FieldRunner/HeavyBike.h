#pragma once
#include "Enemy.h"
class HeavyBike :
	public Enemy
{
public:
	virtual void Ready() override;
public:
	explicit HeavyBike();
	virtual ~HeavyBike();

protected:
	virtual void Init_Stat() override;
	virtual void Change_Anim() override;
	virtual void Dead_Anim() override;

	virtual void CreateEnemy();
};

