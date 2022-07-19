#pragma once
#include"CObject.h"
class CField : public CObject
{
private:
	CField();
	CField(const std::list<Line>& _linelst);
public:
	virtual ~CField();
public:
	virtual void Render(const HDC _hdc) override;
	virtual int  Update()				override;

private:
	std::list<Line> m_lstLine;
	
};

