#pragma once
#include "GameObject.h"
class Actor :
	public GameObject
{
public:
	void Set_Attack(int attack) { m_iAttack = attack; }
public:
	// GameObject을(를) 통해 상속됨
	virtual void Ready() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(const HDC & hDC) override;
	virtual void Release() override;

public:
	explicit Actor();
	virtual ~Actor();

protected:
	virtual void Update_Anim();

protected:
	int m_iAttack;
};

