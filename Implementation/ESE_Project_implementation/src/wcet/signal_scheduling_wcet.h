//
// Created by sheik on 1/7/2024.
//
#ifndef WCET_SIGNAL_SCHEDULING
#define WCET_SIGNAL_SCHEDULING

#include <Arduino.h>
#include "task/signal_scheduling.h"

void WCET_signal_scheduling(signal_sch* signal_scheduling_task){
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
            wcet = (wcet+(EndTime - StartTime))/2;
        }
        wcet = EndTime - StartTime;

    }
    Serial.print(wcet);
}


#endif