#include "framework.h"
#include "ObjectManager.h"

#include "GameObject.h"
#include "Enemy.h"
#include "Blimp.h"
#include "GooBullet.h"
#include "Effect.h"

ObjectManager* ObjectManager::m_pInstance{ nullptr };

GameObject * ObjectManager::Get_Target(GameObject * pObj, OBJECT::ID eTargetID)
{
	if (m_listObject[eTargetID].empty())
		return nullptr;
	
	GameObject* pTarget = m_listObject[eTargetID].front();		// 비교하기위해 첫번째 타겟을 정해준다.

	float fBaseDist = Distance(pObj->Get_PosX(), pObj->Get_PosY(), pTarget->Get_PosX(), pTarget->Get_PosY());


	for (auto& iter : m_listObject[eTargetID])
	{
		if (dynamic_cast<Enemy*>(iter)->IsTargetDead())
			continue;
		
		float fDist = Distance(pObj->Get_PosX(), pObj->Get_PosY(), iter->Get_PosX(), iter->Get_PosY());

		if (fDist < fBaseDist)
		{
			pTarget = iter;
			fBaseDist = fDist;
		}
	}

	return pTarget;
}

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
		if (GameStop(static_cast<OBJECT::ID>(i)))
			continue;

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

	// 충돌 처리
	Collide_GameObject(m_listObject[OBJECT::ENEMY], m_listObject[OBJECT::BULLET]);

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
	{
		if (!dynamic_cast<Blimp*>(pObj))
			dynamic_cast<Enemy*>(pObj)->ReSearch();
	}
		
	isReSearch = false;
}

bool ObjectManager::GameStop(OBJECT::ID eID)
{
	if (!USER_MGR->Get_GameStop()) return false;
	if(eID == OBJECT::ID::ENEMY || eID == OBJECT::ID::BULLET || eID == OBJECT::ID::EFFECT)
		return true;

	return false;
}

void ObjectManager::Collide_GameObject(list<GameObject*>& rDstList, list<GameObject*>& rSrcList)
{
	if (USER_MGR->Get_GameStop()) return;

	RECT rc = {};
	for (auto& rDstObject : rDstList)
	{
		for (auto& rSrcObject : rSrcList)
		{
			if (IntersectRect(&rc, &rDstObject->Get_ColliderRect(), &rSrcObject->Get_ColliderRect()))
			{
				if (dynamic_cast<GooBullet*>(rSrcObject))
				{
					dynamic_cast<Enemy*>(rDstObject)->Set_Damage(dynamic_cast<Actor*>(rSrcObject)->Get_Attack());
					dynamic_cast<Enemy*>(rDstObject)->Set_SlowSpeed();
					// GooEffect Create
					GameObject* pInstance = nullptr;
					pInstance = AbstractFactory<Effect>::Create(TEXT("Goo_Effect"), rSrcObject->Get_PosX(), rSrcObject->Get_PosY());
					OBJ_MGR->Add_Object(pInstance, OBJECT::EFFECT);
					dynamic_cast<Bullet*>(rSrcObject)->Set_Delete();
				}
			}
		}
	}
}

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
	Release();
}
