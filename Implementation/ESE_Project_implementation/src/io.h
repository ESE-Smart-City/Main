#ifndef IO_
#define IO_

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

void pin_out(int pin, int value);
bool pin_in(int pin);
void setPIN(int pin, int type);

void print_string(const char *__fmt, ...);
void println_string(const char *__fmt, ...);

void print_value_int(int input);
void println_value_int(int input);

unsigned long time_millis();

void vTaskDelay_(int period);
void delay_(int value);

// pin
extern int ROW_1_OUTPUT;
extern int ROW_2_OUTPUT;
extern int ROW_3_OUTPUT;
extern int ROW_4_OUTPUT;

extern int bus_ROW_1;
extern int bus_ROW_2;
extern int bus_ROW_3;
extern int bus_ROW_4;

extern int emergency_BUTTON_ROW_1;
extern int emergency_BUTTON_ROW_2;
extern int emergency_BUTTON_ROW_3;
extern int emergency_BUTTON_ROW_4;

// for pin test purpose 
extern int pin_value[40]; // pin value
extern int pin_mode[40]; // pin mode

#endif