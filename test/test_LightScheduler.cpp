#include "CppUTest/TestHarness.h"
#include "LightScheduler.h"

#include "FakeTimeService.h"
#include "LightControllerSpy.h"

TEST_GROUP(LightScheduler)
{
   void setup()
   {
   }

   void teardown()
   {
   }
};

TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
    LightController_Create();
    LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(1199);
    LightScheduler_Wakeup();

    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

TEST(LightScheduler, ScheduleOnEverydayItsTime)
{
    LightController_Create();
    LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
    FakeTimeService_SetDay(MONDAY);
    FakeTimeService_SetMinute(1200);
    LightScheduler_Wakeup();

    LONGS_EQUAL(LIGHT_STATE_ON, LightControllerSpy_GetLastState());
}
