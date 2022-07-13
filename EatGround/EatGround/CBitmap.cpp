#include "pch.h"
#include "CBitmap.h"
#include"CGameMgr.h"

CBitmap::CBitmap()
	:CComponent(true)
{
}

CBitmap::~CBitmap()
{
}

CBitmap* CBitmap::Create()
{
	return new CBitmap();
}


int CBitmap::Update(const int _xChange, const int _yChange)
{
	RePositionBitmap((int)(m_vecPos.x += _xChange), (int)(m_vecPos.y += _yChange));
	return 0;
}

void CBitmap::Render(HDC _hdc)
{
	if (m_bRender == false)
		return;
	StretchBlt(_hdc
		, (int)(m_vecPos.x - m_stSize.Width * 0.5f)
		, (int)(m_vecPos.y - m_stSize.Height * 0.5f)
		, (int)m_stSize.Width
		, (int)m_stSize.Height
		, m_hDC
		, 0
		, 0
		, (int)m_bitInfo.bmWidth
		, (int)m_bitInfo.bmHeight
		, SRCCOPY);
}

void CBitmap::RePositionBitmap(const int _x, const int _y)
{
	m_vecPos.x = (float)_x;
	m_vecPos.y = (float)_y;
}

void CBitmap::ResizeBitmap(const int _width, const int _height)
{
	m_stSize.Height = _height;
	m_stSize.Width = _width;
}

void CBitmap::BitmapSetting(const HBITMAP _hbit)
{
	// ¾îÂ¿¼ö¾øÀ½ ¤·¤µ¤·
	m_hDC = CreateCompatibleDC(CGameMgr::GetInstance()->GetMainDC());
	m_hBit = _hbit;
	HBITMAP oldBit = (HBITMAP)SelectObject(m_hDC, m_hBit);
	DeleteObject(oldBit);
	GetObject(m_hBit,sizeof(BITMAP),&m_bitInfo);
}

