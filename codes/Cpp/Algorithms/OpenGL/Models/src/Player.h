#ifndef __PLAYER__
#define __PLAYER__

class Player: public Object {
	public:
		Player(float X, float Y, float Z);
		virtual void draw();
};


#endif
