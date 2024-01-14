//
// Created by sheik on 1/7/2024.
//

#include "scheduling/scheduling.h"

// use case
bool WCET = false;
bool simulate = true;
bool test = false;

// basic setup and main thread
void setup(){
    Serial.begin(115200);
    signal_scheduling_task.SETUP();
    bus_listener_task.SETUP();
    emergency_listener_task.SETUP();
    if (WCET){
        // compute WCET for each job from each task
        Serial.println("Scedubility test ");
        if(scedubility()){
            Serial.println("feasible");
        }
        else{
            Serial.println("not feasible");
        }
    }
    if (simulate){
        StartScheduler();
    }
    if (test){
        // use platform io unit test env
    }
    
    delay(1);
}

// loop thread
void loop(){
    delay(1);
}

// threads
void StartScheduler(){

    xTaskCreate(
        signal_scheduling,
        "Task1",
        2048,
        NULL,
        1,
        &xTask1Handle);

    xTaskCreate(
        bus_listener,
        "Task2",
        2048,
        NULL,
        2,
        &xTask2Handle);

    xTaskCreate(
        emergency_listener,
        "Task3",
        2048,
        NULL,
        3,
        &xTask3Handle);

    vTaskStartScheduler();
}

void signal_scheduling(void *parameter){
    signal_scheduling_task.run();
}

void bus_listener(void *parameter){
  bus_listener_task.run();
}

void emergency_listener(void *parameter){
    emergency_listener_task.run();
}
