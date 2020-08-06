#include "framework.h"
#include "ObjectManager.h"

#include "GameObject.h"
#include "Enemy.h"
ObjectManager* ObjectManager::m_pInstance{ nullptr };

void ObjectManager::Add_Object(GameObject *& pObj, OBJECT::ID eID)
{
	m_listObject[eID].emplace_back(pObj);
}

void ObjectManager::Delete_Object(OBJECT::ID eID)
{
	for (auto& pObj : m_listObject[eID])
		Safe_Delete(pObj);
	m_listObject[eID].clear();
}

void ObjectManager::Update()
{
	for (int i = 0; i < OBJECT::END_ID; ++i)
	{
		for (list<GameObject*>::iterator iter = m_listObject[i].begin(); iter != m_listObject[i].end();)
		{
			int iEvent = (*iter)->Update();
			if (OBJ_DEAD == iEvent)
			{
				Safe_Delete(*iter);
				iter = m_listObject[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void ObjectManager::LateUpdate()
{
	//  ReSearch
	ReSearchEnemy();

	for (int i = 0; i < OBJECT::END_ID; ++i)
	{
		for (auto& pObj : m_listObject[i])
		{
			// �׸��� ���� ������ pObj->LateUpdate(); �̰� ���� ���� �ְų� if�� �Ʒ� �־���Ѵ�. 
			// ������ pObj->LateUpdate();���⼭ ����ȯ�� �ϰԵǰ� ��ü�� ������ ����Ʈ ������ ���������� ������.
			// ������ ���ﲨ �������� �� �Ʒ� ����.
			pObj->LateUpdate();

			if (isSceneChange)
			{
				isSceneChange = false;
				// ���� ���� �߰��� �����ԵǸ� �����ִ� RenderSortList�� ��������Ѵ�.
				for (int k = 0; k < OBJECT::END_RENDER; ++k)
					m_listRenderSort[k].clear();
				break;
			}

			// �׸��� ���� �����Ѵ�. 
			OBJECT::RENDER eID = pObj->Get_RenderID();
			m_listRenderSort[eID].emplace_back(pObj);
		}
	}
}

void ObjectManager::Render(const HDC & hDC)
{
	for (int i = 0; i < OBJECT::END_RENDER; ++i)
	{
		// ���� �� �׸���
		m_listRenderSort[i].sort([](GameObject* pFirst, GameObject* pSecond)
			{
				return pFirst->Get_PosY() < pSecond->Get_PosY();
			});

		for (const auto& pObj : m_listRenderSort[i])
		{
			pObj->Render(hDC);
		}
		m_listRenderSort[i].clear();
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < OBJECT::END_ID; ++i)
	{
		for (auto& pObj : m_listObject[i])
			Safe_Delete(pObj);
		m_listObject[i].clear();
	}
}

void ObjectManager::ReSearchEnemy()
{
	if (!isReSearch) return;

	for (auto& pObj : m_listObject[OBJECT::ENEMY])
		dynamic_cast<Enemy*>(pObj)->ReSearch();
	isReSearch = false;
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}
