#include "pch.h"
#include "CObjectMgr.h"
#include "CScene_stage1.h"
#include"CBitmapMgr.h"
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
	return 0;
}

int CScene_stage1::Init()
{
	switch (m_eBitmapType)
	{
	case IMAGE::IMAGE_IRONMAN:
		CBitmapMgr::GetInstance()->BitmapLoad(L"ironman.bmp");
		break;
	case IMAGE::IMAGE_SPIDERMAN:
		CBitmapMgr::GetInstance()->BitmapLoad(L"spiderman.bmp");
		break;
	case IMAGE::IMAGE_DOCTORSTARNGE:
		CBitmapMgr::GetInstance()->BitmapLoad(L"doctorstrange.bmp");
		break;
	case IMAGE::IMAGE_WARMACHINE:
		CBitmapMgr::GetInstance()->BitmapLoad(L"warmachineMenu");
		break;
	}
	

	return 0;
}

int CScene_stage1::Release()
{
	return 0;
}
