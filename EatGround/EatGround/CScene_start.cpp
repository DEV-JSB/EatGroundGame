#include "pch.h"
#include "CObjectMgr.h"
#include "CBitmapMgr.h"
#include "CMenuIcon.h"
#include "CScene_start.h"

#define MENU_COUNT 4


void CScene_start::Init()
{
	m_vecFilename.push_back(L"ironmanMenu.bmp");
	m_vecFilename.push_back(L"spidermanMenu.bmp");
	m_vecFilename.push_back(L"warmachineMenu.bmp");
	m_vecFilename.push_back(L"doctorstrangeMenu.bmp");
	CBitmapMgr::GetInstance()->BitmapLoad(m_vecFilename);
	
	
	for (int i = 0; i < MENU_COUNT; ++i)
		CObjectMgr::GetInstance()->RegisterObject(OBJECT::OBJECT_MENUICON,CMenuIcon::Create());
	

}

