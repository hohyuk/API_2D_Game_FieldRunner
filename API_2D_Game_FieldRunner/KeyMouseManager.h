#pragma once
class KeyMouseManager final
{
public:
	static KeyMouseManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new KeyMouseManager;
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
	POINT Mouse_Point();
	bool Key_UP(int iKey);
	bool Key_DOWN(int iKey);
	bool Key_Pressing(int iKey);
	bool ToggleKeyDown(int KeyCode);

	// ���콺 ����Ʈ �׸���
	void Ready();
	void Update();
	void Render(const HDC & hDC);

private:
	explicit KeyMouseManager();
	~KeyMouseManager();
private:
	static KeyMouseManager* m_pInstance;

private:
	bool KeyDown[256];
	BYTE PrevKey;
	// ���콺 ����Ʈ �׸��� ���� ����
	INFO m_tInfo;
	RECT m_tRect;
};

