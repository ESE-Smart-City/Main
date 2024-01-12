#include  "io.h"

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

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