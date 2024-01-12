//
// Created by sheik on 1/7/2024.
//
#ifndef EMERGENCY_L
#define EMERGENCY_L

class emergency_l{

public: 

    unsigned long WCET = 10;
    unsigned long periode = 10;

    int emergency_ROW_1 = 6;
    int emergency_ROW_2 = 7;
    int emergency_ROW_3 = 8;
    int emergency_ROW_4 = 9;

    int* emergency_vehicle;

    void SETUP();
    void run();
    void job();
    emergency_l(unsigned long periode, int* emergency_trigger);
};

#endif