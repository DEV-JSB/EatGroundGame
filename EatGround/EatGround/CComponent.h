#pragma once
class CComponent abstract
{
public:
	virtual int Update(const int _xChange,const int _yChange) = 0;
	virtual void Render(const HDC _hdc) = 0;
protected:
	CComponent();
	CComponent(bool _render);
public:
	virtual ~CComponent();
protected:
	bool m_bRender;
};

