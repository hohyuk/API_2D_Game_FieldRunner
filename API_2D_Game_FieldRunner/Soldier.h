#pragma once
#include "Enemy.h"
class Soldier :
	public Enemy
{
public:
	virtual void Ready() override;
	virtual int Update() override;
public:
	explicit Soldier();
	virtual ~Soldier();
};

