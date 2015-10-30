#include "FakeTimeService.h"

extern int theMinute;
extern int theDay;

// void FakeTimeService_SetDay(Day day)
// {
// }

// void FakeTimeService_SetMinute(int minute)
// {
// }

void FakeTimeService_SetMinute(int minute)
{
    theMinute = minute;
}

void FakeTimeService_SetDay(int day)
{
    theDay = day;
}
