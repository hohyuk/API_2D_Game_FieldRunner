#include "framework.h"
#include "ScoreScene.h"

void ScoreScene::Ready()
{
	m_szBGKey = TEXT("ScoreScene");
	Create_UI(TEXT("Exit"), INFO(1295, 110, 88 * 2 - 40, 84 * 2 - 40, 88, 84),
		UI_TYPE::CLASS_ID::EXIT_UI, UI_TYPE::BUTTON::EXIT_BTN);

	FILE_MGR->LoadGameScore();
	m_pScore = FILE_MGR->Get_Score();
	Set_Color(0);
	for (int i = 0; i < 3; ++i)
	{
		for (auto v : m_pScore[i])
			cout << v << endl;
	}
}

void ScoreScene::Update()
{
	OBJ_MGR->Update();
}

void ScoreScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
	if (KEY_MGR->Key_DOWN('1'))
		Set_Color(0);
	if (KEY_MGR->Key_DOWN('2'))
		Set_Color(1);
	if (KEY_MGR->Key_DOWN('3'))
		Set_Color(2);
}

void ScoreScene::Render(const HDC & hDC)
{
	Scene::Render_BackGround(hDC);
	OBJ_MGR->Render(hDC);

	TCHAR m_Tmp[128];

	for (int i = 0; i < 3; ++i)
	{
		_stprintf_s(m_Tmp, 128, TEXT("Stage %d"), i + 1);
		FONT_MGR->FontDraw(hDC, m_Tmp, 200, 300 + (i * 100), m_Color[i], TEXT("°íµñ"), 50, FW_BOLD);
	}

	_stprintf_s(m_Tmp, 128, TEXT("No."));
	FONT_MGR->FontDraw(hDC, m_Tmp, 460, 200, RGB(243, 217, 1), TEXT("°íµñ"), 50, FW_BOLD);
	_stprintf_s(m_Tmp, 128, TEXT("Score"));
	FONT_MGR->FontDraw(hDC, m_Tmp, 800, 200, RGB(243, 217, 1), TEXT("°íµñ"), 50, FW_BOLD);

	int size = static_cast<int>(m_pScore[index].size());
	for (int i = 0; i < size; ++i)
	{
		_stprintf_s(m_Tmp, 128, TEXT("%d"), i + 1);
		FONT_MGR->FontDraw(hDC, m_Tmp, 460, 250 + (i * 50), RGB(243, 217, 1), TEXT("°íµñ"), 50, FW_BOLD);

		_stprintf_s(m_Tmp, 128, TEXT("%d"), m_pScore[index][i]);
		FONT_MGR->FontDraw(hDC, m_Tmp, 800, 250 + (i * 50), RGB(243, 217, 1), TEXT("°íµñ"), 50, FW_BOLD);
	}
}

void ScoreScene::Release()
{
	OBJ_MGR->Delete_Object(OBJECT::UI);

}

ScoreScene::ScoreScene()
{
}

ScoreScene::~ScoreScene()
{
	Release();
}

void ScoreScene::Set_Color(int idx)
{
	for (int i = 0; i < 3; ++i)
		m_Color[i] = (idx == i) ? RGB(243, 117, 1): RGB(243, 217, 1);

	index = idx;
}
