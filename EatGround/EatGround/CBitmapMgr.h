#pragma once
#include"CBitmap.h"
class CBitmapMgr
{
	SINGLE(CBitmapMgr);


public:
	void Init();
	void BitmapLoad(const std::vector<std::wstring> _filelist);
	CBitmap* FindBit(std::wstring _filename) const;
private:
	// 파일의 경로를 저장하고 있는 wchar_t
	wchar_t m_szContentPath[255];

	// 비트맵들을 들고있는 맵
	std::map<std::wstring , CBitmap*> m_mapBitmap;

};

