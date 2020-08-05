#pragma once
class UserManager final
{
public:
	enum ID { DBUG_RENDER_BOX, END_ID };
public:
	void ReSet(int gold = 10);
	void Set_GameState(ID _eID) { isGameState[_eID] = !isGameState[_eID]; }
	bool Get_DebugRenderBox()const { return isGameState[ID::DBUG_RENDER_BOX]; }

	// ±ÝÀü
	int Get_Gold()const { return m_iGold; }
	void Set_Buy(int price) { m_iGold -= price; }
	void Set_Sell(int price) { m_iGold += price; }

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

	int m_iGold{};
	int m_iScore{};
	int m_iLife{};
};

