#include "framework.h"
#include "SceneManager.h"

#include "LogoScene.h"
#include "HelpScene.h"
#include "SelectScene.h"
#include "EditScene.h"
#include "GrasslandsScene.h"
#include "VolcanoScene.h"
#include "CaveScene.h"

SceneManager* SceneManager::m_pInstance{ nullptr };

void SceneManager::Change_Scene(ID eSceneID)
{
	m_eNextScene = eSceneID;

	if (m_eCurrentScene != m_eNextScene)
	{
		Safe_Delete(m_pScene);

		switch (m_eNextScene)
		{
		case SceneManager::LOGO:
			m_pScene = new LogoScene;
			break;
		case SceneManager::HELP:
			m_pScene = new HelpScene;
			break;
		case SceneManager::SELECT:
			m_pScene = new SelectScene;
			break;
		case SceneManager::EDIT:
			m_pScene = new EditScene;
			break;
		case SceneManager::STAGE_1:
			m_pScene = new GrasslandsScene;
			break;
		case SceneManager::STAGE_2:
			m_pScene = new VolcanoScene;
			break;
		case SceneManager::STAGE_3:
			m_pScene = new CaveScene;
			break;
		default:
			break;
		}

		OBJ_MGR->ChangeScene();
		m_pScene->Ready();
		m_eCurrentScene = m_eNextScene;
		m_bFadeVal = 255;
		isFadeIn_Activation = false;
	}
}

void SceneManager::Update()
{
	m_pScene->Update();
}

void SceneManager::LateUpdate()
{
	m_pScene->LateUpdate();
}

void SceneManager::Render(const HDC & hDC)
{
	m_pScene->Render(hDC);

	// Fade In
	if (!IsActivateScene())
		Fade_In(hDC);
}

void SceneManager::Release()
{
	Safe_Delete(m_pScene);
}

bool SceneManager::IsActivateScene(const BYTE & speed)
{
	if (0 == m_bFadeVal) return true;

	if (10 >= (m_bFadeVal -= speed))
		m_bFadeVal = 0;

	return false;
}

void SceneManager::Fade_In(const HDC & hDC)
{
	HBITMAP Ahbmp = CreateCompatibleBitmap(hDC, WINCX, WINCY);		// ���ĺ����� �� ��Ʈ�� ����
	HDC Ahdc = CreateCompatibleDC(hDC);								// ��ȭ�� �غ�
	HBITMAP Aoldbmp = (HBITMAP)SelectObject(Ahdc, Ahbmp);			// ���⿡ �׸��� �׸�
	BLENDFUNCTION bf;

	bf.BlendOp = AC_SRC_OVER;
	bf.BlendFlags = 0;
	bf.AlphaFormat = 0;
	bf.SourceConstantAlpha = m_bFadeVal;								// ���� 255 -> 0

	GdiAlphaBlend(hDC, 0, 0, WINCX, WINCY, Ahdc, 0, 0, WINCX, WINCY, bf);
	SelectObject(Ahdc, Aoldbmp);

	DeleteObject(Ahbmp);
	DeleteDC(Ahdc);
}

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	Release();
}
