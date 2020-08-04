#include "framework.h"
#include "FileManager.h"

#include "TileManager.h"
#include "Tile.h"

FileManager* FileManager::m_pInstance{ nullptr };
void FileManager::SaveData(ID eID)
{
	const TCHAR* path = DataPath(eID);

	HANDLE hFile = CreateFile(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		//MessageBox(nullptr, TEXT("SaveData Failed"), TEXT("FileSystem"),MB_OK);
		MESSAGE_BOX(TEXT("SaveData Failed"), TEXT("FileManager"));
		return;
	}

	// Tile Save
	DWORD dwByte = 0;
	int index = -1;
	for (auto& pTile : TILE_MGR->Get_Tile())
	{
		OBJECT::TILE_TYPE type = dynamic_cast<Tile*>(pTile)->Get_TileType();
		++index;
		if (OBJECT::TILE_TYPE::NONE != type)
		{
			WriteFile(hFile, &index, sizeof(int), &dwByte, nullptr);
			WriteFile(hFile, &type, sizeof(OBJECT::TILE_TYPE), &dwByte, nullptr);
		}
	}
	MESSAGE_BOX(TEXT("SaveData Success!"), TEXT("FileManager"));
	CloseHandle(hFile);
}

void FileManager::Load_Data(ID eID)
{
	const TCHAR* path = DataPath(eID);
	HANDLE hFile = CreateFile(path, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
		NewFile(eID);
	
	DWORD dwByte = 0;
	OBJECT::TILE_TYPE type = OBJECT::TILE_TYPE::NONE;
	int index = -1;
	while (true)
	{
		ReadFile(hFile, &index, sizeof(int), &dwByte, nullptr);
		ReadFile(hFile, &type, sizeof(OBJECT::TILE_TYPE), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		dynamic_cast<Tile*>(TILE_MGR->Get_Tile()[index])->Set_TileType(type);
	}

	CloseHandle(hFile);
}

const TCHAR * FileManager::DataPath(ID eID)
{
	switch (eID)
	{
	case FileManager::TILE_STAGE1:
		return TEXT("../Resources/Data/TileSaveData1.txt");
	case FileManager::TILE_STAGE2:
		return TEXT("../Resources/Data/TileSaveData2.txt");
	case FileManager::TILE_STAGE3:
		return TEXT("../Resources/Data/TileSaveData3.txt");
	case FileManager::SCORE1:
		return TEXT("../Resources/Data/ScoreSaveData1.txt");
	case FileManager::SCORE2:
		return TEXT("../Resources/Data/ScoreSaveData2.txt");
	case FileManager::SCORE3:
		return TEXT("../Resources/Data/ScoreSaveData3.txt");
	default:
		break;
	}
	return nullptr;
}

void FileManager::NewFile(ID eID)
{
	const TCHAR* path = DataPath(eID);

	HANDLE hFile = CreateFile(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		MESSAGE_BOX(TEXT("NewFile Failed"), TEXT("FileSystem"));
		return;
	}
	CloseHandle(hFile);
}

FileManager::FileManager()
{
}

FileManager::~FileManager()
{
}
