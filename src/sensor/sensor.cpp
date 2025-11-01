#include <sensor/sensor.h>

Sensor::Sensor(int t, int e, int p) {
    trigger = t;
    echo = e;
    pos = p;
    timeout = 30000;
}

void Sensor::begin() {
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
}

float Sensor::getDistance() {
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    unsigned long duration = pulseIn(echo, HIGH, timeout);
    if (duration == 0) return -1;

    float distance = (duration / 2.0) * 0.0343;
    return distance;
}

