

#include <stdio.h>
#include <stdarg.h>
#include "CppUTest/TestHarness.h"

extern "C" {
    #include "Arith.h"
}

//static SimpleString* buffer;

TEST_GROUP(Arith)
{ 
    int a, b;

    void setup()
    {
        a = 0; b = 0;
        //Do Something for before test
    }
    void teardown()
    {
        //Do Something for after test
        
    }
};

TEST(Arith, TestMultiplyTwoPositives)
{
    a = 2, b = 4;
    CHECK_EQUAL(8, Multiply(a, b));
}

TEST(Arith, TestMultiplyPositiveAndNegative)
{
    a = 3, b = -2;
    CHECK_EQUAL(-6, Multiply(a, b));
}

TEST(Arith, TestMultiplyZeroAndPositive)
{
    a = 0; b = 3;
    CHECK_EQUAL(0, Multiply(a, b));
}

