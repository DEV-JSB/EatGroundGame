#pragma once
#include"CBitmap.h"
class CMagentaBitmap : public CBitmap
{
private:
	CMagentaBitmap();
	CMagentaBitmap(const float _r, const float _g, const float _b);
public:
	virtual ~CMagentaBitmap();
public:

	static CMagentaBitmap* Create(const float _r, const float _g, const float _b);
	virtual void Update()			override;
	virtual void Render(HDC _hdc)	override;

	void SetMagenta(const float _r, const float _g, const float _b);

private:
	float m_fR;
	float m_fG;
	float m_fB;
};

