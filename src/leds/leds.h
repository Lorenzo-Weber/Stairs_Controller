#ifndef __LEDS_H__
#define __LEDS_H__

class Leds {
public:
    int output;
    int brightness;

    Leds();
    Leds(int pin);

    void begin();

    void setBrightness(int b);
    void loop();
};


#endif