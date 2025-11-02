#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#define NUM_LEDS 7

#include <leds/leds.h>
#include <Arduino.h>

/*

    State:      0 -> off     |       1 -> on
    timeout:    45s timer to auto turn off the leds

*/


class ledController {
public:
    Leds leds[NUM_LEDS];
    int len;
    int lastPos;

    int state;
    unsigned long timeoutStart;
    
    ledController();

    void insertLed(int pin);
    void turnOn(int pos);
    void turnOff();

    void loop();
    void update();
};

#endif