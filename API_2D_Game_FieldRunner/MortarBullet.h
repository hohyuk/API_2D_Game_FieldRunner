#pragma once
#include "Bullet.h"
class MortarBullet :
	public Bullet
{
public:
	bool IsBomb()const { return isBomb; }
	void Set_EndPoint(POINT endPoint) { m_EndPoint = endPoint; }
public:
	virtual void Ready() override;
	virtual int Update() override;
	virtual void Render(const HDC & hDC) override;
public:
	explicit MortarBullet();
	virtual ~MortarBullet();

private:
	float QuadraticBezierCurve(float t, LONG start, LONG middle, LONG end);

private:
	bool isBomb{ false };
	float m_fTime;
	// º£Áö¾î °î¼±
	POINT m_StartPoint;
	POINT m_MiddlePoint;
	POINT m_EndPoint;
};

