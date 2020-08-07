#pragma once
#include "Bullet.h"
class GooBullet final:
	public Bullet
{
public:
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Release() override;

public:
	explicit GooBullet();
	virtual ~GooBullet();
};

