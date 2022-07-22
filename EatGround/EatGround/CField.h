#pragma once
#include"CObject.h"
class CField : public CObject
{
private:
	CField();
	CField(const int _left, const int _up, const int _right, const int _down);
public:
	static CField* Create(const int _left, const int _up, const int _right, const int _down);
	virtual ~CField();
public:
	virtual void Render(const HDC _hdc) override;
	virtual int  Update()				override;

private:
	std::list<POINT> m_lstPoint;
	
};

