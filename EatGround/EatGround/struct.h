#pragma once

enum class LINE;



struct Line
{
	POINT start;
	POINT end;
	LINE type;
};


typedef struct MySize
{
	int Width;
	int Height;
}Size;

typedef struct MyVector2
{
	float x;
	float y;

	MyVector2 operator+(MyVector2& _vec)const
	{
		return MyVector2({ x + _vec.x, y + _vec.y });
	}

	MyVector2& operator+=(MyVector2& _vec)
	{
		this->x += _vec.x;
		this->y += _vec.y;
		return *this;
	}

}Vector2;


typedef struct MyVector3
{
	float x;
	float y;
	float z;


	MyVector3 operator+(MyVector3& _vec)const
	{
		return MyVector3({ x + _vec.x, y + _vec.y,z + _vec.z });
	}

	MyVector3& operator+=(MyVector3& _vec)
	{
		this->x += _vec.x;
		this->y += _vec.y;
		this->z += _vec.z;
		return *this;
	}

}Vector3;