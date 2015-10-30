#include "LightControllerSpy.h"

extern int lastState;

int LightControllerSpy_GetLastState()
{
    return lastState;    
}
