#pragma once
#include "GameObject.h"
class Actor :
	public GameObject
{
public:
	void Set_Attack(int attack) { m_iAttack = attack; }
	int Get_Attack()const { return m_iAttack; }
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
	bool isSound{ false };
	int m_iAttack;
};

