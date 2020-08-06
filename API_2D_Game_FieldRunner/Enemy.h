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
	virtual void Init_Stat() = 0;
	virtual void Change_Anim() = 0;
	virtual void ReSearch();
protected:
	void Save_State(int preIndex);
	void Console_AStarSearch();
	void Move();
	void HpDraw(const HDC& hDC, const int& hp, DWORD color = RGB(255, 1, 1));
protected:
	bool isArrive{ false };					// 목표 도착했는지 안했는지
	int m_iHP;
	int m_iMaxHP;
	int m_HpBarLength;
	int m_StateIndex{};
	float m_fSpeed;
	AStar* m_pAStar{ nullptr };

	OBJECT::STATE m_eCurState;
	vector< OBJECT::STATE> m_vecState;		// 미리 모션 저장
};

