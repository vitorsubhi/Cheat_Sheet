#ifndef __CAR__
#define __CAR__

class Car: public Object {
	public:
		bool direction = true;
		Car(float X, float Y, float Z);
		virtual void draw();
		virtual void action();
};


#endif
