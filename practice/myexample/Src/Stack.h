#ifndef STACK_H_
#define STACK_H_

#define STACK_CAPACITY 10

typedef struct StackStruct* Stack;

extern Stack Stack_Create(void);
extern int Stack_Verify(Stack);
extern void Stack_Destroy(Stack);
extern int Stack_Count(Stack);
extern int Stack_Push(Stack, int);
extern int Stack_Pop(Stack s, int* out);

#endif
