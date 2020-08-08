#pragma once
#include "Actor.h"
class Effect :
	public Actor
{
public:
	virtual void Ready() override;
	virtual int Update() override;
public:
	explicit Effect();
	virtual ~Effect();
};

