#include "pch.h"
#include "CBitmap.h"


void CBitmap::Render()
{

	//BitBlt(m_hdc,m_vecPos.x - m_stSize.Width/2,m_vecPos.y - m_stSize.Width/2,m_stSize.Width,m_stSize.Height,);
}

void CBitmap::SetBitmap(HBITMAP _bitmap)
{
	m_hBit = _bitmap;
}

void CBitmap::SetBitInfo(BITMAP _bitinfo)
{
	m_bitInfo = _bitinfo;
}
