//
// Created by sheik on 1/7/2024.
//

#include "emergency_listener.h"
#include "io.h"

void emergency_l::SETUP(){
    setPIN(emergency_ROW_1, INPUT);          
    setPIN(emergency_ROW_2, INPUT);           
    setPIN(emergency_ROW_3, INPUT);         
    setPIN(emergency_ROW_4, INPUT);           
}

emergency_l::emergency_l(unsigned long new_periode, int* emergency_trigger){
    periode = new_periode;
    emergency_vehicle = emergency_trigger;
}

void emergency_l::run(){
    while(true){
        job();
        vTaskDelay_(periode);
    }
}

void emergency_l::job(){
    // procedure
    println_string("emergency_listener");

}

/*
void generateRandomEmergencyTrigger() {
    //
    int probability = 0;
    int emergency_trigger = 0;


    // Generate a random number between 1 and 4
    int randomValue = rand() % 4 + 1;

    // Check if it's time to trigger an emergency
    if (randomValue < probability * 100) {
        // Set the emergency trigger to the generated random value between 1 and 4
        emergency_trigger = randomValue;
        // You can add additional logic here if needed
    } else {
        // Set emergencyTrigger to 0 (or another appropriate value) if the condition is not met
        emergencyTrigger = 0;
    }
}
*/