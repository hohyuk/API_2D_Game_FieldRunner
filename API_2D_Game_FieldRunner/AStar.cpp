#include "framework.h"
#include "AStar.h"

#include "TileManager.h"
#include "Tile.h"

bool AStar::AStarStart(const int & iStartIdx, const int & iGoalIdx)
{
	// 둘이 같다면 리턴
	if (iStartIdx == iGoalIdx)
		return false;
	// 타일 정보 가져오기
	vector<GameObject*> pVecTile = TILE_MGR->Get_Tile();

	if (dynamic_cast<Tile*>(pVecTile[iGoalIdx])->Get_TileType() != OBJECT::TILE_TYPE::ARRIVAL_POINT)
		return false;

	// 먼저 정보를 지워진다.
	Release();

	// 인덱스 정보를 담는다
	m_iStartIdx = iStartIdx;
	m_iGoalIdx = iGoalIdx;

	// 검색한다.
	if (!MakeRoute()) return false;		// 검색 실패시 false

	return true;	// 이상 없으면 true
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
		/* if(존재하는 타일?, 갈수있는 타일?, 이미 조사했거나, 오픈리스트에 추가되있는 Node는 제외) */

		// 윗 타일
		index = pNode->iIndex - TILEX;
		if (pNode->iIndex >= TILEX && IsCommon(index))
		{
			// 위 인덱스에 해당하는 타일에 대한 정보를 생성하기 위해서
			pNextNode = MakeNode(index, pNode);
			m_OpenList.push_back(pNextNode);
		}

		// 아래쪽
		index = pNode->iIndex + TILEX;

		if (pNode->iIndex < (TILEX * TILEY) - TILEX && IsCommon(index))
		{
			pNextNode = MakeNode(index, pNode);
			m_OpenList.push_back(pNextNode);
		}

		// 오른쪽
		index = pNode->iIndex + 1;

		if (pNode->iIndex % TILEX != TILEX - 1 && IsCommon(index))
		{
			pNextNode = MakeNode(index, pNode);
			m_OpenList.push_back(pNextNode);
		}

		// 왼쪽
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
		if (iter == m_OpenList.end())	// 비어있다면
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
	if (_index == m_iGoalIdx)
		return true;

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
