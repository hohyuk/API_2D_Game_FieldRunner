#include "framework.h"
#include "AStar.h"

#include "TileManager.h"
#include "Tile.h"

bool AStar::AStarStart(const int & iStartIdx, const int & iGoalIdx)
{
	// ���� ���ٸ� ����
	if (iStartIdx == iGoalIdx)
		return false;
	// Ÿ�� ���� ��������
	vector<GameObject*> pVecTile = TILE_MGR->Get_Tile();

	// ��ǥ�ε��� DrawID�� 1�̸� ����
	if (dynamic_cast<Tile*>(pVecTile[iGoalIdx])->Get_TileType() != OBJECT::TILE_TYPE::ARRIVAL_POINT)
		return false;

	// ���� ������ ��������.
	Release();

	// �ε��� ������ ��´�
	m_iStartIdx = iStartIdx;
	m_iGoalIdx = iGoalIdx;

	// �˻��Ѵ�.
	if (!MakeRoute()) return false;		// �˻� ���н� false

	return true;	// �̻� ������ true
}

bool AStar::MakeRoute()
{
	vector<GameObject*> pVecTile = TILE_MGR->Get_Tile();

	NODE* pNode = new NODE;

	pNode->iIndex = m_iStartIdx;
	pNode->pParent = nullptr;
	pNode->fCost = 0.f;
	m_CloseList.push_back(pNode);

	NODE* pNextNode = nullptr;
	int index = 0;

	while (true)
	{
		/* if(�����ϴ� Ÿ��?, �����ִ� Ÿ��?, �̹� �����߰ų�, ���¸���Ʈ�� �߰����ִ� Node�� ����) */

		// �� Ÿ��
		index = pNode->iIndex - TILEX;
		if (pNode->iIndex >= TILEX && IsCommon(index))
		{
			// �� �ε����� �ش��ϴ� Ÿ�Ͽ� ���� ������ �����ϱ� ���ؼ�
			pNextNode = MakeNode(index, pNode);
			m_OpenList.push_back(pNextNode);
		}

		// �Ʒ���
		index = pNode->iIndex + TILEX;

		if (pNode->iIndex < (TILEX * TILEY) - TILEX && IsCommon(index))
		{
			pNextNode = MakeNode(index, pNode);
			m_OpenList.push_back(pNextNode);
		}

		// ������
		index = pNode->iIndex + 1;

		if (pNode->iIndex % TILEX != TILEX - 1 && IsCommon(index))
		{
			pNextNode = MakeNode(index, pNode);
			m_OpenList.push_back(pNextNode);
		}

		// ����
		index = pNode->iIndex - 1;

		if (pNode->iIndex % TILEX != 0 && IsCommon(index))
		{
			pNextNode = MakeNode(index, pNode);
			m_OpenList.push_back(pNextNode);
		}

		m_OpenList.sort([](NODE* pDestNode, NODE* pSourceNode) {
			return pDestNode->fCost < pSourceNode->fCost;
			});

		list<NODE*>::iterator iter = m_OpenList.begin();
		if (iter == m_OpenList.end())	// ����ִٸ�
			return false;

		pNode = *iter;
		m_CloseList.push_back(*iter);
		iter = m_OpenList.erase(iter);

		if (pNode->iIndex == m_iGoalIdx)
		{
			while (true)
			{
				m_BestList.push_back(pNode->iIndex);
				pNode = pNode->pParent;
				if (pNode->iIndex == m_iStartIdx)
					break;
			}

			m_BestList.reverse();
			break;
		}
	}

	return true;
}

bool AStar::CheckList(const int & _index)
{
	for (const auto& pNode : m_OpenList)
		if (_index == pNode->iIndex)
			return false;

	for (const auto& pNode : m_CloseList)
		if (_index == pNode->iIndex)
			return false;

	return true;
}

NODE * AStar::MakeNode(int _index, NODE * pParent)
{
	NODE* pNode = new NODE;
	pNode->iIndex = _index;
	pNode->pParent = pParent;

	vector<GameObject*> pVecTile = TILE_MGR->Get_Tile();
	float x1 = pVecTile[_index]->Get_PosX();
	float y1 = pVecTile[_index]->Get_PosY();
	float x2 = pVecTile[pParent->iIndex]->Get_PosX();
	float y2 = pVecTile[pParent->iIndex]->Get_PosY();

	float fPCost = Distance(x1, y1, x2, y2);

	float gx = pVecTile[m_iGoalIdx]->Get_PosX();
	float gy = pVecTile[m_iGoalIdx]->Get_PosY();

	float fGoalCost = Distance(x1, y1, gx, gy);

	pNode->fCost = fPCost + fGoalCost;

	return pNode;
}

bool AStar::IsCommon(const int & _index)
{
	if (dynamic_cast<Tile*>(TILE_MGR->Get_Tile()[_index])->Get_TileType() == OBJECT::TILE_TYPE::NONE && CheckList(_index))
		return true;
	return false;
}

void AStar::Release()
{
	for (auto& pNode : m_OpenList)
		Safe_Delete(pNode);

	for (auto& pNode : m_CloseList)
		Safe_Delete(pNode);

	m_OpenList.clear();
	m_CloseList.clear();
	m_BestList.clear();
}

AStar::AStar()
{
}

AStar::~AStar()
{
	Release();
}
