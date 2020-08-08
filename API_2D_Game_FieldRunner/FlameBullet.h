#pragma once
#include "Bullet.h"
class FlameBullet :
	public Bullet
{
public:
	virtual void Ready() override;
	virtual int Update() override;

public:
	explicit FlameBullet();
	virtual ~FlameBullet();
};

