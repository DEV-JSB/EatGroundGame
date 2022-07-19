#pragma once
#include"CObject.h"


enum class LINE 
{ 
	LINE_WIDTH, 
	LINE_HEIGHT, 
	LINE_END 
};

class CPlayer : public CObject
{
private:
	bool MeetOnEndLine(const Line _line, const Vector2 _lastpos, const Vector2 _startpos);
	int DrawLine(std::list<Line>& _linelst, const HDC _hdc, const BYTE _r, const BYTE _g, const BYTE _b);
	bool CanAdvance();
	bool IsGetOutImgaeRange(const int _posx, const int _posy);
	bool IsInRange(LINE _etype, const int _posx, const int _posy);
	int SaveLine(const int _x, const int _y, const int _type, bool _directionchange);
	int SaveDrawLineToList();
	int RemakeLine();
	bool PointIsInLine(const Vector2 _point,const Line _line);
private:
	int LateUpdate();
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
	Line				m_stTempLine;
	std::list<Line>		m_lstDrawingLine;
	std::list<Line>		m_lstLine;

	Vector2				m_vecPrevMoveDirection;
	Vector2				m_vecMaxRangeLT;
	Vector2				m_vecMaxRangeRB;

	Vector2				m_vecEatingStartPos;
	Vector2				m_vecEatingEndPos;
};

