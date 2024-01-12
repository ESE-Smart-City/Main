//
// Created by sheik on 1/7/2024.
//
#ifndef SIGNAL_SCHEDULING
#define SIGNAL_SCHEDULING

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>


class signal_sch{

public: 

    unsigned long WCET = 1696; //micro seconds
    unsigned long periode; //micro seconds
    int* emergency_vehicle = 0;
    int* current_state;

    // signal duration in millis
    unsigned long state_default_duration = 60000;
    unsigned long* state_duration;
    unsigned long current_state_clock = 0;
    unsigned long start_state_clock = 0;
    //unsigned long hold_state_clock;
    unsigned long start_emergency_state_clock = 0;
    unsigned long hold_start_state_clock;
    unsigned long hold_duration_state_clock;

    bool change_state = true;
    bool emergency_state = false;
    bool state_clock_hold = false;

    // if false, the emergency will be next insted of change it immediately(lab)
    bool change_immediate_emergency_state = true;

    // emergency
    bool emergency_mode = true;

    int next_state = 1;
    int hold_state = 0;
    int emergency_ROW= 0;

    int ROW_1_OUTPUT = 20;
    int ROW_2_OUTPUT = 19;
    int ROW_3_OUTPUT = 18;
    int ROW_4_OUTPUT = 17; 
    int emergency_ROW_OUTPUT = 0; // variable

    bool run_in_loop = true;

    void SETUP();
    void run();
    void job();
    void ROW1();
    void ROW2();
    void ROW3();
    void ROW4();
    void ROWEmergency();
    signal_sch(unsigned long periode, unsigned long* new_state_duration,int * current_state_, int* emergency_trigger);

};

#endif