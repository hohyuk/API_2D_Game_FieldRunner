#include "framework.h"
#include "Enemy.h"

#include "TileManager.h"

void Enemy::Set_SlowSpeed()
{
	m_fSlowTime = 0.f;

	if (isSlowSpeed) return;
	isSlowSpeed = true;
	m_fSpeed /= 2.f;
	m_tFrame.fFixTime /= 2.f;
}

void Enemy::Ready()
{
	m_pAStar = new AStar;
	m_pAStar->AStarStart(g_StartPoint, g_ArrivalPoint);
	m_eCurState = OBJECT::STATE::END_MOTION;
	Save_State(g_StartPoint);
	Change_Anim();
	Console_AStarSearch();
}

int Enemy::Update()
{
	SlowDown();

	Actor::Update_Anim();

	if (!isDie)	Move();

	if (DeleteEnemy()) return OBJ_DEAD;
	return OBJ_NOEVENT;
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
	if (isArrive) return; // �̹� ���������� �˻����� �ʴ´�.
	cout << "ReSearch" << endl;
	int index = TILE_MGR->Get_TileIndex(m_tInfo.fX, m_tInfo.fY);
	if (index == g_ArrivalPoint)
	{
		isArrive = true;
		return;
	}
	else if (index == -1)
		return;
	m_pAStar->AStarStart(index, g_ArrivalPoint);

	Save_State(index);
	Change_Anim();
}

void Enemy::Save_State(int preIndex)
{
	if (m_pAStar->Get_BestList().empty())
		return;

	m_StateIndex = -1;					// �ٽ� �ε����� �ʱ�ȭ������
	m_vecState.clear();					// Vecter�� �ִ� ���µ��� ��������
	int previousIndex = preIndex;		// �� �ܰ� �ε����� ���� ���� ������ �ε����� ���ϱ����� Temp���� ���� �����.

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
	m_vecState.emplace_back(OBJECT::STATE::RIGHT);	// ������ ����� �׻� �������̱⶧����
}

void Enemy::Console_AStarSearch()
{
	for (const auto& d: m_pAStar->Get_BestList())
		cout << d << " ";
	cout << endl;
}

void Enemy::Move()
{
	// ü���� ������ �״� ��ǹٲٱ� �� isDie - True�ٲٱ�
	if (m_iHP <= 0)
	{
		Dead_Anim();
		isDie = true;
		return;
	}
	else if (m_pAStar->Get_BestList().empty())
	{
		m_tInfo.fX += DELTA_TIME * m_fSpeed;			// ���������� �� ����
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
		Change_Anim();		// ��� �ٲ��ִ°� ���⼭ ���ش�. ��ǥ�������� �����ϱ�
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
		// ��������
		float hpRate = float(m_iHP) / float(m_iMaxHP);			// ���� hp ����
		float start = 0;					// ���� ��
		curHp = int(start * (1.f - hpRate) + m_HpBarLength * hpRate);		// ���������� ����
	}

	GdiAlphaBlend(hDC, m_tColliderRC.left, m_tColliderRC.top - 25, curHp, 10, Ahdc, 0, 0, 100, 50, bf);

	SelectObject(Ahdc, Aoldbmp);
	DeleteObject(m_br);
	DeleteObject(Ahbmp);
	DeleteDC(Ahdc);
}

bool Enemy::DeleteEnemy()
{
	// 1. ������ ���� ���� ��
	if (m_tInfo.fX >= WINCX + 50)
	{
		// ������ ��ƾ��Ѵ�.
		USER_MGR->Set_LifeMinus();
		return true;
	}
	// 2. ���� �ִ��� ������ ����
	else if (isDie && m_tFrame.iStart == m_tFrame.iEnd - 1)
	{
		USER_MGR->Set_Gain(m_iGold, m_iScore);
		return true;
	}
	return false;
}

void Enemy::SlowDown()
{
	if (!isSlowSpeed) return;

	m_fSlowTime += DELTA_TIME;
	if (m_fSlowTime > 1.f)
	{
		m_fSlowTime = 0.f;
		isSlowSpeed = false;
		m_fSpeed *= 2.f;
		m_tFrame.fFixTime *= 2.f;
	}
}
