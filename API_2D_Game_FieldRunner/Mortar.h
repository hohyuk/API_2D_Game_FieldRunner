#pragma once
#include "Tower.h"
class Mortar :
	public Tower
{
public:
	virtual void Ready() override;
	virtual int Update() override;
public:
	explicit Mortar();
	virtual ~Mortar();

protected:
	virtual void UpgradeTower() override;
	virtual void Attack(float fDist) override;
	virtual void MakeBullet() override;

private:
	bool isAttackMotion{ false };
};

