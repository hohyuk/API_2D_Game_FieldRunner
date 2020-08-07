#pragma once
#include "Enemy.h"
class Blimp :
	public Enemy
{
public:
	virtual void Ready() override;
	virtual int Update() override;
public:
	explicit Blimp();
	virtual ~Blimp();

protected:
	virtual void Init_Stat() override;
	virtual void Change_Anim() override;
	virtual void Dead_Anim() override;
	virtual bool DeleteEnemy() override;
private:
	void Move_Wave();

private:
	int m_iMoveAngle{ 0 };
	float m_ftempX, m_ftempY;
};

