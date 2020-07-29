#pragma once
class Scene;
class SceneManager final
{
public:
	static SceneManager* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new SceneManager;
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
	enum ID { LOGO, SELECT, STAGE_1, STAGE_2, STAGE_3, HELP, SCORE, EDIT, NO_CHANGE };
public:
	void Change_Scene(ID eSceneID);
	void Change_Scene(ID eSceneID, bool nextScene);
	void Update();
	void LateUpdate();
	void Render(const HDC& hDC);
	void Release();
private:
	bool IsActivateScene(const BYTE& speed = 5);
	void Fade_In(const HDC& hDC);
private:
	explicit SceneManager();
	~SceneManager();
private:
	static SceneManager* m_pInstance;

private:
	BYTE	m_bFadeVal;
	bool	isFadeIn_Activation;
	Scene*	m_pScene{ nullptr };
	ID		m_eCurrentScene{ NO_CHANGE };
	ID		m_eNextScene{ NO_CHANGE };
};