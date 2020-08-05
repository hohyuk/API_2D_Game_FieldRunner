#include "framework.h"
#include "Enemy.h"

#include "TileManager.h"

void Enemy::Ready()
{
	m_pAStar = new AStar;
	m_pAStar->AStarStart(g_StartPoint, g_ArrivalPoint);
	
	Save_State(g_StartPoint);
	Console_AStarSearch();
}

void Enemy::Render(const HDC & hDC)
{
	MakeRect(m_tRect, m_tInfo);
	Actor::Render(hDC);
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	Safe_Delete(m_pAStar);
}

void Enemy::Save_State(int preIndex)
{
	if (m_pAStar->Get_BestList().empty())
		return;

	int previousIndex = preIndex;		// 전 단계 인덱스와 다음 어디로 갈지의 인덱스를 비교하기위해 Temp역할 변수 만든다.
	for (const auto& index : m_pAStar->Get_BestList())
	{
		// 오른쪽 모션
		if (index == previousIndex + 1)
			m_vecState.emplace_back(OBJECT::STATE::RIGHT);
		else if(index == previousIndex - 1)
			m_vecState.emplace_back(OBJECT::STATE::LEFT);
		else if(index == previousIndex - TILEX)
			m_vecState.emplace_back(OBJECT::STATE::UP);
		else if(index == previousIndex + TILEX)
			m_vecState.emplace_back(OBJECT::STATE::DOWN);
		previousIndex = index;
	}
}

void Enemy::Console_AStarSearch()
{
	for (const auto& d: m_pAStar->Get_BestList())
		cout << d << " ";
	cout << endl;
}

void Enemy::Move()
{
	if (m_pAStar->Get_BestList().empty())
		return;

	vector<GameObject*> pVecTile = TILE_MGR->Get_Tile();
	int iDestIdx = m_pAStar->Get_BestList().front();

	float dirX = pVecTile[iDestIdx]->Get_PosX() - m_tInfo.fX;
	float dirY = pVecTile[iDestIdx]->Get_PosY() - m_tInfo.fY;

	float length = sqrtf(dirX*dirX + dirY * dirY);

	m_tInfo.fDirX = dirX / length;
	m_tInfo.fDirY = dirY / length;

	m_tInfo.fX += m_tInfo.fDirX * DELTA_TIME * m_fSpeed;
	m_tInfo.fY += m_tInfo.fDirY * DELTA_TIME * m_fSpeed;

	if (length < 5.f)
	{
		Change_Anim();		// 모션 바꿔주는건 여기서 해준다. 목표지점까지 왔으니까
		m_pAStar->Get_BestList().pop_front();
		cout << m_pAStar->Get_BestList().front() << endl;
	}
}
