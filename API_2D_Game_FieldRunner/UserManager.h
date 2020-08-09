#pragma once
class UserManager final
{
public:
	enum ID { DEBUG_RENDER_BOX, DEBUG_NONE_TILE, GAME_STOP, GAME_OVER, INVINCIBILITY, END_ID };
public:
	void ReSet(int gold = 10);
	void Set_GameState(ID _eID) { isGameState[_eID] = !isGameState[_eID]; }
	bool Get_DebugRenderBox()const { return isGameState[ID::DEBUG_RENDER_BOX]; }
	bool Get_DebugNoneTileBox()const { return isGameState[ID::DEBUG_NONE_TILE]; }
	void Set_GameStartStop() { isGameState[ID::GAME_STOP] = !isGameState[ID::GAME_STOP]; }
	bool Get_GameStop() { return isGameState[ID::GAME_STOP]; }
	// 무적
	void Set_GameInvincibility() { isGameState[ID::INVINCIBILITY] = !isGameState[ID::INVINCIBILITY]; }
	bool Get_GameInvincibility() { return isGameState[ID::INVINCIBILITY]; }
	// 금전
	int Get_Gold()const { return m_iGold; }
	void Set_Buy(int price) { m_iGold -= price; }
	void Set_Sell(int price) { m_iGold += price; }
	// 스코어
	void Set_Score(int _score) { m_iScore += _score; }
	int Get_Score()const { return m_iScore; }
	// Life
	int Get_Life()const { return m_iLife; }
	void Set_LifeMinus(int minus = 1) { m_iLife -= minus; /* 생명이 0이하이면 게임 오버 해주자 */ if (m_iLife <= 0) isGameState[GAME_OVER] = true; }

	// Enemy 죽이면 스코어 및 금전 획득
	void Set_Gain(int _gold, int _score);
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

