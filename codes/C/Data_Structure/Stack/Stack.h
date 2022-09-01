#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100
#define TRUE 1
#define FALSE 0

#define OK 0
#define STRUCTURE_NOT_INITIALIZED -1
#define EMPTY_STRUCTURE -2
#define FULL_STRUCTURE -3
#define INVALID_PARAMETER -4

typedef struct {
	int items[MAX_SIZE];
	int top;
} Stack;

Stack* new_Stack();
int free_Stack(Stack* stack);
int isEmpty_Stack(Stack* stack);
int isFull_Stack(Stack* stack);
int Stack_Push(Stack* stack, int item);
int Stack_Pop(Stack* stack, int* item);
int getTop_Stack(Stack* stack, int* item);

#endif
