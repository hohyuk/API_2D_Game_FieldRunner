#pragma once
#include "Actor.h"

#include "AStar.h"

class Enemy :
	public Actor
{
public:
	void ReSearch();

	void Set_Damage(int damage) { m_iHP -= damage; }
	bool IsTargetDead()const { return isDie; }			// ������ Ÿ���� ���� ����.
public:
	virtual void Ready() override;
	virtual void Render(const HDC & hDC) override;
public:
	explicit Enemy();
	virtual ~Enemy();

protected:
	virtual void Init_Stat() = 0;
	virtual void Change_Anim() = 0;
	virtual void Dead_Anim() = 0;
protected:
	void Save_State(int preIndex);
	void Console_AStarSearch();
	void Move();
	void HpDraw(const HDC& hDC, const int& hp, DWORD color = RGB(255, 1, 1));
	bool DeleteEnemy();
protected:
	bool isArrive{ false };					// ��ǥ �����ߴ��� ���ߴ���
	bool isDie{ false };
	int m_iGold{};
	int m_iScore{};
	int m_iHP;
	int m_iMaxHP;
	int m_HpBarLength;
	int m_StateIndex{};
	float m_fSpeed;
	AStar* m_pAStar{ nullptr };

	OBJECT::STATE m_eCurState;
	vector< OBJECT::STATE> m_vecState;		// �̸� ��� ����
};

