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
	bool IsGetOutImgaeRange(const int _posx, const int _posy);
	bool IsInRange(LINE _etype, const int _posx, const int _posy);
	int SaveLine(const int _x, const int _y, const int _type, bool _directionchange);
	int DrawLineRange(HDC _hdc);
	int DrawDrawingLine(HDC _hdc);
	int LateUpdate();
	int SaveDrawLineToList();
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
	bool				m_bDrawingLine;
	Vector2				m_vecPrevMoveDirection;
	Line				m_stTempLine;
	std::list<Line>		m_lstDrawingLine;
	std::list<Line>		m_lstLine;

	Vector2				m_vecMaxRangeLT;
	Vector2				m_vecMaxRangeRB;
};

