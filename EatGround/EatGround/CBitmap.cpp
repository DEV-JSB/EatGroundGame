#include "pch.h"
#include "CBitmap.h"


void CBitmap::SetBitmap(HBITMAP _bitmap)
{
	m_hBit = _bitmap;
}

void CBitmap::SetBitInfo(BITMAP _bitinfo)
{
	m_bitInfo = _bitinfo;
}
