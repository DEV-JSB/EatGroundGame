#include "pch.h"
#include "CMagentaBitmap.h"

CMagentaBitmap::CMagentaBitmap(const float _r, const float _g, const float _b)
	:m_fR(_r)
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

void CMagentaBitmap::Update()
{
}

void CMagentaBitmap::Render(HDC _hdc)
{
}

void CMagentaBitmap::SetMagenta(const float _r, const float _g, const float _b)
{
}
