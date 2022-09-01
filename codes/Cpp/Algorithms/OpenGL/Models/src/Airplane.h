#ifndef __AIRPLANE__
#define __AIRPLANE__

class Airplane: public Object {
	public:
		Airplane(float X, float Y, float Z);
		virtual void draw();
		virtual void action();
};


#endif
