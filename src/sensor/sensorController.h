#ifndef SENSORCONTROLLER_H_
#define SENSORCONTROLLER_H_

#pragma once

#include <Arduino.h>
#include <sensor/sensor.h>

class SensorController {
public:

    int len;
    Sensor sensors[2];

    SensorController();

    void begin(int trig, int echo, int pos);
    int loop(); // Return the pos used by the led controller
};

#endif