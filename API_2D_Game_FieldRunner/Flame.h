#pragma once
#include "Tower.h"
class Flame :
	public Tower
{
public:
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Release() override;
public:
	explicit Flame();
	virtual ~Flame();
};

