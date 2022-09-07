#ifndef __INT32_H__
	#define __INT32_H__

	class Int32: public Node {
		private:
			int number;
		public:
			Int32(int n): number(n) {}
			int getNumber() const { return number; }
			virtual Value *generate(Function *func, BasicBlock *block, BasicBlock *allocblock) override;
			virtual void accept(Visitor &v) override;
	};
#endif