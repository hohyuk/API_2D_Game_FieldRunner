#include "framework.h"
#include "CaveScene.h"

void CaveScene::Ready()
{
	m_szBGKey = TEXT("CaveStage");
	StageScene::Ready();
	SOUND_MGR->PlayBGM(SoundManager::CHANNELID::STAGE3_BGM);
	FILE_MGR->LoadData(FileManager::TILE_STAGE3);		// Ž�� �������� ������ ���� ������ �ҷ���
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