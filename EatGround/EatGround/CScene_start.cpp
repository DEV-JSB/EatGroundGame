#include "pch.h"
#include "CObjectMgr.h"
#include "CObject.h"
#include "CBitmapMgr.h"
#include "CMenuIcon.h"
#include "CScene_start.h"

#define MENU_COUNT 4


CScene_start::~CScene_start()
{
}

CScene_start* CScene_start::Create()
{
	return new CScene_start();
}

void CScene_start::Init()
{
	m_vecFilename.push_back(L"ironmanMenu.bmp");
	m_vecFilename.push_back(L"spidermanMenu.bmp");
	m_vecFilename.push_back(L"warmachineMenu.bmp");
	m_vecFilename.push_back(L"doctorstrangeMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(m_vecFilename);
	
	
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(100, 100, 0));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(200, 100, 0));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(100, 200, 0));
	CObjectMgr::GetInstance()->AddObject(OBJECT::OBJECT_MENUICON, CMenuIcon::Create(200, 200, 0));

	pMenuIcon1->InputBitmap(m_vecFilename[0]);
	pMenuIcon2->InputBitmap(m_vecFilename[1]);
	pMenuIcon3->InputBitmap(m_vecFilename[2]);
	pMenuIcon4->InputBitmap(m_vecFilename[3]);

	pMenuIcon1->Setposition(100, 100, 0);
	pMenuIcon1->InputBitmap(m_vecFilename[0]);
	

}

