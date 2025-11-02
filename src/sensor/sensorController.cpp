#include <sensor/sensorController.h>

#define TRESHOLD 5
#define ACTIVATE0 200
#define ACTIVATE1 50

SensorController::SensorController() {
    len = 0;
}

void SensorController::begin(int trig, int echo, int pos) {
    Sensor newSensor = Sensor(trig, echo, pos);

    sensors[len] = newSensor;
    sensors[len].begin();
    len++;
}

int SensorController::loop() {
    
    float dist0 = 0;
    float dist1 = 0;

    int pos = -1;
    
    for (int i = 0; i < TRESHOLD; i++) {
        dist0 += sensors[0].getDistance();
        delay(100);
        dist1 += sensors[1].getDistance(); 
    }

    dist0 /= TRESHOLD;
    dist1 /= TRESHOLD;

    if (dist0 < ACTIVATE0) pos = 0;
    else if (dist1 < ACTIVATE1) pos = 1;

    return pos;
}