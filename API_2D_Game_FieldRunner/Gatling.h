#pragma once
#include "Tower.h"
class Gatling :
	public Tower
{
public:
	virtual void Ready() override;
public:
	explicit Gatling();
	virtual ~Gatling();

protected:
	virtual void UpgradeTower() override;
	virtual void Attack(float fDist) override;
	virtual void MakeBullet() override {};
};

