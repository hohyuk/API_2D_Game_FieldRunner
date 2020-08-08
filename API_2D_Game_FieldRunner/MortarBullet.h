#pragma once
#include "Bullet.h"
class MortarBullet :
	public Bullet
{
public:
	virtual void Ready() override;
	virtual int Update() override;

public:
	explicit MortarBullet();
	virtual ~MortarBullet();
};

