#pragma once
#include "Actor.h"
class Bullet :
	public Actor
{
public:
	virtual void Render(const HDC & hDC) override;
public:
	explicit Bullet();
	virtual ~Bullet();

};

