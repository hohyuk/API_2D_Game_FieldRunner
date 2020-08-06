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
			// 그리기 순서 소팅을 pObj->LateUpdate(); 이것 보다 위에 있거나 if문 아래 있어야한다. 
			// 이유는 pObj->LateUpdate();여기서 씬전환을 하게되고 객체가 지워져 리스트 랜더에 담을수없어 터진다.
			// 어차피 지울꺼 담지말고 맨 아래 두자.
			pObj->LateUpdate();

			if (isSceneChange)
			{
				isSceneChange = false;
				// 만약 게임 중간에 나가게되면 남아있는 RenderSortList를 지워줘야한다.
				for (int k = 0; k < OBJECT::END_RENDER; ++k)
					m_listRenderSort[k].clear();
				break;
			}

			// 그리기 순서 소팅한다. 
			OBJECT::RENDER eID = pObj->Get_RenderID();
			m_listRenderSort[eID].emplace_back(pObj);
		}
	}
}

void ObjectManager::Render(const HDC & hDC)
{
	for (int i = 0; i < OBJECT::END_RENDER; ++i)
	{
		// 소팅 후 그리기
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
