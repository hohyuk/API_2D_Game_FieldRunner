#include "framework.h"
#include "VolcanoScene.h"

void VolcanoScene::Ready()
{
	m_szBGKey = TEXT("VolcanoStage");
	StageScene::Ready();
	Create_OverHang(TEXT("Gate2"), 1343, 280);
	SOUND_MGR->PlayBGM(SoundManager::CHANNELID::STAGE2_BGM);
	FILE_MGR->LoadData(FileManager::TILE_STAGE2);		// 탐색 시작점과 끝점을 정한 파일을 불러옴

}

void VolcanoScene::Update()
{
	OBJ_MGR->Update();
}

VolcanoScene::VolcanoScene()
{
}

VolcanoScene::~VolcanoScene()
{
	FILE_MGR->SaveGameScore(FILE_MGR->SCORE2, USER_MGR->Get_Score());
}