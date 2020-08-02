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
	// ���� ���ҽ� ������ ���� ��ü 
	map<TCHAR*, FMOD_SOUND*> m_mapSound;
	// FMOD_CHANNEL : ����ϰ� �ִ� ���带 ������ ��ü 
	FMOD_CHANNEL* m_pChannelArr[MAXCHANNEL];
	// ���� ,ä�� ��ü �� ��ġ�� �����ϴ� ��ü 
	FMOD_SYSTEM* m_pSystem;

	// BGM ����
	bool isLogoBGM{ false };
};