#ifndef D_TIMESERVICE_H
#define D_TIMESERVICE_H

typedef struct {
    int minuteOfDay;
    int dayOfWeek;    
} Time;

void TimeService_GetTime(Time* time);

#endif
