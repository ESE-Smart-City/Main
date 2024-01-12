//
// Created by sheik on 1/7/2024.
//
#ifndef SIGNAL_SCHEDULING
#define SIGNAL_SCHEDULING

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>


class signal_sch{

public: 

    unsigned long WCET = 4; //micro seconds
    unsigned long periode; //micro seconds
    unsigned long default_periode;
    int* emergency_vehicle = 0;

    int next_state = 0;
    int hold_state = 0;
    int emergency_ROW= 0;

    int ROW_1_OUTPUT = 5;
    int ROW_2_OUTPUT = 4;
    int ROW_3_OUTPUT = 3;
    int ROW_4_OUTPUT = 2; 
    int emergency_ROW_OUTPUT = 0;

    bool run_in_loop = true;

    void SETUP();
    void run();
    void job();
    void ROW1();
    void ROW2();
    void ROW3();
    void ROW4();
    void ROWEmergency();
    signal_sch(unsigned long periode, int * emergency_trigger);
};

#endif