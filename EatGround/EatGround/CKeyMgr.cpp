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
		m_vecstKey.push_back({ false, KEYSTATE::KEYSTATE_NOTPTRESSED,KEYSTATE::KEYSTATE_NOTPTRESSED });
}

void CKeyMgr::Update()
{
	HWND hWnd = GetFocus();

	if (nullptr != hWnd)
	{
		for (int i = 0; i < (int)KEY::KEY_LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000 && m_vecstKey[i].State == KEYSTATE::KEYSTATE_NOTPTRESSED )
			{
				m_vecstKey[i].PrevState = KEYSTATE::KEYSTATE_NOTPTRESSED;
				m_vecstKey[i].State = KEYSTATE::KEYSTATE_PRESSED;
				m_vecstKey[i].IsPress = true;
			}
			else if (GetAsyncKeyState(g_arrVK[i]) & 0x8000 && m_vecstKey[i].State == KEYSTATE::KEYSTATE_PRESSED)
			{
				m_vecstKey[i].PrevState = KEYSTATE::KEYSTATE_PRESSED;
				m_vecstKey[i].State = KEYSTATE::KEYSTATE_PRESSED;
				m_vecstKey[i].IsPress = true;
			}
			else
			{
				m_vecstKey[i].State = KEYSTATE::KEYSTATE_NOTPTRESSED;
				m_vecstKey[i].IsPress = false;
			}
		}
	}
	else
	{
		for (int i = 0; i < (int)KEY::KEY_LAST; ++i)
		{
			if (GetAsyncKeyState(g_arrVK[i]) & 0x8000)
			{
				m_vecstKey[i].State = KEYSTATE::KEYSTATE_NOTPTRESSED;
				m_vecstKey[i].IsPress = false;
			}
		}
	}
}

void CKeyMgr::SetFalse()
{
	for (int i = 0; i < (int)KEY::KEY_LAST; ++i)
	{
		m_vecstKey[i].State = KEYSTATE::KEYSTATE_NOTPTRESSED;
		m_vecstKey[i].IsPress = false;
	}
}



CKeyMgr::CKeyMgr()
{

}

CKeyMgr::~CKeyMgr()
{

}

