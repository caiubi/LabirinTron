#ifndef CHARACTER_H
#define CHARACTER_H

class Character{
	private:
		float frame;
		int texture;
	public:
		Character(int texture);
		void draw();
		void updateFrame(float deltaT);
};

#endif