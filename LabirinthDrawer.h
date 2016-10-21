#ifndef LABIRINTH_DRAWER_H
#define LABIRINTH_DRAWER_H

#include "Labirinth.h"

class LabirinthDrawer{

	private:
		int texture;
		Labirinth *labirinth;
		void drawCubeAt(int i, int j);
		void drawFloorCeilAt(int i, int j, int fc);

	public:
		LabirinthDrawer(int texture, Labirinth *labirinth);
		void draw();//int **wallMatrix, int alt, int larg);
};

#endif