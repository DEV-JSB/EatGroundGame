#pragma once
class CBitmapMgr
{
	SINGLE(CBitmapMgr);


public:
	void Init();
private:
	// 파일의 경로를 저장하고 있는 wchar_t

	wchar_t m_szContentPath[255];

};

