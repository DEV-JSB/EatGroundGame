#include "pch.h"
#include "CComponent.h"
#include "CTransform2D.h"

CTransform2D::CTransform2D(Vector3 _position, Vector3 _rotation)
	:m_vecPosition(_position)
	,m_vecRotation(_rotation)
{

}

CTransform2D::CTransform2D(float _posx, float _posy, float _posz, float _rotx, float _roty, float _rotz)
	: m_vecPosition({_posx,_posy,_posz})
	, m_vecRotation({_rotx,_roty,_rotz})
{
}

CTransform2D::CTransform2D()
{
}

CTransform2D::~CTransform2D()
{
}

void CTransform2D::Update()
{
}
