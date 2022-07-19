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
		return true;
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
		m_vecEatingEndPos.x = (float)m_pTransform->GetPosition_X();
		m_vecEatingEndPos.y = (float)m_pTransform->GetPosition_Y();
		RemakeLine();


		//SaveDrawLineToList();
		m_bDrawingLine = false;
		
		

		// 같은 y 축의 최종값 , 같은 x 축의 최종값 , 최대 최솟값을 통해서 새로운 영역을 그려낸다
		// 땅따먹기는 결과적으로 아니 , 최종적으로 면적이 늘어난다.
		// 즉 면적이 무조건 늘어나게 되어있다
		// 점들을 다 검사하면 어떨까
		// 점들을 다 모아서 검사를 하면 ?? 
		// 점들을 다 검사를 해보자.
		// 내부에 있는 점들을 갱신을 시켜서 없애자
		// 내부에 있는 점들을 갱신해서 최종 점을 만들어야 한다.
	}
	return 0;
}

int CPlayer::RemakeLine()
{
	bool MeetEndLine = false;
	// 찍히는 시작 점과 끝을 기준으로 정한다.
	m_vecEatingEndPos;
	m_vecEatingStartPos;

	// 지금의 경우는 가에의 선분을 제외한 경우이다.
	for (std::list<Line>::iterator iter = m_lstLine.begin(); iter != m_lstLine.end();)
	{
		// 시작 점과 관련이 되어있는 선분을 찾았다 .
		if (PointIsInLine(m_vecEatingStartPos, (*iter)))
		{
			(*iter).end.x = (int)m_vecEatingStartPos.x;
			(*iter).end.y = (int)m_vecEatingStartPos.y;
			MeetEndLine = true;
			++iter;
		}
		else if (PointIsInLine(m_vecEatingEndPos, (*iter)))
		{
			(*iter).start.x = (int)m_vecEatingEndPos.x;
			(*iter).start.y = (int)m_vecEatingEndPos.y;
			
		}
		if (MeetEndLine && iter != m_lstLine.end())
			m_lstLine.erase(iter++);
		else if (iter == m_lstLine.end())
			break;
		else
			++iter;
	}

	for (std::list<Line>::iterator iter = m_lstDrawingLine.begin(); iter != m_lstDrawingLine.end(); ++iter)
	{
		m_lstLine.push_back(*iter);
	}

	return 0;
}

bool CPlayer::PointIsInLine(const Vector2 _point, const Line _line)
{
	switch (_line.type)
	{
	case LINE::LINE_WIDTH:
			if (_line.start.y == _point.y &&
				_line.start.x <= _point.x &&
				_point.x <= _line.end.x)
				return true;
			else if (_line.start.y == _point.y &&
				_line.end.x <= _point.x &&
				_point.x <= _line.start.x)
				return true;
		break;
	case LINE::LINE_HEIGHT:
			if (_line.start.x == _point.x &&
				_line.start.y <= _point.y &&
				_point.y <= _line.end.y)
				return true;
			else if (_line.start.x == _point.x &&
				_line.end.y <= _point.y &&
				_point.y <= _line.start.y)
				return true;
		break;
	}
	return false;
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

			m_vecEatingStartPos.x = (float)m_pTransform->GetPosition_X();
			m_vecEatingStartPos.y = (float)m_pTransform->GetPosition_Y();
			
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
			if (false == IsInRange(LINE::LINE_HEIGHT, (int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y() + 1)
				&& !(IsGetOutImgaeRange((int)m_pTransform->GetPosition_X(), (int)m_pTransform->GetPosition_Y() + 1)))
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

	m_lstLine.push_back(tmp);
	
	tmp.start = { _right , _top };
	tmp.end = { _right , _bottom };
	tmp.type = LINE::LINE_HEIGHT;
	m_lstLine.push_back(tmp);

	tmp.start = { _right , _bottom };
	tmp.end = { _left , _bottom };
	tmp.type = LINE::LINE_WIDTH;
	m_lstLine.push_back(tmp);

	tmp.start = { _left , _bottom };
	tmp.end = { _left , _top };
	tmp.type = LINE::LINE_HEIGHT;
	m_lstLine.push_back(tmp);

	return 0;
}
