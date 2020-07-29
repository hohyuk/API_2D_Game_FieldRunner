#pragma once
#include "GameObject.h"
class Actor :
	public GameObject
{
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
};

