#include "TimeService.h"

int theMinute;
int theDay;

void TimeService_GetTime(Time * time)
{
    time->minuteOfDay = theMinute;
    time->dayOfWeek = theDay;
}

void TimeService_SetDay(int day)
{
}

void TimeService_SetMinute(int minute)
{
}
