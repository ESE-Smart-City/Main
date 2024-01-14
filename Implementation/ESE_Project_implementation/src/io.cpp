#include  "io.h"

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

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



void pin_out(int pin, int value){
    digitalWrite(pin,value);

}

bool pin_in(int pin){
    return digitalRead(pin);

}

void setPIN(int pin, int type){
    pinMode(pin, type);

}

void print_string(const char *__fmt, ...){
    Serial.print(__fmt);
}

void println_string(const char *__fmt, ...){
    Serial.println(__fmt);
}

void print_value(int input){
    Serial.print(input);
}

void println_value(int input){
    Serial.print(input);
    Serial.print("");
}



unsigned long time_millis(){
    return millis();
}

 void vTaskDelay_(int period){
    vTaskDelay(period);
 }
 
void delay_(int value){
    delay(value);
}