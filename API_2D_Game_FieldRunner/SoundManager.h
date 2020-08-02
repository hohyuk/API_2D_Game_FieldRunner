#pragma once
class SoundManager final
{
public:
	enum CHANNELID { BGM, PLAYER, ENEMY, EFFECT, UI, MAXCHANNEL };
public:
	static SoundManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new SoundManager;

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
	void Initialize();
	void Release();
public:
	void PlaySound(const TCHAR* pSoundKey, CHANNELID eID);
	void PlaySound(const TCHAR* pSoundKey, CHANNELID eID, bool overlap);
	void PlayBGM(const TCHAR* pSoundKey);
	void StopSound(CHANNELID eID);
	void StopAll();

	// LogoBGM
	void Start_LogoBGM();
	void Stop_LogoBGM();
private:
	void LoadSoundFile();
private:
	explicit SoundManager();
	~SoundManager();
private:
	static SoundManager* m_pInstance;
	// 사운드 리소스 정보를 갖는 객체 
	map<TCHAR*, FMOD_SOUND*> m_mapSound;
	// FMOD_CHANNEL : 재생하고 있는 사운드를 관리할 객체 
	FMOD_CHANNEL* m_pChannelArr[MAXCHANNEL];
	// 사운드 ,채널 객체 및 장치를 관리하는 객체 
	FMOD_SYSTEM* m_pSystem;

	// BGM 변수
	bool isLogoBGM{ false };
};