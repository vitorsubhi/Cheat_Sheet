#ifndef __GRASS__
#define __GRASS__

class Grass: public Object {
	private:
		GLfloat width = 10.0, length = 30.0;

	public:
		Grass(float X, float Y, float Z);
		virtual void draw();

		void setWidth(float w);
		void setLength(float l);
};


#endif
