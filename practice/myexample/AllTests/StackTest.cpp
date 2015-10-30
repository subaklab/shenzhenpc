

#include <stdio.h>
#include <stdarg.h>
#include "CppUTest/TestHarness.h"

extern "C" {
    #include "Stack.h"
}


TEST_GROUP(Stack)
{ 
    Stack s;
    void setup()
    {
        //Do Something for before each test
        s = Stack_Create();
    }
    void teardown()
    {
        //Do Something for after each test
        Stack_Destroy(s);
    }
};

TEST(Stack, Create)
{
    CHECK(Stack_Verify(s));
}

TEST(Stack, Push)
{
    CHECK(Stack_Verify(s));
    
    Stack_Push(s, 2);
    CHECK_EQUAL(1, Stack_Count(s));
}

TEST(Stack, PushOverflow)
{
    for(int i =0; i<STACK_CAPACITY; i++)
    {
        Stack_Push(s, i);
    }
    CHECK_EQUAL(STACK_CAPACITY, Stack_Count(s));

    CHECK_EQUAL(-1, Stack_Push(s, 1));
}

TEST(Stack, Pop)
{
    int input, output;
    input = 5; output = 0;

    Stack_Push(s, input);
    CHECK_EQUAL(1, Stack_Pop(s, &output));
    CHECK_EQUAL(input, output);
}

TEST(Stack, PopFromEmptyStack)
{
    int output = 0;

    CHECK_EQUAL(-1, Stack_Pop(s, &output));
}
