#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main(){
	Stack* stack = new_Stack();
	Stack_Push(stack, 1);
	free_Stack(stack);
	return 0;
}
