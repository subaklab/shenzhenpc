#ifndef D_LIGHTCONTROLLER_H
#define D_LIGHTCONTROLLER_H

enum {
    LIGHT_STATE_UNKNOWN = -1,
    LIGHT_STATE_OFF = 0,
    LIGHT_STATE_ON = 1,    
};

void LightController_Create(void);
void LightController_On(int id);

#endif
