#ifndef __ledController_h__
#define __ledController_h__

#include <leds/leds.h>
#include <Arduino.h>
#include <time.h>

/*

    State:      0 -> off     |       1 -> on
    timeout:    45s timer to auto turn off the leds

*/


class ledController {
public:
    Leds leds[7];
    int len;
    int lastPos;

    int state;
    time_t timeout;
    
    ledController();

    void insertLed(int pin);
    void turnOn(int pos);
    void turnOff();

    void loop();
    void update();
};

#endif