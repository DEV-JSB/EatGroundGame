#include "pch.h"
#include "CBitmapMgr.h"


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

void CBitmapMgr::BitmapLoad(const std::vector<std::wstring> _filelist)
{
	for (int i = 0; i < (int)_filelist.size(); ++i)
	{
		CBitmap* newBitmap;
		newBitmap = FindBit(_filelist[i]);
		if (nullptr == newBitmap)
		{
			std::wstring filepath;
			filepath += m_szContentPath;
			filepath += _filelist[i];
			newBitmap->SetBitmap(((HBITMAP)LoadImage(nullptr, filepath.c_str(), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE)));
			m_mapBitmap.insert({ _filelist[i],newBitmap });
		}
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
