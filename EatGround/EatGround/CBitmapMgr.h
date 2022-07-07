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
	// ������ ��θ� �����ϰ� �ִ� wchar_t
	wchar_t m_szContentPath[255];

	// ��Ʈ�ʵ��� ����ִ� ��
	std::map<std::wstring , CBitmap*> m_mapBitmap;

};

