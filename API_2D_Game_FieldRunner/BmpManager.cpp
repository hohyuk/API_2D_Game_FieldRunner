#include "framework.h"
#include "BmpManager.h"
#include "BitMap.h"

BmpManager* BmpManager::m_pInstance{ nullptr };
HDC BmpManager::Find_Image(const TCHAR* _pKey)
{
	auto iter_find = m_mapBmp.find(_pKey);
	if (iter_find == m_mapBmp.end())
	{
		MESSAGE_BOX(TEXT("Key Not Exists"), TEXT("BmpManager::Find_Image()"));
		return nullptr;
	}


	return iter_find->second->Get_MemDC();
}

void BmpManager::Insert_Texture(const TCHAR* _pKey, const TCHAR* _pFilePath)
{
	auto iter_find = m_mapBmp.find(_pKey);

	if (iter_find != m_mapBmp.end())
	{
		MESSAGE_BOX(TEXT("Key Exists"), TEXT("BmpManager::Insert_Texture()"));
		return;
	}

	BitMap* pBitmap = new BitMap;
	pBitmap->LoadBmp(_pFilePath);
	m_mapBmp.emplace(_pKey, pBitmap);
}

void BmpManager::Release()
{
	for (auto& rPair : m_mapBmp)
		Safe_Delete(rPair.second);
	m_mapBmp.clear();
}

BmpManager::BmpManager()
{
}

BmpManager::~BmpManager()
{
	Release();
}
