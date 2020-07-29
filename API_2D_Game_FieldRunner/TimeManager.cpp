#include "framework.h"
#include "TimeManager.h"

// static 변수의 초기화하는 법
TimeManager* TimeManager::m_pInstance{ nullptr };

void TimeManager::Set_SecTimeLoopStart()
{
	std::chrono::duration<double>time = std::chrono::high_resolution_clock::now() - m_Start;
	m_fElapsedTime = static_cast<float>(time.count());
}

void TimeManager::Set_SecTimeLoopEnd()
{
	m_Start = chrono::high_resolution_clock::now();
}

void TimeManager::Set_SecTimeLoop()
{
	Set_SecTimeLoopStart();
	Set_SecTimeLoopEnd();
}

void TimeManager::Measure_FPS()
{
	std::chrono::duration<double>time = std::chrono::high_resolution_clock::now() - m_FpsStart;
	m_fCurrentFpsSec = static_cast<float>(time.count());

	++m_iFPS;
	if (m_fCurrentFpsSec >= m_fFixFpsSec)
	{
		m_FpsStart = chrono::high_resolution_clock::now();
		swprintf_s(m_szFPS, TEXT("FieldRunner FPS : %d"), m_iFPS);
		m_iFPS = 0;
	}
	SetWindowText(g_hWND, m_szFPS);
}

TimeManager::TimeManager()
	:
	m_Start{ chrono::high_resolution_clock::now() },
	m_FpsStart{ chrono::high_resolution_clock::now() },
	m_fElapsedTime{ 0.f },
	m_fCurrentFpsSec{ 0.f },
	m_fFixFpsSec{ 1.f },
	m_iFPS{ 0 }
{

}

TimeManager::~TimeManager()
{
}
