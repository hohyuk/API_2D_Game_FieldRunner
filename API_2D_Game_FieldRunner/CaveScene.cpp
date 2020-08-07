#include "framework.h"
#include "CaveScene.h"

void CaveScene::Ready()
{
	m_szBGKey = TEXT("CaveStage");
	StageScene::Ready();
	StageScene::Ready();
	FILE_MGR->Load_Data(FileManager::TILE_STAGE3);		// Ž�� �������� ������ ���� ������ �ҷ���
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