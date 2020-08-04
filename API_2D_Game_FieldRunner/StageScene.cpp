#include "framework.h"
#include "StageScene.h"

void StageScene::Ready()
{
	Create_UI(TEXT("Start_Stop"), INFO(150, 900, 128, 128, 128, 128), UI_TYPE::CLASS_ID::OPTION_UI);
	Create_UI(TEXT("FastForward"), INFO(300, 900, 128, 128, 128, 128), UI_TYPE::CLASS_ID::OPTION_UI);
	Create_UI(TEXT("Option"), INFO(450, 900, 128, 128, 128, 128), UI_TYPE::CLASS_ID::OPTION_UI);
}

void StageScene::Update()
{
}

void StageScene::LateUpdate()
{
	OBJ_MGR->LateUpdate();
}

void StageScene::Render(const HDC & hDC)
{
}

void StageScene::Release()
{
}

StageScene::StageScene()
{
}

StageScene::~StageScene()
{
}
