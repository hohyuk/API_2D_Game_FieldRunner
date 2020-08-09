#pragma once
#include "Actor.h"

#include "AStar.h"

class Bullet;
class Enemy :
	public Actor
{
public:
	void ReSearch();

	void Set_Damage(int damage) { m_iHP -= damage; }
	bool IsTargetDead()const { return isDie; }			// ������ Ÿ���� ���� ����.
	void Set_SlowSpeed();
	bool IsBulletCollide(Bullet* bullet);
	POINT Get_NextPos()const { return m_nextPos; }
public:
	virtual void Ready() override;
	virtual int Update() override;
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
	virtual bool DeleteEnemy();
	void SlowDown();
	void Check_NextPos();
protected:
	bool isArrive{ false };					// ��ǥ �����ߴ��� ���ߴ���
	bool isDie{ false };
	bool isSlowSpeed{ false };
	int m_iGold{};
	int m_iScore{};
	int m_iHP;
	int m_iMaxHP;
	int m_HpBarLength;
	int m_StateIndex{};
	float m_fSpeed;
	float m_fSlowTime{ 0.f };
	POINT m_nextPos;			

	AStar* m_pAStar{ nullptr };

	OBJECT::STATE m_eCurState;
	vector< OBJECT::STATE> m_vecState;		// �̸� ��� ����
	//list<Bullet**> m_BulletCollide;
	list<Bullet*> m_BulletCollide;

};

