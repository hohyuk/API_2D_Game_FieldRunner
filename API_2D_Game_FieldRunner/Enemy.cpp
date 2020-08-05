#include "framework.h"
#include "Enemy.h"



void Enemy::Ready()
{
	m_pAStar = new AStar;
	m_pAStar->AStarStart(g_StartPoint, g_ArrivalPoint);

	// Test
	Console_AStarSearch();
}

void Enemy::Render(const HDC & hDC)
{
	Actor::Render(hDC);
}

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	Safe_Delete(m_pAStar);
}

void Enemy::Console_AStarSearch()
{
	for (const auto& d: m_pAStar->Get_BestList())
		cout << d << " ";
	cout << endl;
}
