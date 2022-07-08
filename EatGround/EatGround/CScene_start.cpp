#include "pch.h"
#include "CObjectMgr.h"
#include "CObject.h"
#include "CBitmapMgr.h"
#include "CMenuIcon.h"
#include "CScene_start.h"

#define MENU_COUNT 4


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

void CScene_start::Update()
{
}

void CScene_start::Render(HDC _hdc)
{
	for (int i = 0; (OBJECT)i < OBJECT::OBJECT_END; ++i)
	{
		CObjectMgr::GetInstance()->Render(_hdc);
	}
}

void CScene_start::Init()
{
	CBitmapMgr::GetInstance()->BitmapLoad(L"ironmanMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(L"spidermanMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(L"warmachineMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(L"doctorstrangeMenu.bmp");

	
	//Create :  x , y , z , width , height , filename
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(100, 100, 0 , 50 , 50 , L"ironmanMenu.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(200, 100, 0 , 50 , 50 , L"spidermanMenu.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(100, 200, 0 , 50 , 50 , L"warmachineMenu.bmp"));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(200, 200, 0 , 50 , 50 , L"doctorstrangeMenu.bmp"));



}

