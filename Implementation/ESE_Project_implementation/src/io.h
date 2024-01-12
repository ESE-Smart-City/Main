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

#endif