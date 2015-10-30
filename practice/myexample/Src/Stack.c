#include "Stack.h"

#include <stdlib.h>


typedef struct StackStruct {
	int index;
	int count;
	int values[STACK_CAPACITY];
}StackStruct;


Stack Stack_Create()
{
	Stack self;
	self = (Stack) malloc(sizeof(StackStruct));
	self->index = 0;
	self->count = 0;

	return self;
}

int Stack_Verify(Stack s)
{
	if (s != NULL){
		return 1;
	}
	return 0;
}

int Stack_Count(Stack s)
{
	if (s != NULL){
		return s->count;
	} else {
		return -1;
	}
}

int Stack_Push(Stack s, int v)
{
	if (s->count == STACK_CAPACITY){ //overflow
		return -1;
	}

	s->index = s->count;
	s->count++;
	s->values[s->index]= v;
	return 1;
}

int Stack_Pop(Stack s, int* out)
{
	if(s->count == 0)
	{
		return -1;
	}
	s->count--;
	s->index = s->count;

	*out = s->values[s->index];
	return 1;
}

void Stack_Destroy(Stack s)
{
	free(s);
}
