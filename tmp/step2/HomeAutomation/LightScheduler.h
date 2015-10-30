#ifndef D_LIGHTSCHEDULER_H
#define D_LIGHTSCHEDULER_H

enum Day {
    EVERYDAY,
    SUNDAY,
    MONDAY
};

typedef enum Day Day;

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
void LightScheduler_Wakeup();
void LightScheduler_Create(void);
#endif
