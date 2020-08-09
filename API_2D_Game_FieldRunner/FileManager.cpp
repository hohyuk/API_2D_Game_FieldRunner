#include "framework.h"
#include "FileManager.h"

#include "TileManager.h"
#include "Tile.h"

// AStar에 필요한 위치
int g_StartPoint{};
int g_ArrivalPoint{};

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

void FileManager::LoadData(ID eID)
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
		if (OBJECT::TILE_TYPE::START_POINT == type)
			g_StartPoint = index;
		else if (OBJECT::TILE_TYPE::ARRIVAL_POINT == type)
			g_ArrivalPoint = index;
	}

	CloseHandle(hFile);
}

void FileManager::SaveGameScore(ID eID, const int& score)
{
	// 1 vector 초기화해주기
	for (int i = 0; i < 3; ++i)
		m_vecScore[i].clear();
	// 2 Score불러오기
	LoadScoreData(eID);

	// 3 Score vector넣기
	m_vecScore[m_index].emplace_back(score);

	// 4 정렬하기
	sort(m_vecScore[m_index].rbegin(), m_vecScore[m_index].rend());

	// 5 저장하기
	SaveScoreData(eID);
}

void FileManager::LoadGameScore()
{
	for (int i = 0; i < 3; ++i)
		m_vecScore[i].clear();
	for (int i = SCORE1; i <= SCORE3; ++i)
		LoadScoreData(static_cast<ID>(i));
}

void FileManager::SaveScoreData(ID eID)
{
	const TCHAR* path = DataPath(eID);

	HANDLE hFile = CreateFile(path, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
	if (INVALID_HANDLE_VALUE == hFile)
	{
		//MessageBox(nullptr, TEXT("SaveData Failed"), TEXT("FileSystem"),MB_OK);
		MESSAGE_BOX(TEXT("SaveScoreData Failed"), TEXT("FileManager"));
		return;
	}

	DWORD dwByte = 0;
	int size = static_cast<int>(m_vecScore[m_index].size());
	for (int i = 0; i < MAX_SCORE; ++i)
	{
		if (i == size)
			break;
		WriteFile(hFile, &m_vecScore[m_index][i], sizeof(int), &dwByte, nullptr);
	}
	CloseHandle(hFile);
}

void FileManager::LoadScoreData(ID eID)
{
	const TCHAR* path = DataPath(eID);
	HANDLE hFile = CreateFile(path, GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);

	if (INVALID_HANDLE_VALUE == hFile)
		NewFile(eID);

	DWORD dwByte = 0;
	while (true)
	{
		int score = -1;
		ReadFile(hFile, &score, sizeof(int), &dwByte, nullptr);

		if (0 == dwByte)
			break;

		m_vecScore[m_index].emplace_back(score);
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
		m_index = 0;
		return TEXT("../Resources/Data/ScoreSaveData1.txt");
	case FileManager::SCORE2:
		m_index = 1;
		return TEXT("../Resources/Data/ScoreSaveData2.txt");
	case FileManager::SCORE3:
		m_index = 2;
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
