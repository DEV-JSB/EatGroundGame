#pragma once
class CGameMgr
{
	SINGLE(CGameMgr);
public:
	void Update();
	void Init(HWND _hdc, POINT _resolution);
	void Render();
	void LateUpdate();
	void Process();
	HDC GetMainDC() { return m_hDC; }
private:
	HWND m_hWnd;
	POINT m_ptResolution;
	HDC m_hDC;

	// ������۸��� ���� �������
	HBITMAP m_hBit;
	HDC m_memDC;
};

