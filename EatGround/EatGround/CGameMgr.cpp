#include "pch.h"
#include "CGameMgr.h"
#include "CSceneMgr.h"
#include "CTimeMgr.h"
#include "CObjectMgr.h"
#include"CBitmapMgr.h"

CGameMgr::CGameMgr()
{}
CGameMgr::~CGameMgr()
{}

void CGameMgr::Init(HWND _hdc,POINT _resolution)
{
	m_hWnd = _hdc;
	m_hDC = GetDC(m_hWnd);
	m_ptResolution = _resolution;

	RECT rt = { 0 , 0 , m_ptResolution.x , m_ptResolution.y };
	
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
	SetWindowPos(m_hWnd, nullptr, 200, 200, rt.right - rt.left, rt.bottom - rt.top, 0);

	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_memDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_memDC, m_hBit);
	DeleteObject(hOldBit);

	CBitmapMgr::GetInstance()->Init();
	CTimeMgr::GetInstance()->Init();
	CObjectMgr::GetInstance()->Init();
	CSceneMgr::GetInstance()->Init();
}

void CGameMgr::Render()
{
	Rectangle(m_memDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInstance()->Render(m_memDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y,
		m_memDC, 0, 0, SRCCOPY);
}
