#pragma once
#include"CComponent.h"

class CTransform2D :public CComponent
{
public:
	CTransform2D(const Vector3 _position,const Vector3 _rotation);
	CTransform2D(const float _posx, const float _posy, const float _posz, const float _rotx, const float _roty, const float _rotz);
	CTransform2D(const float _posx, const float _posy, const float _posz, const float _rotx, const float _roty, const float _rotz , const float _width , const float _height);
	CTransform2D(const Vector3 _position, const Vector3 _rotation, const Vector2 _scale);

	CTransform2D();
	virtual ~CTransform2D();
public:
	virtual int Update(const int _xChange, const int _yChange) override;
	virtual void Render(HDC _hdc) override;
public:// 임시로 만든거 나중에 고민 해보자
	Vector3 GetPosition() { return m_vecPosition; }
	float GetPosition_X() { return m_vecPosition.x; }
	float GetPosition_Y() { return m_vecPosition.y; }
	void SetPosition(Vector3 _pos) { m_vecPosition = _pos; }
	void SetPosition(const float _x,const float _y,const float _z) { m_vecPosition.x = _x; m_vecPosition.y = _y; m_vecPosition.z = _z; }
private:
	Vector3 m_vecPosition;
	Vector3 m_vecRotation;
	Vector2 m_vecScale;
};

