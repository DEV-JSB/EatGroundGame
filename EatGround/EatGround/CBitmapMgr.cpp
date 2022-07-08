#include "pch.h"
#include "CBitmapMgr.h"
#include "CGameMgr.h"

CBitmapMgr::CBitmapMgr()
	:m_szContentPath{}
{}

CBitmapMgr::~CBitmapMgr()
{}

void CBitmapMgr::Init()
{
	GetCurrentDirectory(255, m_szContentPath);
	wcscat_s(m_szContentPath, L"\\Bitmap\\");
}

void CBitmapMgr::BitmapLoad(const std::wstring _filename)
{
	CBitmap* newBitmap;
	newBitmap = FindBit(_filename);
	if (nullptr == newBitmap)
	{
		newBitmap = CBitmap::Create();
		std::wstring filepath;
		filepath += m_szContentPath;
		filepath += _filename;
		newBitmap->BitmapSetting(((HBITMAP)LoadImage(nullptr, filepath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE)));

		m_mapBitmap.insert({ _filename,newBitmap });
	}
}

CBitmap* CBitmapMgr::FindBit(std::wstring _filename) const
{
	auto iter = m_mapBitmap.find(_filename);
	if (iter == m_mapBitmap.end())
		return nullptr;
	else
		return (*iter).second;
}
