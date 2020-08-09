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

void SoundManager::PlaySound(const CHANNELID & eID)
{
	const TCHAR * pSoundKey = SearchSoundKey(eID);
	map<TCHAR*, FMOD_SOUND*>::iterator iter;

	iter = find_if(m_mapSound.begin(), m_mapSound.end(), [&](auto& iter)
		{
			return !lstrcmp(pSoundKey, iter.first);
		});

	if (iter == m_mapSound.end())
		return;

	FMOD_BOOL bPlay = FALSE;
	
	FMOD_System_PlaySound(m_pSystem, FMOD_CHANNEL_FREE, iter->second, FALSE, &m_pChannelArr[eID]);
	FMOD_System_Update(m_pSystem);
}

void SoundManager::PlayBGM(const CHANNELID& eID)
{
	const TCHAR * pSoundKey = SearchSoundKey(eID);

	map<TCHAR*, FMOD_SOUND*>::iterator iter;

	iter = find_if(m_mapSound.begin(), m_mapSound.end(), [&](auto& iter)
		{
			return !lstrcmp(pSoundKey, iter.first);
		});

	if (iter == m_mapSound.end())
		return;

	FMOD_System_PlaySound(m_pSystem, FMOD_CHANNEL_FREE, iter->second, FALSE, &m_pChannelArr[eID]);
	FMOD_Channel_SetMode(m_pChannelArr[eID], FMOD_LOOP_NORMAL);
	FMOD_Channel_SetVolume(m_pChannelArr[eID], 0.8f);
	FMOD_System_Update(m_pSystem);
}

void SoundManager::StopSound(CHANNELID eID)
{
	FMOD_Channel_Stop(m_pChannelArr[eID]);
}

void SoundManager::StopAll()
{
	for (int i = 0; i < MAXCHANNEL; ++i)
		FMOD_Channel_Stop(m_pChannelArr[i]);
}

void SoundManager::LoadSoundFile()
{
	_finddata_t fd;

	long handle = _findfirst("../Resources/Sound/*.*", &fd);

	if (handle == 0)
		return;

	int iResult = 0;

	char szCurPath[128] = "../Resources/Sound/";
	char szFullPath[128] = "";

	while (iResult != -1)
	{
		strcpy_s(szFullPath, szCurPath);
		strcat_s(szFullPath, fd.name);
		FMOD_SOUND* pSound = nullptr;

		FMOD_RESULT eRes = FMOD_System_CreateSound(m_pSystem, szFullPath, FMOD_HARDWARE, 0, &pSound);

		if (eRes == FMOD_OK)
		{
			int iLength = strlen(fd.name) + 1;

			TCHAR* pSoundKey = new TCHAR[iLength];
			ZeroMemory(pSoundKey, sizeof(TCHAR) * iLength);
			MultiByteToWideChar(CP_ACP, 0, fd.name, iLength, pSoundKey, iLength);

			m_mapSound.emplace(pSoundKey, pSound);
		}
		iResult = _findnext(handle, &fd);
	}
	FMOD_System_Update(m_pSystem);
	_findclose(handle);
}

const TCHAR * SoundManager::SearchSoundKey(const CHANNELID & eID)
{
	switch (eID)
	{
	case CHANNELID::LOGO_BGM:
		return TEXT("LogoBgm.mp3");
	case CHANNELID::STAGE1_BGM:
		return TEXT("grasslands.mp3");
	case CHANNELID::STAGE2_BGM:
		return TEXT("lavaflow.mp3");
	case CHANNELID::STAGE3_BGM:
		return TEXT("crystalcaves.mp3");
	case CHANNELID::BUTTON1:
		return TEXT("UI_button.wav");
	case CHANNELID::BUTTON2:
		return TEXT("UI_button2.wav");
	case CHANNELID::INVALID:
		return TEXT("invalid.mp3");
	case CHANNELID::UPGRADE:
		return TEXT("tower_upgrade.mp3");
	case CHANNELID::SELL:
		return TEXT("tower_sell.mp3");
	case CHANNELID::GOO_ATTACK:
		return TEXT("goo_launch.mp3");
	case CHANNELID::EFFECT:
		return TEXT("goo_impact.mp3");
	case CHANNELID::GATLING_ATTACK1:
		return TEXT("tower_gatling_fire_loop_01.mp3");
	case CHANNELID::GATLING_ATTACK2:
		return TEXT("tower_gatling_fire_loop_02.mp3");
	case CHANNELID::GATLING_ATTACK3:
		return TEXT("tower_gatling_fire_loop_03.mp3");
	case CHANNELID::FLAME_ATTACK:
		return TEXT("tower_flamethrower_attack_loop_01.mp3");	
	default:
		return nullptr;
	}
	return nullptr;
}

SoundManager::SoundManager()
	: m_pSystem{ nullptr }
{
}

SoundManager::~SoundManager()
{
	Release();
}
