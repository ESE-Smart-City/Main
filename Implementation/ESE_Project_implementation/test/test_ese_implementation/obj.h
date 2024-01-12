
#include "../src/task/bus_listener.h"
#include "../src/task/emergency_listener.h"
#include "../src/task/signal_scheduling.h"
#include "../src/task/bus_listener.cpp"
#include "../src/task/emergency_listener.cpp"
#include "../src/task/signal_scheduling.cpp"

// shared variable
static int emergency_triger = 0;
static int current_signal_state=0;
unsigned long signal_state_duration = 5000; //mili seconds


// scheduling -> task period
unsigned long period_signal = 20; //mili seconds
unsigned long period_bus = 4; //mili seconds
unsigned long period_emergency = 20; //mili seconds

// scheduling -> task
signal_sch signal_scheduling_task = signal_sch(period_signal,&signal_state_duration, &current_signal_state, &emergency_triger);
emergency_l emergency_listener_task = emergency_l(period_emergency ,&emergency_triger);
bus_l bus_listener_task = bus_l(period_bus, &current_signal_state, &signal_state_duration);
