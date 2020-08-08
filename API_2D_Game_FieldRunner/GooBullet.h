#pragma once
#include "Bullet.h"
class GooBullet final:
	public Bullet
{
public:
	virtual void Ready() override;
	virtual int Update() override;

public:
	explicit GooBullet();
	virtual ~GooBullet();
};

