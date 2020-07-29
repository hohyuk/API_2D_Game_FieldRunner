#pragma once

/*Singleton Pattern*/
class TimeManager final
{
public:
	// 자기 자신 클래스 내에서 객체 생성을 하기 위한 static함수이다.
	// 만약 객체를 동작할당 했다면 바로 리턴해준다.
	static TimeManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new TimeManager;
		return m_pInstance;
	}

	// 객체를 삭제해주는 static함수이다.
	static void Destroy_Instance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

public:
	void Set_SecTimeLoop();				// 루프를 통해 ElapsedTime을 구함
	void Measure_FPS();					// 매 초마다 FPS측정
	float GetElapsedTime()const { return m_fElapsedTime * m_TimeSpeed; }
	void Set_DubleSpeed() { isDoubleSpeed = !isDoubleSpeed; m_TimeSpeed = (isDoubleSpeed == true) ? 2.f : 1.f; }
	void Set_ReSetSpeed() { isDoubleSpeed = false; m_TimeSpeed = 1.f; }
	bool IsDubleSpeed()const { return isDoubleSpeed; }
private:
	void Set_SecTimeLoopStart();		// 루프 시작초 시작
	void Set_SecTimeLoopEnd();			// 루프 끝 초 리셋

	// 싱글턴 패턴을 사용하기 위해서는 생성자와 소멸자를 private으로 해줘야 외부에서 선언을 막을 수 있다.
	// 복사 생성자 및 대입연산자도 막으면 좋긴하다.
private:
	explicit TimeManager();
	~TimeManager();
private:
	static TimeManager* m_pInstance;
private:
	TCHAR	m_szFPS[32]{};				// FPS 출력
	int		m_iFPS;						// FPS 65정도 나오게 한다.
	float	m_fFixFpsSec;				// 1초 주기
	float   m_fCurrentFpsSec;			// 현재 초 주기
	float	m_fElapsedTime;				// 0.016초를 나오게 만들기
	std::chrono::time_point<std::chrono::steady_clock> m_Start;
	std::chrono::time_point<std::chrono::steady_clock> m_FpsStart;

	bool isDoubleSpeed{ false };		// 배속
	float m_TimeSpeed{ 1.f };
};

/* 싱글턴 패턴이란 */
// 객체 생성을 제한하는 패턴. 최소단위가 1개이기 때문에 싱글톤이라 함. 