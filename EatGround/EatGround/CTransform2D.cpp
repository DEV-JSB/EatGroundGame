#include "pch.h"
#include "CComponent.h"
#include "CTransform2D.h"

CTransform2D::CTransform2D(const Vector3 _position, const  Vector3 _rotation)
	:CComponent(false)
	,m_vecPosition(_position)
	,m_vecRotation(_rotation)
	,m_vecScale({0,0})
{

}

CTransform2D::CTransform2D(const float _posx, const  float _posy, const  float _posz, const  float _rotx, const float _roty, const float _rotz)
	: m_vecPosition({ _posx,_posy,_posz })
	, m_vecRotation({ _rotx,_roty,_rotz })
	, m_vecScale({ 0,0 })
{
}

CTransform2D::CTransform2D(const float _posx, const float _posy, const float _posz, const float _rotx, const float _roty, const float _rotz, const float _width, const float _height)
	: m_vecPosition({_posx,_posy,_posz})
	, m_vecRotation({_rotx,_roty,_rotz})
	, m_vecScale({_width,_height})
{
}

CTransform2D::CTransform2D(const Vector3 _position, const Vector3 _rotation, const Vector2 _scale)
	: m_vecPosition(_position)
	, m_vecRotation(_rotation)
	, m_vecScale(_scale)
{

}

CTransform2D::CTransform2D()
{
}

CTransform2D::~CTransform2D()
{
}

int CTransform2D::Update(const int _xChange, const int _yChange)
{
	m_vecPosition.x += _xChange;
	m_vecPosition.y += _yChange;
	return 0;
}

void CTransform2D::Render(HDC _hdc)
{
	if (m_bRender == false)
		return;
}
