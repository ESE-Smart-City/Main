// emergency_listener.cpp
#include "emergency_listener.h"
#include "io.h" // Assuming io.h includes necessary functions like setPIN, println_string, digitalRead

void emergency_l::SETUP() {
    setPIN(emergency_BUTTON_ROW_1, INPUT);
    setPIN(emergency_BUTTON_ROW_2, INPUT);
    setPIN(emergency_BUTTON_ROW_3, INPUT);
    setPIN(emergency_BUTTON_ROW_4, INPUT);
}

emergency_l::emergency_l(unsigned long new_periode, int* emergency_trigger) {
    periode = new_periode;
    emergency_vehicle = emergency_trigger;

}

void emergency_l::run() {
    while (true) {
        job();
        vTaskDelay_(periode); // Assuming vTaskDelay_ is a custom function
    }
}

void emergency_l::job() {
    // Print a message to indicate that the emergency_listener job is running
    println_string("emergency_listener");

    // Read the state of the buttons
    int buttonState_1 = pin_in(emergency_BUTTON_ROW_1);
    int buttonState_2 = pin_in(emergency_BUTTON_ROW_2);
    int buttonState_3 = pin_in(emergency_BUTTON_ROW_3);
    int buttonState_4 = pin_in(emergency_BUTTON_ROW_4);

    // Check which button is pressed and assign the corresponding row to emergency_trigger
    if (buttonState_1 == HIGH) {
        println_string("Emergency button in row 1 pressed!");
        *emergency_vehicle = 1;  // Assuming emergency_vehicle is a pointer to an int
        // Handle emergency trigger logic for row 1 here
    } else if (buttonState_2 == HIGH) {
        println_string("Emergency button in row 2 pressed!");
        *emergency_vehicle = 2;  // Assign 2 to emergency_trigger
        // Handle emergency trigger logic for row 2 here
    } else if (buttonState_3 == HIGH) {
        println_string("Emergency button in row 3 pressed!");
        *emergency_vehicle = 3;  // Assign 3 to emergency_trigger
        // Handle emergency trigger logic for row 3 here
    } else if (buttonState_4 == HIGH) {
        println_string("Emergency button in row 4 pressed!");
        *emergency_vehicle = 4;  // Assign 4 to emergency_trigger
        // Handle emergency trigger logic for row 4 here
    }
}
