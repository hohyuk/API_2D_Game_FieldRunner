#pragma once
#include "Actor.h"

#include "AStar.h"

class Enemy :
	public Actor
{
public:
	virtual void Ready() override;
	virtual void Render(const HDC & hDC) override;
public:
	explicit Enemy();
	virtual ~Enemy();

protected:
	void Console_AStarSearch();
protected:
	AStar* m_pAStar{ nullptr };
};

