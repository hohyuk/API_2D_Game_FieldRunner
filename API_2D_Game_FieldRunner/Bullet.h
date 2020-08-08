#pragma once
#include "Actor.h"
class Bullet :
	public Actor
{
public:
	void Set_RadianAngle(float rad) { m_fRadAngle = rad; }
public:
	virtual void Render(const HDC & hDC) override;
public:
	explicit Bullet();
	virtual ~Bullet();

protected:
	float m_fRadAngle;
	float m_fLifeTime;
};

