#ifndef LABIRINTH_DRAWER_H
#define LABIRINTH_DRAWER_H

#include "Labirinth.h"

class LabirinthDrawer{

	private:
		int textureCube, textureFc;
		Labirinth *labirinth;
		void drawCubeAt(int i, int j);
		void drawFloorCeilAt(int i, int j, int fc);

	public:
		LabirinthDrawer(int textureCube, int textureFc, Labirinth *labirinth);
		void draw();//int **wallMatrix, int alt, int larg);
};

#endif