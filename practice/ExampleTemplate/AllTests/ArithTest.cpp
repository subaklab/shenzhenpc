

#include <stdio.h>
#include <stdarg.h>
#include "CppUTest/TestHarness.h"

extern "C" {
    #include "Arith.h"
}

//static SimpleString* buffer;

TEST_GROUP(Arith)
{ 
    void setup()
    {
        //Do Something for before test
    }
    void teardown()
    {
        //Do Something for after test
        
    }
};

TEST(Arith, SampleTest)
{
    CHECK(true);
}
