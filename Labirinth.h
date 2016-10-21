#ifndef LABIRINTH_H
#define LABIRINTH_H

#include "Path.h"

class Labirinth{
private:
	int larg, alt;
	Spot **spots;

	void initRandomMatrix();

	bool isSolveable();

public:
	Labirinth(int larg, int alt);
	void generate();
	void print();
	int getBlockAt(int i, int j);
};

#endif