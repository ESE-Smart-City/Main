//
// Created by sheik on 1/7/2024.
//
//
// Created by sheik on 1/7/2024.
//
#ifndef WCET_BUS_LISTENER
#define WCET_BUS_LISTENER

#include <Arduino.h>
#include "task/bus_listener.h"


void WCET_bus_listener(bus_l* bus_listener_task){
    Serial.println("running WCET_bus_listener");
    bus_listener_task->run_in_loop = false;
    int iteration = 10;
    unsigned long wcet = 0;

    
    while (iteration>0){
        iteration = iteration - 1;
        unsigned long StartTime = micros();
        bus_listener_task->job();
        unsigned long EndTime = micros();
        if (wcet > 0 ){
            wcet = EndTime - StartTime;
        }
        else{
            wcet = (wcet+(EndTime - StartTime))/2;
        }
        wcet = EndTime - StartTime;

    }
    Serial.print(wcet);
}


#endif