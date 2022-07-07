#pragma once
#include"CComponent.h"
class CBitmap : public CComponent 
{




private:
	HDC		m_dc;
	
	HBITMAP	m_hBit;

	BITMAP	m_bitInfo;

};

