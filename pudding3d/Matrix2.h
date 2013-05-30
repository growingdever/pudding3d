#pragma once

class Matrix2
{
public:
	float a11, a12;
	float a21, a22;

	Matrix2();
	Matrix2(float m11, float m12, float m21, float m22);
	~Matrix2(){};

	void Identity();  //�������
	void Transpose(); //��ġ���
	void Inverse();   //�����

	Matrix2 operator+(const Matrix2 &m) const;
	Matrix2 operator-(const Matrix2 &m) const;
	Matrix2 operator*(const Matrix2 &m) const;	
	Matrix2 operator*(const float scalar) const;
	friend Matrix2 operator*(const float scalar, const Matrix2 &m);//���������ڿ����ε�

	void operator+=(const Matrix2 &m);
	void operator-=(const Matrix2 &m);
	void operator*=(const Matrix2 &m); //��Ŀ�� ������ �������
	void operator*=(const float scalar);
};
