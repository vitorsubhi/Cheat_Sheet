#ifndef __SUN__
#define __SUN__

class Sun: public Object {
	public:
		Sun(float X, float Y, float Z);
		virtual void draw();
		virtual void action();
};


#endif
