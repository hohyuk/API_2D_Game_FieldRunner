#pragma once
#include "Tower.h"
class Mortar :
	public Tower
{
public:
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Release() override;
public:
	explicit Mortar();
	virtual ~Mortar();
};

