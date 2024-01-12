//
// Created by sheik on 1/7/2024.
//

#include <Arduino.h>

#include <Arduino_FreeRTOS.h>
#include "task/bus_listener.h"
#include "task/emergency_listener.h"
#include "task/signal_scheduling.h"
#include "wcet/bus_listener_wcet.h"
#include "wcet/signal_scheduling_wcet.h"

void signal_scheduling(void *parameter);
void bus_listener(void *parameter);
void emergency_listener(void *parameter);
void StartScheduler();
static int emergency_triger = 0;
int current_signal_state=0;
int add =0;


TaskHandle_t xTask1Handle, xTask2Handle, xTask3Handle, xTask4Handle, xTask5Handle;



unsigned long periode_signal = 20; //mili seconds
unsigned long periode_bus = 4; //mili seconds
unsigned long periode_emergency = 20; //mili seconds


unsigned long signal_state_duration = 5000; //mili seconds

signal_sch signal_scheduling_task = signal_sch(periode_signal,&signal_state_duration, &current_signal_state, &emergency_triger);
emergency_l emergency_listener_task = emergency_l(periode_emergency ,&emergency_triger);
bus_l bus_listener_task = bus_l(periode_bus, &current_signal_state, &signal_state_duration);


// basic setup and main thread
void setup(){
    Serial.begin(115200);
    signal_scheduling_task.SETUP();
    bus_listener_task.SETUP();
    emergency_listener_task.SETUP();
    //WCET_signal_scheduling(&signal_scheduling_task);
    //WCET_bus_listener(&bus_listener_task);
    StartScheduler();
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