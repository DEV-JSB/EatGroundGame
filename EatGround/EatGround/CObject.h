#pragma once
#include"CComponent.h"
#include"CTransform2D.h"

class CObject
{
protected:
	CObject(const int _x,const int _y,const int _z, const int _width,const int _height);
	CObject(const Vector3 _pos, const Vector3 _rotation, const Vector2 _scale);
	CObject();
public:
	virtual ~CObject();

public: // Bitmap Function
	void SetBitPosition(const int _x, const int _y);
	void SetBitScale(const int _width, const int _height);
	void InputBitmap(std::wstring _bmpname);
public:
	virtual void Render(const HDC _hdc);
	virtual int Update();
public:
	int MoveTransAndBitPosition(const int _x, const int _y);
	void SetTransfornPosition(const int _x, const int _y, const int _z);
protected:
	std::map<COMPONENT, CComponent*> m_mapComponent;
	CTransform2D* m_pTransform;
};

