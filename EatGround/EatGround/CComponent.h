#pragma once
class CComponent abstract
{
public:
	virtual void Update() = 0;
	virtual void Render(const HDC _hdc) = 0;
protected:
	CComponent();
	CComponent(bool _render);
	virtual ~CComponent();
protected:
	bool m_bRender;
};

