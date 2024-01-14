//
// Created by sheik on 1/7/2024.
// update by adi 13.01.24
//

#include "signal_scheduling.h"
#include  "io.h"

void signal_sch::ROW1(){
    pin_out(ROW_1_OUTPUT,HIGH);
    pin_out(ROW_2_OUTPUT,LOW);
    pin_out(ROW_3_OUTPUT,LOW);
    pin_out(ROW_4_OUTPUT,LOW);
}

void signal_sch::ROW2(){
    pin_out(ROW_1_OUTPUT,LOW);
    pin_out(ROW_2_OUTPUT,HIGH);
    pin_out(ROW_3_OUTPUT,LOW);
    pin_out(ROW_4_OUTPUT,LOW);
}

void signal_sch::ROW3(){
    pin_out(ROW_1_OUTPUT,LOW);
    pin_out(ROW_2_OUTPUT,LOW);
    pin_out(ROW_3_OUTPUT,HIGH);
    pin_out(ROW_4_OUTPUT,LOW);
}

void signal_sch::ROW4(){
    pin_out(ROW_1_OUTPUT,LOW);
    pin_out(ROW_2_OUTPUT,LOW);
    pin_out(ROW_3_OUTPUT,LOW);
    pin_out(ROW_4_OUTPUT,HIGH);
}

void signal_sch::ROWEmergency(){
    if (emergency_ROW == 1){
        ROW1();
    }
    else if (emergency_ROW == 2){
        ROW2();
    }
    else if (emergency_ROW == 3){
        ROW3();
    }
    else if (emergency_ROW == 4){
        ROW4();
    }
}

void signal_sch::SETUP(){
    setPIN(ROW_1_OUTPUT, OUTPUT);          
    setPIN(ROW_2_OUTPUT, OUTPUT);           
    setPIN(ROW_3_OUTPUT, OUTPUT);         
    setPIN(ROW_4_OUTPUT, OUTPUT);           
}

void signal_sch::run(){
    //emergency_l emergency_listener(1000, emergency_vehicle); // Adjust the period as needed -> those job are independent
    while(true){
        job();
        //emergency_listener.job(); // Call the job function of the emergency_listener -> those job are independent
        vTaskDelay_(periode);
    } 
}
signal_sch::signal_sch(unsigned long new_periode, unsigned long* state_duration_, int* current_state_, int* emergency_trigger, bool* allow_extention_)
    : periode(new_periode), current_state(current_state_), state_default_duration(*state_duration_),
      state_duration(state_duration_), emergency_vehicle(emergency_trigger),allow_extention (allow_extention_){
}
/*signal_sch::signal_sch(unsigned long new_periode,unsigned long* state_duration_ ,int* current_state_, int* emergency_trigger){
    periode = new_periode;
    current_state = current_state_;
    state_default_duration = *state_duration_;
    state_duration = state_duration_;
    emergency_vehicle = emergency_trigger;
}
*/
void signal_sch::job(){
    // procedure
    println_string("Signal_scheduling");

    // update current state clock
    current_state_clock = time_millis();

    // check for state change using time constraint (current state validation)
    if(!emergency_state){
        if((current_state_clock - start_state_clock)> *state_duration){
        change_state = true;
        }
    }
    else{
        // for now the duration for emergency state is equal to default duration instead of waiting the emergency vehicle to pass
        if(change_immediate_emergency_state){
            if((current_state_clock-start_emergency_state_clock)> *state_duration){
            change_state = true;
            }
        }
        else if((current_state_clock- start_emergency_state_clock)> *state_duration){
        change_state = true;
        }
    }
    

    // check for bus time extention
    if ((*state_duration != state_default_duration)&&(!extended)){
        println_string("Signal_scheduling -> extending periode");
        extended = true;
        *allow_extention = false;
    }

    // check for emergency input
    if(!emergency_mode){
        *emergency_vehicle = 0;

    }
    if (*emergency_vehicle>0 && *emergency_vehicle<5){
            println_string("Signal_scheduling -> Emergency input detected");
            // for now the emergency will be next insted of change it immediately
            if(!change_immediate_emergency_state){
                // change next state to emergency and store history state
                hold_state = next_state;
                next_state = 5;

                // get which ROW the emergency vehivle come form and reset the input
                emergency_ROW = *emergency_vehicle;
                *current_state = *emergency_vehicle;
                *emergency_vehicle = 0;
            }
            // lab: experiment for change immediately
            else{
                hold_state = *current_state;
                next_state = 5;
                // get which ROW the emergency vehivle come form and reset the input
                emergency_ROW = *emergency_vehicle;
                *current_state = *emergency_vehicle;
                *emergency_vehicle = 0;

                // store current state information
                hold_start_state_clock = start_state_clock;
                hold_duration_state_clock = current_state_clock - start_state_clock;

                //change immediate
                change_state = true;
                start_emergency_state_clock = current_state_clock;
            }
        }

    // exit emergency procedure
    if (emergency_state){
        if(change_state){

            // reset varabels
            emergency_state = false;
            next_state = hold_state;
            hold_state = 0;
            *emergency_vehicle = 0;

            if(change_immediate_emergency_state){
                // continue pervious state
                start_state_clock = current_state_clock - hold_duration_state_clock;
                state_clock_hold = true;
            }
        }
    }

    // execute task
    if (change_state){
        // reset
        *allow_extention = true;
        extended = false;
        *state_duration = state_default_duration;
        change_state = false;
        if(state_clock_hold && !emergency_state){
            state_clock_hold = false;
        }
        else{
            start_state_clock = current_state_clock;
        }

        // change
        switch(next_state){
        case 1:
            println_string("Signal_scheduling -> state 1");
            *current_state = 1;
            ROW1();
            next_state = 2;
            break;
        case 2:
            println_string("Signal_scheduling -> state 2");
            *current_state = 2;
            ROW2();
            next_state = 3;
            break;
        case 3:
            println_string("Signal_scheduling -> state 3");
            *current_state = 3;
            ROW3();
            next_state = 4;
            break;
        case 4:
            println_string("Signal_scheduling -> state 4");
            *current_state = 4;
            ROW4();
            next_state = 1;
            break;
        
        case 5:
            println_string("Signal_scheduling -> Emergency state");
            *current_state = 5;
            start_emergency_state_clock = current_state_clock;
            ROWEmergency();
            // update handler
            emergency_state = true;
            break;
    }

    }
    
    delay_(1);

}


