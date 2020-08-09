#pragma once
#include "Bullet.h"
class FlameBullet :
	public Bullet
{
public:
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Render(const HDC & hDC) override;
public:
	explicit FlameBullet();
	virtual ~FlameBullet();

private:
	int m_iBulletSize;
};

