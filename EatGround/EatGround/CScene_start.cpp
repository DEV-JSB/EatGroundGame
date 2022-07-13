#include "pch.h"
#include "CObjectMgr.h"
#include "CObject.h"
#include "CKeyMgr.h"
#include "CBitmapMgr.h"
#include "CImage.h"
#include "CScene_start.h"

#define MENU_COUNT 4
#define SELECT_MENU_WIDTH 145
#define SELECT_MENU_HEIGHT 190

CScene_start::CScene_start()
{
}

CScene_start::~CScene_start()
{
}

CScene_start* CScene_start::Create()
{
	return new CScene_start();
}

void CScene_start::DrawRect(HDC _hdc, Vector2 _pos, BITMAP _info)
{
	MoveToEx(_hdc, (int)_pos.x - _info.bmWidth / 2, (int)_pos.y - _info.bmHeight / 2, NULL);
	LineTo(_hdc, (int)_pos.x + _info.bmWidth / 2, (int)_pos.y - _info.bmHeight / 2);
	MoveToEx(_hdc, (int)_pos.x + _info.bmWidth / 2, (int)_pos.y - _info.bmHeight / 2, NULL);
	LineTo(_hdc, (int)_pos.x + _info.bmWidth / 2, (int)_pos.y + _info.bmHeight / 2);
	MoveToEx(_hdc, (int)_pos.x - _info.bmWidth / 2, (int)_pos.y + _info.bmHeight / 2, NULL);
	LineTo(_hdc, (int)_pos.x + _info.bmWidth / 2, (int)_pos.y + _info.bmHeight / 2);
	MoveToEx(_hdc, (int)_pos.x - _info.bmWidth / 2, (int)_pos.y + _info.bmHeight / 2, NULL);
	LineTo(_hdc, (int)_pos.x - _info.bmWidth / 2, (int)_pos.y - _info.bmHeight / 2);
}

void CScene_start::DrawSelectRectLine(HDC _hdc,int _Select)
{
	HPEN hPen;
	HPEN hPenOld;
	hPen = CreatePen(PS_SOLID, 5, RGB(255, 0, 0));
	hPenOld = (HPEN)SelectObject(_hdc, hPen);
	Vector2 pos;
	BITMAP info;
	switch (_Select)
	{
	case 1:
		if (S_OK == CBitmapMgr::GetInstance()->GetPos(L"ironmanMenu.bmp", &pos)
			&& S_OK == CBitmapMgr::GetInstance()->GetBitInfo(L"ironmanMenu.bmp", &info))
			DrawRect(_hdc, pos, info);
		else
			assert(1);
		break;
	case 2:
		if (S_OK == CBitmapMgr::GetInstance()->GetPos(L"spidermanMenu.bmp", &pos)
			&& S_OK == CBitmapMgr::GetInstance()->GetBitInfo(L"spidermanMenu.bmp", &info))
			DrawRect(_hdc, pos, info);
		else
			assert(1);
		break;
	case 3:
		if (S_OK == CBitmapMgr::GetInstance()->GetPos(L"warmachineMenu.bmp", &pos)
			&& S_OK == CBitmapMgr::GetInstance()->GetBitInfo(L"warmachineMenu.bmp", &info))
			DrawRect(_hdc, pos, info);
		else
			assert(1);
		break;
	case 4:
		if (S_OK == CBitmapMgr::GetInstance()->GetPos(L"doctorstrangeMenu.bmp", &pos)
			&& S_OK == CBitmapMgr::GetInstance()->GetBitInfo(L"doctorstrangeMenu.bmp", &info))
			DrawRect(_hdc, pos, info);
		else
			assert(1);
		break;
	}

	hPen = (HPEN)SelectObject(_hdc, hPenOld);
	DeleteObject(hPen);
}


int CScene_start::Update()
{
	if (m_iSelectImage != 1 &&
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_LEFT).IsPress&&
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_LEFT).PrevState == KEYSTATE::KEYSTATE_NOTPTRESSED)
		--m_iSelectImage;
	if (m_iSelectImage != 4 && 
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_RIGHT).IsPress&&
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_RIGHT).PrevState == KEYSTATE::KEYSTATE_NOTPTRESSED)
		++m_iSelectImage;
	if (m_iSelectImage != 4 && m_iSelectImage != 3 && 
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_DOWN).IsPress&&
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_DOWN).PrevState == KEYSTATE::KEYSTATE_NOTPTRESSED)
		m_iSelectImage += 2;
	if (m_iSelectImage != 1 && m_iSelectImage != 2 && 
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_UP).IsPress&&
		CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_UP).PrevState == KEYSTATE::KEYSTATE_NOTPTRESSED)
		m_iSelectImage -= 2;
	if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_SPACE).IsPress)
		return m_iSelectImage;
	
	return 0;
}

int CScene_start::Render(HDC _hdc)
{
	for (int i = 0; (OBJECT)i < OBJECT::OBJECT_END; ++i)
		CObjectMgr::GetInstance()->Render(_hdc);
	DrawSelectRectLine(_hdc, m_iSelectImage);
	return 0;
}

int CScene_start::Init()
{

	m_iSelectImage = 1;

	CBitmapMgr::GetInstance()->BitmapLoad(L"ironmanMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(L"spidermanMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(L"warmachineMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(L"doctorstrangeMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(L"Logo.bmp");
	

	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_IMAGE, CImage::Create(WINX / 4		   , WINY  / 2,	0, SELECT_MENU_WIDTH, SELECT_MENU_HEIGHT,		   L"ironmanMenu.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_IMAGE, CImage::Create(WINX / 2 + WINX / 4, WINY  / 2, 0, SELECT_MENU_WIDTH, SELECT_MENU_HEIGHT,		   L"spidermanMenu.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_IMAGE, CImage::Create(WINX / 4		   , WINY / 2 + WINY / 4, 0, SELECT_MENU_WIDTH, SELECT_MENU_HEIGHT,   L"warmachineMenu.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_IMAGE, CImage::Create(WINX / 2 + WINX / 4, WINY / 2 + WINY / 4, 0, SELECT_MENU_WIDTH, SELECT_MENU_HEIGHT, L"doctorstrangeMenu.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_LOGO,  CImage::Create(WINX / 2		   , WINY / 4 - 70, 0, 512, 280,	   L"Logo.bmp"));

	m_rcCursor[(int)PHOTO::PHOTO_IRONMAN];
	return 0;
}

int CScene_start::Release()
{
	CBitmapMgr::GetInstance()->Release();
	CObjectMgr::GetInstance()->Release();
	
	return 0;
}

