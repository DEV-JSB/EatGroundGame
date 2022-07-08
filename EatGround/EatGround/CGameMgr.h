#pragma once
class CGameMgr
{
	SINGLE(CGameMgr);


public:
	void Update();
	void Init(HWND _hdc, POINT _resolution);
	void Render();
	HWND GetMainHandle() { return m_hWnd; }
private:
	HWND m_hWnd;
	POINT m_ptResolution;
	HDC m_hDC;

	// 더블버퍼링을 위한 멤버변수
	HBITMAP m_hBit;
	HDC m_memDC;
};

