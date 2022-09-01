#ifndef __CLOUD__
#define __CLOUD__

class Cloud: public Object {
	private:
		short int sentido = 1;
	public:
		Cloud(float X, float Y, float Z);
		virtual void draw();
		virtual void action();
};


#endif
