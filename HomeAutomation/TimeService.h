#ifndef D_TIMESERVICE_H
#define D_TIMESERVICE_H

typedef struct {
    int minuteOfDay;
    int dayOfWeek;    
} Time;

void TimeService_GetTime(Time* time);


void TimeService_SetDay(int day);
void TimeService_SetMinute(int minute);

#endif
