#ifndef SENSOR_H
#define SENSOR_H

#pragma once

#include <Arduino.h>

class Sensor {
public:
    int trigger, echo, pos;
    unsigned long timeout;
    Sensor(int trigger, int echo, int pos);
    Sensor();

    void begin();

    float getDistance();
    void loop();
};

#endif