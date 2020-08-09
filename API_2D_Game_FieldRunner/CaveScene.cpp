#include "framework.h"
#include "CaveScene.h"

void CaveScene::Ready()
{
	m_szBGKey = TEXT("CaveStage");
	StageScene::Ready();
	SOUND_MGR->PlayBGM(SoundManager::CHANNELID::STAGE3_BGM);
	FILE_MGR->LoadData(FileManager::TILE_STAGE3);		// 탐색 시작점과 끝점을 정한 파일을 불러옴
}

void CaveScene::Update()
{
	OBJ_MGR->Update();
}

CaveScene::CaveScene()
{
}

CaveScene::~CaveScene()
{
	FILE_MGR->SaveGameScore(FILE_MGR->SCORE3, USER_MGR->Get_Score());
}