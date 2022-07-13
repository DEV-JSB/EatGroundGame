#include "pch.h"
#include "CObjectMgr.h"
#include "CScene_stage1.h"
#include "CObjectMgr.h"
#include "CImage.h"
#include "CBitmapMgr.h"
CScene_stage1::CScene_stage1()
{
}
CScene_stage1::CScene_stage1(IMAGE _Type)
	:m_eBitmapType(_Type)
{
}

CScene_stage1::~CScene_stage1()
{
}

CScene_stage1* CScene_stage1::Create(IMAGE _Type)
{
	return new CScene_stage1(_Type);
}



int CScene_stage1::Update()
{
	return 0;
}

int CScene_stage1::Render(HDC _hdc)
{
	for (int i = 0; (OBJECT)i < OBJECT::OBJECT_END; ++i)
		CObjectMgr::GetInstance()->Render(_hdc);
	return 0;
}

int CScene_stage1::Init()
{
	std::wstring bmpName;
	switch (m_eBitmapType)
	{
	case IMAGE::IMAGE_IRONMAN:
		bmpName = L"ironman.bmp";
		CBitmapMgr::GetInstance()->BitmapLoad(bmpName);
		break;
	case IMAGE::IMAGE_SPIDERMAN:
		bmpName = L"spiderman.bmp";
		CBitmapMgr::GetInstance()->BitmapLoad(bmpName);
		break;
	case IMAGE::IMAGE_DOCTORSTARNGE:
		bmpName = L"doctorstrange.bmp";
		CBitmapMgr::GetInstance()->BitmapLoad(bmpName);
		break;
	case IMAGE::IMAGE_WARMACHINE:
		bmpName = L"warmachine.bmp";
		CBitmapMgr::GetInstance()->BitmapLoad(bmpName);
		break;
	}
	CBitmapMgr::GetInstance()->BitmapLoad(L"Player.bmp", 0, 128, 128);

	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_PLAYER, CImage::Create(WINX / 2, WINY / 2, 0, 14, 14, L"Player.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_IMAGE, CImage::Create(WINX / 2, WINY / 2, 0, 600 , 834, bmpName));




	return 0;
}

int CScene_stage1::Release()
{
	return 0;
}
