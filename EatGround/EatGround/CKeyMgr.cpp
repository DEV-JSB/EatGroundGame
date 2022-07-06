#include "pch.h"
#include "CKeyMgr.h"


int g_arrVK[(int)KEY::KEY_LAST] =
{
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	VK_SPACE
};


void CKeyMgr::Init()
{
	for (int i = 0; i < (int)KEY::KEY_LAST; ++i)
	{
		m_vecKey.push_back(false);
	}
}

void CKeyMgr::Update()
{
	HWND hWnd = GetFocus();

	if (nullptr != hWnd)
	{
		for (int i = 0; i < (int)KEY::KEY_LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrVK[i] & 0x8000))
				m_vecKey[i] = true;
			else
				m_vecKey[i] = false;
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::KEY_LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrVK[i] & 0x8000))
				m_vecKey[i] = false;
		}
	}
		
}

CKeyMgr::CKeyMgr()
{

}

CKeyMgr::~CKeyMgr()
{

}

