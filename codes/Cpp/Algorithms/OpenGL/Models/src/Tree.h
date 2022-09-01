#ifndef __TREE__
#define __TREE__

class Tree: public Object {
	private:
		unsigned int model = 1;

	public:
		Tree(float X, float Y, float Z);
		virtual void draw();

		void setModel(unsigned int md);
		unsigned int getModel();
};


#endif
