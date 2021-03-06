/*
 * Configuration:
 * - 30MHz clock
 * - 1 wait state for flash
 * - PIO0_2 is a LED outupt
 * - SysTick 10 times a second
 *
 * Operation:
 * - Toggle the state of the LED on PIO0_2 on every SysTick (heartbeat)
 *
*/

#include "LPC8xx.h"
#include "TimeService.h"
#include "LightScheduler.h"
#include "LightController.h"

extern int theMinute;
extern int theDay;

volatile long int ticks = 0;
extern "C" void SysTick_Handler(void) {
     // Toggle LED on PIO0_2
     ticks++;
     theMinute = ticks / 1000 / 60;
}

extern int lastState;

void LightHardware_Run()
{
  if (lastState == LIGHT_STATE_ON) 
     LPC_GPIO_PORT->PIN0 = 4;
}
 
int main(void) {
    // 30Mhz
    LPC_SYSCON->SYSPLLCTRL = 0x24;
    LPC_SYSCON->SYSAHBCLKDIV = 0x02;

    LPC_SYSCON->PDRUNCFG &= ~(0x80);
    while (!(LPC_SYSCON->SYSPLLSTAT & 0x01));

    LPC_SYSCON->MAINCLKSEL = 0x03;
    LPC_SYSCON->MAINCLKUEN = 0x01;
    while (!(LPC_SYSCON->MAINCLKUEN & 0x01));

    // 1 wait state for flash
    LPC_FLASHCTRL->FLASHCFG &= ~(0x03);

    // PIO0_2 is used by SWD, so disable it */
    LPC_SWM->PINENABLE0 = 0xFFFFFFBFUL;

    // PIO0_2 is an output
    LPC_GPIO_PORT->DIR0 |= 0x04;

    // SysTick 10 time a second
    //SysTick_Config(30000000/10);

    // SysTick 2 time a second
    //SysTick_Config(30000000/2);

    // SysTick 1000 time a second
    SysTick_Config(30000000/1000);
 
    LightController_Create();
    LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1);
    TimeService_SetDay(MONDAY);
    TimeService_SetMinute(0);

    while (1) 
    {
      LightScheduler_Wakeup();
      LightHardware_Run();
    }
}

