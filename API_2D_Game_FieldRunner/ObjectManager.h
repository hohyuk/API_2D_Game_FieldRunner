#pragma once
class ObjectManager final
{
public:
	void ChangeScene() { isSceneChange = true; }
public:
	static ObjectManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new ObjectManager;
		return m_pInstance;
	}

	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void Add_Object(GameObject*& pObj, OBJECT::ID eID);
	void Delete_Object(OBJECT::ID eID);

public:
	void Update();
	void LateUpdate();
	void Render(const HDC& hDC);
	void Release();

private:
	explicit ObjectManager();
	~ObjectManager();
private:
	static ObjectManager* m_pInstance;

private:
	bool isSceneChange{ false };

private:
	list<GameObject*> m_listObject[OBJECT::END_ID];
	list<GameObject*> m_listRenderSort[OBJECT::END_RENDER];
};

