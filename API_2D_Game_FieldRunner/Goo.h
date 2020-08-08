#pragma once
#include "Tower.h"
class Goo :
	public Tower
{
public:
	virtual void Ready() override;
public:
	explicit Goo();
	virtual ~Goo();

protected:
	virtual void UpgradeTower() override;
	virtual void Attack(float fDist) override;
	virtual void MakeBullet() override;
};

