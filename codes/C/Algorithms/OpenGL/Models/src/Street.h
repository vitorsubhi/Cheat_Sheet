#ifndef __STREET__
#define __STREET__

class Street: public Object {
	private:
		GLfloat width = 10.0, length = 30.0;

	public:
		Street(float X, float Y, float Z);
		virtual void draw();

		void setWidth(float w);
		void setLength(float l);
};


#endif
