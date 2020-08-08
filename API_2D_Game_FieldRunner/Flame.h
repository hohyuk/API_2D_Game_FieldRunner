#pragma once
#include "Tower.h"
class Flame :
	public Tower
{
public:
	virtual void Ready() override;
public:
	explicit Flame();
	virtual ~Flame();

protected:
	virtual void UpgradeTower() override;
	virtual void Attack(float fDist) override;
	virtual void MakeBullet() override;
};

