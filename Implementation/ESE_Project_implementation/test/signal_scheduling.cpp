//
// Created by sheik on 1/7/2024.
//

#include "signal_scheduling.h"

void signal_sch::ROW1(){
    digitalWrite(ROW_1_OUTPUT,HIGH);
    digitalWrite(ROW_2_OUTPUT,LOW);
    digitalWrite(ROW_3_OUTPUT,LOW);
    digitalWrite(ROW_4_OUTPUT,LOW);
}

void signal_sch::ROW2(){
    digitalWrite(ROW_1_OUTPUT,LOW);
    digitalWrite(ROW_2_OUTPUT,HIGH);
    digitalWrite(ROW_3_OUTPUT,LOW);
    digitalWrite(ROW_4_OUTPUT,LOW);
}

void signal_sch::ROW3(){
    digitalWrite(ROW_1_OUTPUT,LOW);
    digitalWrite(ROW_2_OUTPUT,LOW);
    digitalWrite(ROW_3_OUTPUT,HIGH);
    digitalWrite(ROW_4_OUTPUT,LOW);
}

void signal_sch::ROW4(){
    digitalWrite(ROW_1_OUTPUT,LOW);
    digitalWrite(ROW_2_OUTPUT,LOW);
    digitalWrite(ROW_3_OUTPUT,LOW);
    digitalWrite(ROW_4_OUTPUT,HIGH);
}

void signal_sch::ROWEmergency(){
    for(int i = 0; i<5 ;i++){
        if (i == emergency_ROW){
            digitalWrite(emergency_ROW_OUTPUT,HIGH);
        }
        else{
            digitalWrite(i,LOW);
        }
    }
}

void signal_sch::SETUP(){
    pinMode(ROW_1_OUTPUT, OUTPUT);          
    pinMode(ROW_2_OUTPUT, OUTPUT);           
    pinMode(ROW_3_OUTPUT, OUTPUT);         
    pinMode(ROW_4_OUTPUT, OUTPUT);           
}

void signal_sch::run(){
    while(true){
        job();
        vTaskDelay(periode);
    } 
}

signal_sch::signal_sch(unsigned long new_periode, int* emergency_trigger){
    periode = new_periode;
    default_periode = new_periode;
}

void signal_sch::job(){
    // procedure
    Serial.println("Signal_scheduling");
    if (*emergency_vehicle){
            hold_state = next_state;
            next_state = 5;
            emergency_ROW = *emergency_vehicle;
            *emergency_vehicle = 0;
        }

        switch(next_state){
            case 1:
                ROW1();
                next_state = 2;
                break;
            case 2:
                ROW2();
                next_state = 3;
                break;
            case 3:
                ROW3();
                next_state = 4;
                break;
            case 4:
                ROW4();
                next_state = 1;
                break;
            
            case 5:
                ROWEmergency();
                next_state = hold_state;
                break;
        }
    delay(1);

}


