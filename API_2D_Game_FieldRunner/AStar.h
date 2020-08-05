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
	list<int>* Get_BestList() { return &m_BestList; }
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
	list<NODE*> m_OpenList;		// ������ ����� ����
	list<NODE*> m_CloseList;	// ������ ����� ����
	list<int> m_BestList;		// ������ ������ ���
	int m_iStartIdx;			// ��� �ε���
	int m_iGoalIdx;				// ������ �ε���
};

