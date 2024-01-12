//
// Created by sheik on 1/7/2024.
//



#include "bus_listener.h"

void bus_l::SETUP(){
    pinMode(bus_ROW_1, INPUT);          
    pinMode(bus_ROW_2, INPUT);           
    pinMode(bus_ROW_3, INPUT);         
    pinMode(bus_ROW_4, INPUT);    

}

void bus_l::run(){
    while(true){
        job();
        vTaskDelay(periode);
    }
}

void bus_l::job(){
    // procedure

    // check
    delay(1);
    Serial.println("bus_listener");
    /*code here*/
    if (digitalRead(bus_ROW_1) == HIGH)
    {
        /* code */
        if(*current_signal_state == 1){
            extendTrafficLightTime();
        }
    
        
    }else if (digitalRead(bus_ROW_2) == HIGH)
    {
        /* code */
        if(*current_signal_state == 2){
            extendTrafficLightTime();
        }
    

    }else if (digitalRead(bus_ROW_3) == HIGH)
    {
        /* code */
        if(*current_signal_state == 3){
            extendTrafficLightTime();
        }
    
    
    }else if (digitalRead(bus_ROW_4) == HIGH)
    {
        /* code */
        if(*current_signal_state == 4){
            extendTrafficLightTime();
        }
    
    }
    
    delay(1);
    Serial.println("bus_listener");

    
}

bus_l::bus_l(unsigned long new_periode, int* current_signal_state_, unsigned long* signal_periode_){
    periode = new_periode;
    current_signal_state = current_signal_state_;
    signal_periode = signal_periode_;

}


void bus_l::extendTrafficLightTime() {
    *signal_periode += extend_time; 
    Serial.println("Extending traffic light time for bus");
}

 

