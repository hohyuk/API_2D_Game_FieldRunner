#include "framework.h"
#include "SoundManager.h"

SoundManager* SoundManager::m_pInstance = nullptr;

void SoundManager::Initialize()
{
	FMOD_System_Create(&m_pSystem);

	// 1. 시스템 포인터, 2. 사용할 가상채널 수 , 초기화 방식) 
	FMOD_System_Init(m_pSystem, 32, FMOD_INIT_NORMAL, NULL);
	LoadSoundFile();
}

void SoundManager::Release()
{
	for (auto& Mypair : m_mapSound)
	{
		delete[] Mypair.first;
		FMOD_Sound_Release(Mypair.second);
	}
	m_mapSound.clear();
	FMOD_System_Release(m_pSystem);
	FMOD_System_Close(m_pSystem);
}

void SoundManager::PlaySound(const TCHAR * pSoundKey, CHANNELID eID)
{
}

void SoundManager::PlaySound(const TCHAR * pSoundKey, CHANNELID eID, bool overlap)
{
}

void SoundManager::PlayBGM(const TCHAR * pSoundKey)
{
}

void SoundManager::StopSound(CHANNELID eID)
{
}

void SoundManager::StopAll()
{
}

void SoundManager::Start_LogoBGM()
{
}

void SoundManager::Stop_LogoBGM()
{
}

void SoundManager::LoadSoundFile()
{
}

SoundManager::SoundManager()
	: m_pSystem{ nullptr }
{
}

SoundManager::~SoundManager()
{
	Release();
}
