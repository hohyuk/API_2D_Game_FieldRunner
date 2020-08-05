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
	virtual void Change_Anim() = 0;
protected:
	void Save_State(int preIndex);
	void Console_AStarSearch();
	void Move();
protected:
	int m_StateIndex{};
	float m_fSpeed;
	AStar* m_pAStar{ nullptr };

	OBJECT::STATE m_eCurState;
	vector< OBJECT::STATE> m_vecState;		// 미리 모션 저장
};

