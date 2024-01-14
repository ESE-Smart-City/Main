#include  "../src/io.h"
#include <ctime>
//get the system time (unix)
#include <iostream>
using namespace std;

// pin
int ROW_1_OUTPUT = 20;
int ROW_2_OUTPUT = 19;
int ROW_3_OUTPUT = 18;
int ROW_4_OUTPUT = 17;  
    
int bus_ROW_1 = 13;
int bus_ROW_2 = 12;
int bus_ROW_3 = 11;
int bus_ROW_4 = 10;

int emergency_BUTTON_ROW_1 = 6;
int emergency_BUTTON_ROW_2 = 7;
int emergency_BUTTON_ROW_3 = 8;
int emergency_BUTTON_ROW_4 = 9;

// pin setting abstarction
int pin_value[40];
int pin_mode[40];


void pin_out(int pin, int value){
    pin_value[pin] = value;
}

bool pin_in(int pin){
    return pin_value[pin];
}

void setPIN(int pin, int type){
    pin_mode[pin] = type;
}

void print_string(const char *__fmt, ...){
}

void println_string(const char *__fmt, ...){
}

void print_value(int input){
}

void println_value(int input){
}

unsigned long time_millis(){
    long double sysTime = time(0);
    long double sysTimeMS = sysTime*1000;
    return sysTimeMS;
}

 void vTaskDelay_(int period){
 }
 
void delay_(int value){
}