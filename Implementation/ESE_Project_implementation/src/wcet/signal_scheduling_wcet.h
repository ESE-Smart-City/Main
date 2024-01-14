//
// Created by sheik on 1/7/2024.
//
#ifndef WCET_SIGNAL_SCHEDULING
#define WCET_SIGNAL_SCHEDULING

#include <Arduino.h>
#include "task/signal_scheduling.h"

// return WCET in microseconds
unsigned long WCET_signal_scheduling(signal_sch* signal_scheduling_task){
    Serial.println("running WCET_signal_scheduling");
    signal_scheduling_task->run_in_loop = false;
    int iteration = 10;
    unsigned long wcet = 0;

    
    while (iteration>0){
        iteration = iteration - 1;
        unsigned long StartTime = micros();
        signal_scheduling_task->job();
        unsigned long EndTime = micros();
        if (wcet > 0 ){
            wcet = EndTime - StartTime;
        }
        else{
            wcet = max(wcet,(EndTime - StartTime));
        }
        wcet = EndTime - StartTime;

    }
    Serial.print("WCET_signal_scheduling(microseconds): ");
    Serial.println(wcet);
    Serial.print("period_signal_scheduling(milliseconds): ");
    Serial.println(signal_scheduling_task->periode);
    return wcet;
}


#endif