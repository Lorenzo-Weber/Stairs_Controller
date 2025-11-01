#ifndef __sensor_H__
#define __sensor_h__

#pragma once

#include <Arduino.h>

class Sensor {
public:
    int trigger, echo, pos;
    unsigned long timeout;
    Sensor(int trigger, int echo, int pos);

    void begin();

    float getDistance();
    void loop();
};

#endif