/*
 * Configuration:
 * - 30MHz clock
 * - 1 wait state for flash
 * - PIO0_2 is a LED outupt
 * - SysTick 2 times a second
 *
*/

#include "LPC8xx.h"

extern "C" void SysTick_Handler(void) {
     // Toggle LED on PIO0_2
     LPC_GPIO_PORT->NOT0 = 4;
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
    SysTick_Config(30000000/2);
 
    while (1);
}

