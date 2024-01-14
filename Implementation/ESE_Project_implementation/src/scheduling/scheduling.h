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
#include "wcet/emergency_listener_wcet.h"


// shared variable
static int emergency_triger = 0;
static int current_signal_state=0;
unsigned long signal_state_duration = 5000; //mili seconds
bool allow_extention = false;

// scheduling -> scheduler 
void StartScheduler();

// scheduling -> task period
unsigned long period_signal = 8; //mili seconds
unsigned long period_bus = 10; //mili seconds
unsigned long period_emergency = 8; //mili seconds

// scheduling -> task WCET 
unsigned long t_WCET_signal_scheduling = 2;
unsigned long t_WCET_bus_listener = 3;
unsigned long t_WCET_emergency_listener = 2;

// scheduling -> task handler
TaskHandle_t xTask1Handle, xTask2Handle, xTask3Handle, xTask4Handle, xTask5Handle;

// scheduling -> task
void signal_scheduling(void *parameter);
void bus_listener(void *parameter);
void emergency_listener(void *parameter);
signal_sch signal_scheduling_task = signal_sch(period_signal,&signal_state_duration, &current_signal_state, &emergency_triger, &allow_extention);
emergency_l emergency_listener_task = emergency_l(period_emergency ,&emergency_triger);
bus_l bus_listener_task = bus_l(period_bus, &current_signal_state, &signal_state_duration, &allow_extention);

//scedubility test
const int num_task =3;
unsigned long wcet[num_task];
int period[num_task];

void scedubility_test_setup(){
    for(int task =0 ; task <num_task; task++){
        wcet[task] = 0; 
        period[task] = 0; 
    }
    wcet[0] = WCET_signal_scheduling(&signal_scheduling_task); //micro
    wcet[1] = WCET_bus_listener(&bus_listener_task); //micro
    wcet[2] = WCET_emergency_listener(&emergency_listener_task); //micro

    period[0] = period_signal*1000; //micro
    period[1] = period_bus*1000; //micro
    period[2] = period_emergency*1000; //micro

}

bool scedubility(){
    scedubility_test_setup();
    double u = 0;
    double u_total = 0;
    for(int task =0 ; task <3; task++){
        
        Serial.println(wcet[task]);
        Serial.println(period[task]);
        u = (double(wcet[task])/double((period[task])));
        
        u_total += (double)u;
        Serial.print("u_");
        Serial.print(task);
        Serial.print(" = ");
        Serial.println(u);
    }
    Serial.print("u_total = ");
    Serial.println(u_total);
    return (u_total<1)?true:false;
}

