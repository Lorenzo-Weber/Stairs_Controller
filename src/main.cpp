#pragma once

#include <leds/ledController.h>
#include <sensor/sensorController.h>
#include <Arduino.h>

SensorController sensors;
ledController leds;

int lastPos = -1;

void setup() {
  leds.insertLed(2);
  leds.insertLed(3);
  leds.insertLed(4);
  leds.insertLed(5);
  leds.insertLed(6);
  leds.insertLed(7);
  leds.insertLed(8);  

  sensors.begin(9, 10, 0);
  sensors.begin(11, 12, 1);
}

void loop() {
  leds.loop();
  leds.update();

  int pos = -1;
  pos = sensors.loop();

  if (pos != -1) {
    if(leds.state == 0) {
      leds.turnOn(pos);
    }
    else {
      if(pos != lastPos) {
        if(leds.state) {
          leds.turnOff();
        }
      }
    }
  }
  lastPos = pos;
}
