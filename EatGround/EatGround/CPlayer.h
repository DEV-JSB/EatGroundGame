#pragma once
#include"CObject.h"


enum class LINE 
{ 
	LINE_WIDTH, 
	LINE_HEIGHT, 
	LINE_END 
};
struct Line
{
	POINT start;
	POINT end;
	LINE type;
};


class CPlayer : public CObject
{
private:
	bool IsCanMove(LINE _etype);
private:
	CPlayer();
	CPlayer(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name);
public:
	static CPlayer* Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name);
	virtual ~CPlayer() override;
public:
	virtual void Render(HDC _hdc) override;
	virtual int Update() override;

	int SettingMoveNavi(const int _left,const int _top,const int _right,const int _bottom);
private:
	std::list<Line> m_lstLine;
};

