#include "framework.h"
#include "CaveScene.h"

void CaveScene::Ready()
{
	m_szBGKey = TEXT("CaveStage");
	StageScene::Ready();
	StageScene::Ready();
	FILE_MGR->Load_Data(FileManager::TILE_STAGE3);		// 탐색 시작점과 끝점을 정한 파일을 불러옴
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
}
