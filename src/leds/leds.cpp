#pragma once

#include <Arduino.h>
#include <leds/leds.h>


Leds::Leds(){}

Leds::Leds(int pin) {
    output = pin;
    brightness = 0;
    
    pinMode(output, OUTPUT);
}

void Leds::setBrightness(int b) {
    brightness = b;
}

void Leds::loop() {
    analogWrite(output, brightness);
}

void Leds::begin() {
    pinMode(output, OUTPUT);
}