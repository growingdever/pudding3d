#pragma once

#include "Matrix.h"

class Vector2
{
public:
	float x, y;
	Vector2();
	Vector2(float initx, float inity);
	Vector2(const Vector2& vec);
	~Vector2();

	Vector2 Nomalize(); //�������͸���
	float Length();		//ũ����
		
	Vector2 operator+(const Vector2& vec) const;
	Vector2 operator-(const Vector2& vec) const;
	Vector2 operator-(void) const; //��ȣ����
	
	Vector2 operator*(const float scalar) const;
	friend Vector2 operator*(const float scalar, const Vector2& vec);
	Vector2 operator/(const float scalar) const;
	
	float operator*(const Vector2& vec) const; //����	
		
	Vector2& operator+=(const Vector2& vec);
	Vector2& operator-=(const Vector2& vec);
	Vector2& operator*=(const float scalar);
	Vector2& operator/=(const float scalar);

	//��İ���
	Vector2 operator*(const Matrix2 m) const;
};

/*
����a
�غ� = a*cos��Ÿ 
������ ������ ��� ������ �κ��Ͱ� ���� ������ ���ϰ� �ִ��� �ƴ��� �˼��ִ�.
*/