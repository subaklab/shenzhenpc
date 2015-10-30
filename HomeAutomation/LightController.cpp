#include "LightController.h"

int lastState; // For Test Spy

void LightController_Create(void)
{
    lastState = LIGHT_STATE_UNKNOWN;    
}

void LightController_On(int id)
{
    lastState = LIGHT_STATE_ON;
    // Hardware ON
    
}



