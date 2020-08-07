#include "framework.h"
#include "VolcanoScene.h"

void VolcanoScene::Ready()
{
	m_szBGKey = TEXT("VolcanoStage");
	StageScene::Ready();
	FILE_MGR->Load_Data(FileManager::TILE_STAGE2);		// 탐색 시작점과 끝점을 정한 파일을 불러옴

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
}