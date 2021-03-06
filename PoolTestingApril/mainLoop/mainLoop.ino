#include "common.h"

dataStruct data;

void setup() {
    Serial.begin(57600);
    rpm_sensor_setup();
    datalogger_init();
    //accel_init();
}

void loop() {
    data.rpm = rpm_calculate(); 
    data.velocity = get_velocity();
    data.depth = depth_function();
    getGyroPos(&(data.accelPos));
    logData(&data);
    delay(1000);
}
