#pragma once
class UserManager final
{
public:
	enum ID { DBUG_RENDER_BOX, END_ID };
public:
	void Set_GameState(ID _eID) { isGameState[_eID] = !isGameState[_eID]; }
	bool Get_DebugRenderBox()const { return isGameState[ID::DBUG_RENDER_BOX]; }
public:
	static UserManager*  Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new UserManager;
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
private:
	explicit UserManager();
	~UserManager();
private:
	static UserManager* m_pInstance;


private:
	bool isGameState[ID::END_ID]{ false };
};

