#pragma once
#include"CComponent.h"

class CTransform2D :public CComponent
{
public:
	CTransform2D(Vector3 _position,Vector3 _rotation);
	CTransform2D(float _posx, float _posy, float _posz, float _rotx, float _roty, float _rotz);
	CTransform2D();
	~CTransform2D();
public:
	virtual void Update() override;
public:// 임시로 만든거 나중에 고민 해보자
	Vector3 GetPosition() { return m_vecPosition; }
	float GetPosition_X() { return m_vecPosition.x; }
	float GetPosition_Y() { return m_vecPosition.y; }
	void SetPosition(Vector3 _pos) { m_vecPosition = _pos; }
	void SetPosition(const float _x,const float _y,const float _z) { m_vecPosition.x = _x; m_vecPosition.y = _y; m_vecPosition.z = _z; }
private:
	Vector3 m_vecPosition;
	Vector3 m_vecRotation;
};

