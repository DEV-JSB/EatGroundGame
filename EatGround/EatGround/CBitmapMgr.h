#pragma once
#include"CBitmap.h"
class CBitmapMgr
{
	SINGLE(CBitmapMgr);


public:
	void Init();
	void Release();
	void BitmapLoad(const std::wstring _filename);
	CBitmap* FindBit(std::wstring _filename) const;
	
	HRESULT GetPos(std::wstring _filename, Vector2* _pos);
	HRESULT GetBitInfo(std::wstring _filename, BITMAP* _info);
private:
	// 파일의 경로를 저장하고 있는 wchar_t
	wchar_t m_szContentPath[255];

	// 비트맵들을 들고있는 맵
	std::map<std::wstring , CBitmap*> m_mapBitmap;

};

