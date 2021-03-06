
#ifndef _TRIANGLE_RASTERIZER_H_
#define _TRIANGLE_RASTERIZER_H_

#include "Triangle.h"
#include "Vertex.h"
#include "Color.h"

class FrameBuffer;
class TriangleRasterizer 
{
	//
	// Method
	//
public:
	TriangleRasterizer();
	virtual ~TriangleRasterizer();
	virtual void drawTriangle( FrameBuffer* buffer, const Triangle& t ) = 0;

protected:
	// TODO : make function
	virtual void sortVertextCCW( Vertex v0, Vertex v1, Vertex v2 );

private:
	

	
	//
	// Variable
	//
protected:


};

#endif