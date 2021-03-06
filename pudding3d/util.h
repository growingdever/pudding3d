
#ifndef UTIL_H
#define UTIL_H

#include <Windows.h>
#include <string.h>
#include <math.h>

#include "vector.h"
#include "Vertex.h"

#ifndef PI
#define PI 3.1415926535897932384626f
#endif

#define DEG2RAD(x)  ((x) * PI / 180.0f)
#define RAD2DEG(x)  ((x) * 180.0f / PI)

#define FILE_LENGTH_MAX 256

typedef struct tagSPDPoint
{
	float x;
	float y;
}pdPoint;

inline int ftoi(float f)
{
	int i;

#ifdef _MSC_VER
	_asm fld	f
	_asm fistp	i
#else
	asm ("fld %0" : : "m" (f));
	asm ("fistpl %0" : :"m" (i));
#endif

	return i;
}

template < class T >
inline void Swap( T& a, T& b )
{
	T tmp(a);
	a = b;
	b = tmp;
}

inline float Get2d_X( Vertex a, Vertex b, float y )
{
	float x1 = a.pos.x;
	float y1 = a.pos.y;
	float x2 = b.pos.x;
	float y2 = b.pos.y;
	float slope = ( y1 - y2 ) / ( x1 - x2 );

	return ( ( y - y1 ) / slope + x1 );
}

inline float Get2d_Y( Vertex a, Vertex b, float x )
{
	float x1 = a.pos.x;
	float y1 = a.pos.y;
	float x2 = b.pos.x;
	float y2 = b.pos.y;
	float slope = ( y1 - y2 ) / ( x1 - x2 );

	return ( slope * ( x - x1 ) + y1 );
}

inline float dot(Vector3 a, Vector3 b)
{
	float result;

	result = a.x*b.x + a.y*b.y + a.z*b.z;

	return result;
}

inline float dot(Vector4 a, Vector4 b)
{
	float result;

	result = a.x*b.x + a.y*b.y + a.z*b.z;

	return result;
}

inline Vector3 cross(Vector3 a, Vector3 b)
{
	Vector3 result;

	result.x = a.y*b.z - a.z*b.y;
	result.y = a.z*b.x - a.x*b.z;
	result.z = a.x*b.y - a.y*b.x;

	return result;
}
inline Vector4 cross(Vector4 a, Vector4 b)
{
	Vector4 result;

	result.x = a.y*b.z - a.z*b.y;
	result.y = a.z*b.x - a.x*b.z;
	result.z = a.x*b.y - a.y*b.x;

	return result;
}

inline double getAngleWithVector( Vector4 a, Vector4 b )
{
	double dp = dot( a, b );

	return acos(dp / a.Length() / b.Length() );
}

inline char* makeAbsolutePath( char* path )
{
	char currDir[FILE_LENGTH_MAX];
	GetCurrentDirectory( FILE_LENGTH_MAX, currDir );

	strcat_s( currDir, FILE_LENGTH_MAX, "\\" );
	strcat_s( currDir, FILE_LENGTH_MAX, path );

	return currDir;
}

#endif