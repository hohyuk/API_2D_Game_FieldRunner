#pragma once
class ObjectManager final
{
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
	void Update();
	void LateUpdate();
	void Render(const HDC& hDC);
	void Release();

private:
	explicit ObjectManager();
	~ObjectManager();
private:
	static ObjectManager* m_pInstance;
};

