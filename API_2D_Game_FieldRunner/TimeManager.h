#pragma once

/*Singleton Pattern*/
class TimeManager final
{
public:
	// �ڱ� �ڽ� Ŭ���� ������ ��ü ������ �ϱ� ���� static�Լ��̴�.
	// ���� ��ü�� �����Ҵ� �ߴٸ� �ٷ� �������ش�.
	static TimeManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new TimeManager;
		return m_pInstance;
	}

	// ��ü�� �������ִ� static�Լ��̴�.
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void Set_SecTimeLoop();				// ������ ���� ElapsedTime�� ����
	void Measure_FPS();					// �� �ʸ��� FPS����
	float GetElapsedTime()const { return m_fElapsedTime * m_TimeSpeed; }
	void Set_DubleSpeed() { isDoubleSpeed = !isDoubleSpeed; m_TimeSpeed = (isDoubleSpeed == true) ? 2.f : 1.f; }
	void Set_ReSetSpeed() { isDoubleSpeed = false; m_TimeSpeed = 1.f; }
	bool IsDubleSpeed()const { return isDoubleSpeed; }
private:
	void Set_SecTimeLoopStart();		// ���� ������ ����
	void Set_SecTimeLoopEnd();			// ���� �� �� ����

	// �̱��� ������ ����ϱ� ���ؼ��� �����ڿ� �Ҹ��ڸ� private���� ����� �ܺο��� ������ ���� �� �ִ�.
	// ���� ������ �� ���Կ����ڵ� ������ �����ϴ�.
private:
	explicit TimeManager();
	~TimeManager();
private:
	static TimeManager* m_pInstance;
private:
	TCHAR	m_szFPS[32]{};				// FPS ���
	int		m_iFPS;						// FPS 65���� ������ �Ѵ�.
	float	m_fFixFpsSec;				// 1�� �ֱ�
	float   m_fCurrentFpsSec;			// ���� �� �ֱ�
	float	m_fElapsedTime;				// 0.016�ʸ� ������ �����
	std::chrono::time_point<std::chrono::steady_clock> m_Start;
	std::chrono::time_point<std::chrono::steady_clock> m_FpsStart;

	bool isDoubleSpeed{ false };		// ���
	float m_TimeSpeed{ 1.f };
};

/* �̱��� �����̶� */
// ��ü ������ �����ϴ� ����. �ּҴ����� 1���̱� ������ �̱����̶� ��. 