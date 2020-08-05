#pragma once
#include "Actor.h"
class Tower :
	public Actor
{
public:
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;
protected:
	void Set_Pivot(float x, float y) { m_tInfo.fX += x, m_tInfo.fY += y; }
public:
	explicit Tower();
	virtual ~Tower();
};

