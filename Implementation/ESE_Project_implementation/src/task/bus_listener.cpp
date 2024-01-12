//
// Created by sheik on 1/7/2024.
//

#include "bus_listener.h"
#include "io.h"

void bus_l::SETUP(){
    setPIN(bus_ROW_1, INPUT);          
    setPIN(bus_ROW_2, INPUT);           
    setPIN(bus_ROW_3, INPUT);         
    setPIN(bus_ROW_4, INPUT);    

}

void bus_l::run(){
    while(true){
        job();
        vTaskDelay_(periode);
    }
}

void bus_l::job(){
    // procedure

    // check
    delay_(1);
    println_string("bus_listener");
    /*code here*/
    if (pin_in(bus_ROW_1) == HIGH)
    {
        /* code */
        if(*current_signal_state == 1){
            extendTrafficLightTime();
        }
    
        
    }else if (pin_in(bus_ROW_2) == HIGH)
    {
        /* code */
        if(*current_signal_state == 2){
            extendTrafficLightTime();
        }
    

    }else if (pin_in(bus_ROW_3) == HIGH)
    {
        /* code */
        if(*current_signal_state == 3){
            extendTrafficLightTime();
        }
    
    
    }else if (pin_in(bus_ROW_4) == HIGH)
    {
        /* code */
        if(*current_signal_state == 4){
            extendTrafficLightTime();
        }
    
    }
    
    delay_(1);
    println_string("bus_listener");

    
}

bus_l::bus_l(unsigned long new_periode, int* current_signal_state_, unsigned long* signal_periode_){
    periode = new_periode;
    current_signal_state = current_signal_state_;
    signal_periode = signal_periode_;

}


void bus_l::extendTrafficLightTime() {
    *signal_periode += extend_time; 
    println_string("Extending traffic light time for bus");
}

 

