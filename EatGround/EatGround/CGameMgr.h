#pragma once
class CGameMgr
{
	SINGLE(CGameMgr);


public:
	void Update();
	void Init();
	void Render();


private:
	HWND m_hWnd;
	POINT m_ptResolution;
};

