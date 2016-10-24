#ifndef LABIRINTH_DRAWER_H
#define LABIRINTH_DRAWER_H

#include "Labirinth.h"

class LabirinthDrawer{

	private:
		int textureCube, textureFc;
		float mx, my, mspeed;
		Labirinth *labirinth;
		void drawCubeAt(int i, int j);
		void drawFloorCeilAt(int i, int j, int fc);

	public:
		LabirinthDrawer(int textureCube, int textureFc, Labirinth *labirinth);
		void draw();//int **wallMatrix, int alt, int larg);
		void getIndexPosition(int i, int j, float *vec);
		bool collidesWith(float *vec);
		void getPositionIndex(int *i, int *j, float *vec);
		void drawMinimap(float *pos);
		void inc(float mx, float my, float mspeed);
};

#endif