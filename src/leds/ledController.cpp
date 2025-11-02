#include <Arduino.h>
#include <leds/ledController.h>

ledController::ledController() {
    len = 0;
    timeoutStart = 0;
    state = 0;
    lastPos = 0;
}

void ledController::turnOn(int pos) {

    timeoutStart = millis(); 
    state = 1; 
    lastPos = pos;

    if (pos) {
        for (int i = len; i >= 0; i--) {
            for (int j = 0; j <= 255; j+=25){
                leds[i].setBrightness(j);
            }
            delay(20);
        }
    }

    else {
        for (int i = 0; i <= len; i++) {
            for (int j = 0; j <= 255; j+=25){
                leds[i].setBrightness(j);
            }
            delay(20);
        }
    }
}

void ledController::turnOff() {

    timeoutStart = 0; 
    state = 0;

    if (!lastPos) {
        for (int i = len; i >= 0; i--) {
            for (int j = 255; j >= 0; j-=25){
                leds[i].setBrightness(j);
            }
            delay(20);
        }
    }

    else {
        for (int i = 0; i <= len; i++) {
            for (int j = 255; j >= 0 ; j-=25){
                leds[i].setBrightness(j);
            }
            delay(20);
        }
    }
}

void ledController::loop() {
    for (int i = 0; i < len; i++) {
        leds[i].loop();
    }
}

void ledController::update() {

    if (state == 1 && timeoutStart != 0) { 
        
        if(millis() - timeoutStart > 45000) { 
            turnOff();
        }
    }
}

void ledController::insertLed(int pin) {

    if(len < NUM_LEDS) {

        Leds newLed = Leds(pin);
    
        leds[len] = newLed;
        leds[len].begin();
        len+=1;
    }
}