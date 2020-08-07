#include "framework.h"
#include "Enemy.h"

#include "TileManager.h"

void Enemy::Ready()
{
	m_pAStar = new AStar;
	m_pAStar->AStarStart(g_StartPoint, g_ArrivalPoint);
	m_eCurState = OBJECT::STATE::END_MOTION;
	Save_State(g_StartPoint);
	Change_Anim();
	Console_AStarSearch();
}

void Enemy::Render(const HDC & hDC)
{
	MakeRect(m_tRect, m_tInfo);
	MakeRect(m_tColliderRC, m_tInfo, 2);
	Actor::Render(hDC);

	HpDraw(hDC, m_iMaxHP);
	HpDraw(hDC, m_iHP, RGB(1, 255, 1));
}

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
	Safe_Delete(m_pAStar);
	cout << "Enemy Delete" << endl;
}

void Enemy::ReSearch()
{
	if (isArrive) return; // 이미 도착했으면 검사하지 않는다.
	cout << "ReSearch" << endl;
	int index = TILE_MGR->Get_TileIndex(m_tInfo.fX, m_tInfo.fY);
	if (index == -1)
		return;
	m_pAStar->AStarStart(index, g_ArrivalPoint);

	Save_State(index);
	Change_Anim();
}

void Enemy::Save_State(int preIndex)
{
	if (m_pAStar->Get_BestList().empty())
		return;

	m_StateIndex = -1;					// 다시 인덱스를 초기화해주자
	m_vecState.clear();					// Vecter에 있는 상태들을 지워주자
	int previousIndex = preIndex;		// 전 단계 인덱스와 다음 어디로 갈지의 인덱스를 비교하기위해 Temp역할 변수 만든다.

	for (const auto& index : m_pAStar->Get_BestList())
	{
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
	m_vecState.emplace_back(OBJECT::STATE::RIGHT);	// 마지막 모션은 항상 오른쪽이기때문에
}

void Enemy::Console_AStarSearch()
{
	for (const auto& d: m_pAStar->Get_BestList())
		cout << d << " ";
	cout << endl;
}

void Enemy::Move()
{
	// 체력이 없으면 죽는 모션바꾸기 및 isDie - True바꾸기
	if (m_iHP <= 0)
	{
		Dead_Anim();
		isDie = true;
		return;
	}
	else if (m_pAStar->Get_BestList().empty())
	{
		m_tInfo.fX += DELTA_TIME * m_fSpeed;			// 도착했으면 쭉 직진
		isArrive = true;
		return;
	}

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
	}
}

void Enemy::HpDraw(const HDC & hDC, const int & hp, DWORD color /*= RGB(255, 1, 1)*/)
{
	HBRUSH m_br = CreateSolidBrush(color);
	HBITMAP Ahbmp = CreateCompatibleBitmap(hDC, 100, 50);
	HDC Ahdc = CreateCompatibleDC(hDC);
	HBITMAP Aoldbmp = (HBITMAP)SelectObject(Ahdc, Ahbmp);
	auto oldbr = SelectObject(Ahdc, m_br);
	Rectangle(Ahdc, 0, 0, 100, 50);
	SelectObject(Ahdc, oldbr);
	BLENDFUNCTION bf;

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = 150;

	int curHp = 0;
	if (hp == m_iMaxHP)
		curHp = m_HpBarLength;
	else
	{
		// 선형보간
		float hpRate = float(m_iHP) / float(m_iMaxHP);			// 현재 hp 비율
		float start = 0;					// 시작 점
		curHp = int(start * (1.f - hpRate) + m_HpBarLength * hpRate);		// 선형보간법 공식
	}

	GdiAlphaBlend(hDC, m_tColliderRC.left, m_tColliderRC.top - 25, curHp, 10, Ahdc, 0, 0, 100, 50, bf);

	SelectObject(Ahdc, Aoldbmp);
	DeleteObject(m_br);
	DeleteObject(Ahbmp);
	DeleteDC(Ahdc);
}

bool Enemy::DeleteEnemy()
{
	// 1. 범위에 벗어 났을 때
	if (m_tInfo.fX >= WINCX + 50)
	{
		// 생명을 깍아야한다.
		//USER_MGR->Set_LifeMinus();
		return true;
	}
	// 2. 죽은 애님이 끝나면 삭제
	else if (isDie && m_tFrame.iStart == m_tFrame.iEnd - 1)
	{
		USER_MGR->Set_Gain(m_iGold, m_iScore);
		return true;
	}
	return false;
}
