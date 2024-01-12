#include  "io.h"
#include <ctime>
//get the system time (unix)
#include <iostream>
using namespace std;

void pin_out(int pin, int value){
}

bool pin_in(int pin){
    return false;
}

void setPIN(int pin, int type){

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