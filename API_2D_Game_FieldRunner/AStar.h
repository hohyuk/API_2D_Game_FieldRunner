#pragma once

typedef struct tag_Node
{
	int iIndex;					
	float fCost;			
	tag_Node* pParent;
}NODE;

class AStar
{
public:
	list<int> Get_BestList() { return m_BestList; }
public:
	bool AStarStart(const int& iStartIdx, const int& iGoalIdx);

private:
	bool MakeRoute();
	bool CheckList(const int& _index);
	NODE* MakeNode(int _index, NODE* pParent);
	bool IsCommon(const int& _index);
	void Release();
public:
	explicit AStar();
	~AStar();
private:
	list<NODE*> m_OpenList;		// 조사할 대상의 집합
	list<NODE*> m_CloseList;	// 조사한 대상의 집합
	list<int> m_BestList;		// 가야할 최적의 경로
	int m_iStartIdx;			// 출발 인덱스
	int m_iGoalIdx;				// 목적지 인덱스
};

