#ifndef SHAPE_DRAWER_H
#define SHAPE_DRAWER_H

class ShapeDrawer{
public:
	static void square(int texture);
	static void cube(int texture);
	static void circle(float cx, float cy, float r, int num_segments);
};

#endif