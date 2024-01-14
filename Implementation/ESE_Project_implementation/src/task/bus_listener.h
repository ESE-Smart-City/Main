//
// Created by sheik on 1/7/2024.
//
#ifndef BUS_LISTENER
#define BUS_LISTENER


class bus_l{

public: 

    unsigned long WCET = 2267;
    unsigned long periode;

    int bus_ROW_store = 0;

    int run_in_loop = true;

    unsigned long extend_time = 10;

    int* current_signal_state;
    unsigned long* signal_periode;

    bool* allow_extention;

    void SETUP();
    void run();
    void job();
    bus_l(unsigned long periode, int* current_signal_state, unsigned long* signal_periode, bool* allow_extention_);
    void extendTrafficLightTime();
};

#endif