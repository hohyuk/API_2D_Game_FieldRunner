#include "framework.h"
#include "VolcanoScene.h"

void VolcanoScene::Ready()
{
	m_szBGKey = TEXT("VolcanoStage");
	StageScene::Ready();
	FILE_MGR->Load_Data(FileManager::TILE_STAGE2);		// Ž�� �������� ������ ���� ������ �ҷ���

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
