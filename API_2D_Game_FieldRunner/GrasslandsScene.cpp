#include "framework.h"
#include "GrasslandsScene.h"

void GrasslandsScene::Ready()
{
	m_szBGKey = TEXT("GrasslandsStage");
	StageScene::Ready();
	FILE_MGR->Load_Data(FileManager::TILE_STAGE1);		// 탐색 시작점과 끝점을 정한 파일을 불러옴

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
	
}
