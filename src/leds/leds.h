#ifndef LEDS_H
#define LEDS_H

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