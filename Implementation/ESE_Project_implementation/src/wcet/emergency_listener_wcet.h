//
// Created by sheik on 1/7/2024.
//

#include <Arduino.h>
#include "task/emergency_listener.h"

// return WCET in microseconds
unsigned long WCET_emergency_listener(emergency_l* emergency_listener_task){
    Serial.println("running WCET_bus_listener");
    int iteration = 10;
    unsigned long wcet = 0;
    
    while (iteration>0){
        iteration = iteration - 1;
        unsigned long StartTime = micros();
        emergency_listener_task->job();
        unsigned long EndTime = micros();
        if (wcet > 0 ){
            wcet = EndTime - StartTime;
        }
        else{
            wcet = max(wcet,(EndTime - StartTime));
        }
        wcet = EndTime - StartTime;

    }
    Serial.print("WCET_emergency_listener(microseconds): ");
    Serial.println(wcet);
    Serial.print("period_emergency_listener_task(milliseconds): ");
    Serial.println(emergency_listener_task->periode);
    return wcet;
}