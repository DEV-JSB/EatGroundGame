#include "pch.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"
#include "CPlayer.h"

#define POINT_END 1
#define POINT_START 0



bool CPlayer::IsGetOutImgaeRange(const int _posx, const int _posy)
{
	if (_posx < m_vecMaxRangeLT.x || m_vecMaxRangeRB.x < _posx
		|| _posy < m_vecMaxRangeLT.y || m_vecMaxRangeRB.y < _posy)
	{
		return true;
	}
	else
		return false;
}

bool CPlayer::IsInRange(LINE _etype, const int _posx, const int _posy)
{
	for (std::list<Line>::iterator iter = m_lstLine.begin(); iter != m_lstLine.end(); ++iter)
	{
		switch (_etype)
		{
		case LINE::LINE_WIDTH:
			if ((*iter).type == LINE::LINE_WIDTH)
			{
				if ((*iter).start.y == _posy &&
					(*iter).start.x <= _posx &&
					_posx <= (*iter).end.x)
					return true;
				else if ((*iter).start.y == _posy &&
					(*iter).end.x <= _posx &&
					_posx <= (*iter).start.x)
					return true;
			}
			break;
		case LINE::LINE_HEIGHT:
			if ((*iter).type == LINE::LINE_HEIGHT)
			{
				if ((*iter).start.x == _posx &&
					(*iter).start.y <= _posy &&
					_posy <= (*iter).end.y)
					return true;
				else if ((*iter).start.x == _posx &&
					(*iter).end.y <= _posy &&
					_posy <= (*iter).start.y)
					return true;
			}
			break;
		}
	}
	return false;
}
int CPlayer::SaveLine(const int _x, const int _y, const int _type,bool _directionchange)
{
	if (!_directionchange)
		return 0;
	switch (_type)
	{
	case POINT_START:
		m_stTempLine.start.x = _x;
		m_stTempLine.start.y = _y;
		break;
	case POINT_END:
		m_stTempLine.end.x = _x;
		m_stTempLine.end.y = _y;
		// Line TypeSelect
		if (m_stTempLine.end.x == m_stTempLine.start.x)
			m_stTempLine.type = LINE::LINE_HEIGHT;
		else
			m_stTempLine.type = LINE::LINE_WIDTH;

		// Final LineSave In PlayerRange
		m_lstDrawingLine.push_back(m_stTempLine);
		m_stTempLine.start.x = _x;
		m_stTempLine.start.y = _y;
		printf("라인 저장!\n");
		break;
	}
	return 0;
}

int CPlayer::DrawLineRange(HDC _hdc)
{
	if (m_lstLine.size() == 0)
		return 0;
	HPEN hPen;
	HPEN hPenOld;

	hPen = CreatePen(PS_SOLID, 5, RGB(100, 100, 100));
	hPenOld = (HPEN)SelectObject(_hdc, hPen);

	for (std::list<Line>::iterator iter = m_lstLine.begin(); iter != m_lstLine.end(); ++iter)
	{
		MoveToEx(_hdc, (*iter).start.x, (*iter).start.y, NULL);
		LineTo(_hdc, (*iter).end.x, (*iter).end.y);
	}

	hPen = (HPEN)SelectObject(_hdc, hPenOld);
	DeleteObject(hPen);
	return 0;
}

int CPlayer::DrawDrawingLine(HDC _hdc)
{
	if (m_lstDrawingLine.size() == 0)
		return 0;
	HPEN hPen;
	HPEN hPenOld;

	hPen = CreatePen(PS_SOLID, 5, RGB(200, 200, 200));
	hPenOld = (HPEN)SelectObject(_hdc, hPen);

	for (std::list<Line>::iterator iter = m_lstDrawingLine.begin(); iter != m_lstDrawingLine.end(); ++iter)
	{
		MoveToEx(_hdc, (*iter).start.x, (*iter).start.y, NULL);
		LineTo(_hdc, (*iter).end.x, (*iter).end.y);
	}

	hPen = (HPEN)SelectObject(_hdc, hPenOld);
	DeleteObject(hPen);
	return 0;
}

int CPlayer::LateUpdate()
{
	if (m_bDrawingLine && m_lstDrawingLine.size() > 0 && 
		(IsInRange(LINE::LINE_WIDTH, (int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y()) || 
		IsInRange(LINE::LINE_HEIGHT, (int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y())))
	{
		SaveLine((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y(), POINT_END, true);
		SaveDrawLineToList();
		m_bDrawingLine = false;
		printf("라인 최종 저장!!\n");
	}
	return 0;
}

int CPlayer::SaveDrawLineToList()
{
	for (std::list<Line>::iterator iter = m_lstDrawingLine.begin(); iter != m_lstDrawingLine.end(); ++iter)
	{
		m_lstLine.push_back(*iter);
	}
	m_lstDrawingLine.clear();
	return 0;
}


CPlayer::CPlayer(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
	: CObject(_x, _y, _z, _width, _height)
	, m_vecPrevMoveDirection{0,0}
	, m_bDrawingLine(false)
{
	CObject::InputBitmap(_name);

	// 기본적으로 비트맵을 생성할때 메뉴 아이콘의 기존 사이즈와 포지션을 따르도록 한다.
	CObject::SetBitScale(_width, _height);
	CObject::SetBitPosition(_x, _y);
}


CPlayer::~CPlayer()
{
}
CPlayer* CPlayer::Create(const int _x, const int _y, const int _z, const int _width, const int _height, const std::wstring _name)
{
	return new CPlayer(_x, _y, _z, _width, _height, _name);
}





void CPlayer::Render(HDC _hdc)
{
	CObject::Render(_hdc);

	DrawLineRange(_hdc);
	DrawDrawingLine(_hdc);
}

int CPlayer::Update()
{
	// Holding Space
	if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_SPACE).IsPress)
	{
		if (KEYSTATE::KEYSTATE_NOTPTRESSED == CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_SPACE).PrevState)
		{
			m_bDrawingLine = true;
			SaveLine((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y(), POINT_START, true);
			printf("시작점 저장 x : %f , y : %f\n", m_pTransform->GetPosition_X(), m_pTransform->GetPosition_Y());
			m_vecPrevMoveDirection = { 0,0 };
		}
		// If Holding Space and Enter Drawing Mode then player Can't move InArea OnlyNew Position can move
		if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_LEFT).IsPress)
		{
			SaveLine((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y(), POINT_END,
				0 != m_vecPrevMoveDirection.y);
			if (false == IsInRange(LINE::LINE_WIDTH, (int)m_pTransform->GetPosition_X() - 1, (int)m_pTransform->GetPosition_Y())
				&& !(IsGetOutImgaeRange((int)m_pTransform->GetPosition_X() - 1, (int)m_pTransform->GetPosition_Y())))
			{
				CObject::MoveTransAndBitPosition(-1, 0);
				m_vecPrevMoveDirection = { -1,0 };
			}
		}
		else if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_RIGHT).IsPress)
		{ 
			SaveLine((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y(), POINT_END,
				0 != m_vecPrevMoveDirection.y);
			if (false == IsInRange(LINE::LINE_WIDTH, (int)m_pTransform->GetPosition_X() + 1, (int)m_pTransform->GetPosition_Y())
				&& !(IsGetOutImgaeRange((int)m_pTransform->GetPosition_X() + 1, (int)m_pTransform->GetPosition_Y())))
			{
				CObject::MoveTransAndBitPosition(1, 0);
				m_vecPrevMoveDirection = { 1,0 };
			} 
		}
		else if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_UP).IsPress)
		{  
			SaveLine((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y(), POINT_END, 
				0 != m_vecPrevMoveDirection.x);
			if (false == IsInRange(LINE::LINE_HEIGHT, (int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y() - 1)
				&& !(IsGetOutImgaeRange((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y() - 1)))
			{
				CObject::MoveTransAndBitPosition(0, -1);
				m_vecPrevMoveDirection = { 0,-1 };
			}
		}
		else if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_DOWN).IsPress)
		{ 
			SaveLine((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y(), POINT_END, 
				0 != m_vecPrevMoveDirection.x);
			if (false == IsInRange(LINE::LINE_WIDTH, (int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y() + 1)
				&& !(IsGetOutImgaeRange((int)m_pTransform->GetPosition_X() - 1, (int)m_pTransform->GetPosition_Y() + 1)))
			{
				CObject::MoveTransAndBitPosition(0, 1);
				m_vecPrevMoveDirection = { 0,1 };
			}
		}
	}
	// Not Holding Space [Limit Move Range]
	else
	{
		if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_RIGHT).IsPress)
		{
			if (IsInRange(LINE::LINE_WIDTH, (int)m_pTransform->GetPosition_X() + 1, (int)m_pTransform->GetPosition_Y()))
			{
				CObject::MoveTransAndBitPosition(1, 0);
				m_vecPrevMoveDirection = { 1,0 };
			}
		}
		if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_LEFT).IsPress)
		{
			if (IsInRange(LINE::LINE_WIDTH, (int)m_pTransform->GetPosition_X() - 1, (int)m_pTransform->GetPosition_Y()))
			{
				CObject::MoveTransAndBitPosition(-1, 0);
				m_vecPrevMoveDirection = { -1,0 };
			}
		}
		if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_DOWN).IsPress)
		{
			if (IsInRange(LINE::LINE_HEIGHT, (int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y() + 1))
			{
				CObject::MoveTransAndBitPosition(0, 1);
				m_vecPrevMoveDirection = { 0,1 };
			}
		}
		if (CKeyMgr::GetInstance()->GetKeyState(KEY::KEY_UP).IsPress)
		{
			if (IsInRange(LINE::LINE_HEIGHT, (int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y() - 1))
			{
				CObject::MoveTransAndBitPosition(0, -1);
				m_vecPrevMoveDirection = { 0,-1 };
			}
		}
	}


	LateUpdate();

	return 0;
}

int CPlayer::SettingMoveNavi(const int _left, const int _top, const int _right, const int _bottom)
{
	m_vecMaxRangeLT.x = (float)_left;
	m_vecMaxRangeLT.y = (float)_top;
	m_vecMaxRangeRB.x = (float)_right;
	m_vecMaxRangeRB.y = (float)_bottom;



	Line tmp;
	tmp.start = { _left , _top };
	tmp.end = { _right , _top };
	tmp.type = LINE::LINE_WIDTH;

	m_lstLine.push_back({ { _left , _top } , { _right , _top } , LINE::LINE_WIDTH });
	
	tmp.start = { _left , _bottom};
	tmp.end = { _right , _bottom };
	tmp.type = LINE::LINE_WIDTH;
	m_lstLine.push_back(tmp);

	tmp.start = { _left , _top };
	tmp.end = { _left , _bottom };
	tmp.type = LINE::LINE_HEIGHT;
	m_lstLine.push_back(tmp);

	tmp.start = { _right , _top };
	tmp.end = { _right , _bottom };
	tmp.type = LINE::LINE_HEIGHT;
	m_lstLine.push_back(tmp);

	return 0;
}
