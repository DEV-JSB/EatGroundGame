#include "pch.h"
#include "CObjectMgr.h"
#include "CScene_stage1.h"
#include "CObjectMgr.h"
#include "CImage.h"
#include "CPlayer.h"
#include "CBitmapMgr.h"

#define INGAME_WIDTH 600
#define INGAME_HEIGHT 834

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
	for (int i = 0; (OBJECT)i < OBJECT::OBJECT_END; ++i)
		CObjectMgr::GetInstance()->Update();
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
	
	// 우선 세팅은 이미지의 좌상단으로 고정을 한다
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_PLAYER, CPlayer::Create((int)(WINX * 0.5 - 300), (int)(WINY * 0.5 - 417), 0, 14, 14, L"Player.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_IMAGE, CImage::Create((int)(WINX * 0.5f), (int)(WINY * 0.5f), 0, INGAME_WIDTH, INGAME_HEIGHT, bmpName));

	std::list<CObject*> lst = CObjectMgr::GetInstance()->GetObjectList(OBJECT::OBJECT_PLAYER);
	CObject* tmp = lst.front();
	CPlayer* player = dynamic_cast<CPlayer*>(tmp);
	player->SettingMoveNavi((int)(WINX * 0.5f - INGAME_WIDTH * 0.5f), (int)(WINY * 0.5f - INGAME_HEIGHT* 0.5f),
							(int)(WINX * 0.5f + INGAME_WIDTH * 0.5f), (int)(WINY * 0.5f + INGAME_WIDTH * 0.5f));
	return 0;
}

int CScene_stage1::Release()
{
	return 0;
}
