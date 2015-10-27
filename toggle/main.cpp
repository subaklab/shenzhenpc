typedef unsigned int volatile * vp;
int main() {
   /* PIO0_2 is used by SWD, so disable it */
   *(vp) 0x4000C1C0 = 0xFFFFFFBFUL; /* PINENABLE0 register */
 /* Set GPIO Direction */
   *(vp) 0xA0002000 |= 1 << 2;  /* DIR0, set PIO0_2 to output */
 for(;;) {
    /* Toggle the LED */
     *(vp) 0xA0002300 |= 1 << 2;  /* NOT0 register */
     volatile long wait = 120000;
     //volatile long wait = 480000;
     while (wait > 0) --wait;   /* WAIT */
   }
 }

/*
// Toggle I/O pins as fast as possible for doing timing measurements.
// See http://jeelabs.org/2014/11/26/getting-started-final-episode/

#include "LPC8xx.h"

#define SYSPLLCTRL_Val      0x24
#define SYSPLLCLKSEL_Val    0
#define MAINCLKSEL_Val      3
#define SYSAHBCLKDIV_Val    2

static void setMaxSpeed () {
    LPC_SYSCON->SYSPLLCLKSEL = SYSPLLCLKSEL_Val;    // select PLL input
    LPC_SYSCON->SYSPLLCLKUEN = 0x01;                // update clock source
    while (!(LPC_SYSCON->SYSPLLCLKUEN & 0x1)) ;     // wait until updated

    LPC_SYSCON->SYSPLLCTRL = SYSPLLCTRL_Val;        // main clock is PLL out
    LPC_SYSCON->PDRUNCFG &= ~(1<<7);                // power-up SYSPLL
    while (!(LPC_SYSCON->SYSPLLSTAT & 0x1)) ;       // wait until PLL locked

    LPC_SYSCON->MAINCLKSEL = MAINCLKSEL_Val;        // select PLL clock output
    LPC_SYSCON->MAINCLKUEN = 0x01;                  // update MCLK clock source
    while (!(LPC_SYSCON->MAINCLKUEN & 0x1)) ;       // wait until updated

    LPC_SYSCON->SYSAHBCLKDIV = SYSAHBCLKDIV_Val;
}

int main () {
    // comment out next two lines for default 12 MHz power-up clock iso 30 MHz
    setMaxSpeed();                          // set maximum clock speed
    LPC_SYSCON->IRQLATENCY = 0;             // minimal interrupt delay

    // uncomment this for maximum speed, but it's out of spec above 20 Mhz
    //LPC_FLASHCTRL->FLASHCFG = 0;          // 1 flash clock instead of 2

    LPC_SWM->PINENABLE0 |= (1<<2) | (1<<3); // disable SWCLK and SWDIO
    LPC_GPIO_PORT->DIR0 |= (1<<2) | (1<<3); // set PIO0_2 & PIO0_3 as outputs

    SysTick_Config(30000000/50000);         // 50 KHz interrupt rate
    volatile int count =0;

    while (true) {
        LPC_GPIO_PORT->NOT0 = 1<<2;         // toggle GPIO 2 max speed (pin 4)
        //while(count < 1000000) {
        while(count < 5000000) {
          count++;
        }
        count = 0;
    }
}

extern "C" void SysTick_Handler () {
    LPC_GPIO_PORT->B0[3] = 1;               // set GPIO 3 high (pin 3)
    LPC_GPIO_PORT->B0[3] = 0;               // set GPIO 3 low again
    LPC_GPIO_PORT->B0[3] = 1;               // set GPIO 3 high again
    LPC_GPIO_PORT->B0[3] = 0;               // set GPIO 3 low again
}
*/
