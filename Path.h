#ifndef PATH_H
#define PATH_H

typedef struct{
	int x, y;
}Point;

typedef struct{
	int opened;
	int visited;
}Spot;


class Path{
	private:
		Point *position;
		int top;
		int size;

	public:

	Path(int size);

	void push(Point c);

	Point pop();

	Point get(int i);

	int getSize();

};

#endif