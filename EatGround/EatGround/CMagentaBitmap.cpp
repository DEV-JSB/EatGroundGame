#include "pch.h"
#include "CMagentaBitmap.h"

CMagentaBitmap::CMagentaBitmap()
	:CBitmap()
{
}

CMagentaBitmap::CMagentaBitmap(const float _r, const float _g, const float _b)
	:CBitmap()
	,m_fR(_r)
	,m_fG(_g)
	,m_fB(_b)
{
}

CMagentaBitmap::~CMagentaBitmap()
{
}

CMagentaBitmap* CMagentaBitmap::Create(const float _r, const float _g, const float _b)
{
	return new CMagentaBitmap(_r,_g,_b);
}

int CMagentaBitmap::Update(const int _xChange, const int _yChange)
{
	CBitmap::Update(_xChange, _yChange);
	return 0;
}


void CMagentaBitmap::Render(HDC _hdc)
{
	if (m_bRender == false)
		return;
	GdiTransparentBlt(_hdc
		, (int)(m_vecPos.x - m_stSize.Width * 0.5f)
		, (int)(m_vecPos.y - m_stSize.Height * 0.5f)
		, (int)m_stSize.Width
		, (int)m_stSize.Height
		, m_hDC
		, 0
		, 0
		, (int)m_bitInfo.bmWidth
		, (int)m_bitInfo.bmHeight
		, RGB(m_fR, m_fG, m_fB));
}

void CMagentaBitmap::SetMagenta(const float _r, const float _g, const float _b)
{
}
