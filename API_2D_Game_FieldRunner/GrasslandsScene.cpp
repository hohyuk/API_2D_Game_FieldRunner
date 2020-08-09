#include "framework.h"
#include "GrasslandsScene.h"

void GrasslandsScene::Ready()
{
	m_szBGKey = TEXT("GrasslandsStage");
	StageScene::Ready();
	Create_OverHang(TEXT("Gate"), 1347, 487);
	SOUND_MGR->PlayBGM(SoundManager::CHANNELID::STAGE1_BGM);
	FILE_MGR->LoadData(FileManager::TILE_STAGE1);		// Ž�� �������� ������ ���� ������ �ҷ���

	cout << g_StartPoint << " , " << g_ArrivalPoint << endl;
}

void GrasslandsScene::Update()
{
	OBJ_MGR->Update();
}

GrasslandsScene::GrasslandsScene()
{
}

GrasslandsScene::~GrasslandsScene()
{
	FILE_MGR->SaveGameScore(FILE_MGR->SCORE1, USER_MGR->Get_Score());
}