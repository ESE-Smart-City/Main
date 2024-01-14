
#include <unity.h>
#include "obj.h"


void setUp(void){
  emergency_trigger = 0;
  signal_scheduling_task = signal_sch(period_signal,&signal_state_duration, &current_signal_state, &emergency_trigger);
  emergency_listener_task = emergency_l(period_emergency ,&emergency_trigger);
  bus_listener_task = bus_l(period_bus, &current_signal_state, &signal_state_duration);

}

void tearDown(void){}


void test_emergency_response(){
  emergency_trigger = 1;
  signal_scheduling_task.SETUP();
  signal_scheduling_task.job();
  TEST_ASSERT_EQUAL(true, signal_scheduling_task.emergency_state);
}

void test_defect_emergency_response(){
  emergency_trigger = 12;
  signal_scheduling_task.SETUP();
  signal_scheduling_task.job();
  TEST_ASSERT_EQUAL(false, signal_scheduling_task.emergency_state);
}
void test_next_state_from_state1(){
  signal_scheduling_task.SETUP();
  signal_scheduling_task.next_state = 1;

  signal_scheduling_task.job();

  TEST_ASSERT_EQUAL(2, signal_scheduling_task.next_state);
}
void test_next_state_from_state2(){
  signal_scheduling_task.SETUP();
  signal_scheduling_task.next_state = 2;

  signal_scheduling_task.job();

  TEST_ASSERT_EQUAL(3, signal_scheduling_task.next_state);
}
void test_next_state_from_state3(){
  signal_scheduling_task.SETUP();
  signal_scheduling_task.next_state = 3;

  signal_scheduling_task.job();

  TEST_ASSERT_EQUAL(4, signal_scheduling_task.next_state);
}
void test_next_state_from_state4(){
  signal_scheduling_task.SETUP();
  signal_scheduling_task.next_state = 4;

  signal_scheduling_task.job();

  TEST_ASSERT_EQUAL(1, signal_scheduling_task.next_state);
}
void test_next_state_emergency(){
  signal_scheduling_task.SETUP();
  signal_scheduling_task.next_state = 3;

  signal_scheduling_task.job();
  
  TEST_ASSERT_EQUAL(4, signal_scheduling_task.next_state);
}

void test_ROW1ActivatesOnlyROW1Output(void) {
  signal_scheduling_task.SETUP();
    signal_scheduling_task.next_state = 1;

    signal_scheduling_task.job();

    TEST_ASSERT_EQUAL(HIGH, pin_value[ROW_1_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_2_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_3_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_4_OUTPUT]);
}

void test_ROW2ActivatesOnlyROW2Output(void) {
  signal_scheduling_task.SETUP();
    signal_scheduling_task.next_state = 2;

    signal_scheduling_task.job();


    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_1_OUTPUT]);
    TEST_ASSERT_EQUAL(HIGH, pin_value[ROW_2_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_3_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_4_OUTPUT]);
}


void test_ROW3ActivatesOnlyROW3Output(void) {
  signal_scheduling_task.SETUP();
    signal_scheduling_task.next_state = 3;

    signal_scheduling_task.job();


    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_1_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_2_OUTPUT]);
    TEST_ASSERT_EQUAL(HIGH, pin_value[ROW_3_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_4_OUTPUT]);
}


void test_ROW4ActivatesOnlyROW4Output(void) {
  signal_scheduling_task.SETUP();
    signal_scheduling_task.next_state = 4;

    signal_scheduling_task.job();


    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_1_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_2_OUTPUT]);
    TEST_ASSERT_EQUAL(LOW, pin_value[ROW_3_OUTPUT]);
    TEST_ASSERT_EQUAL(HIGH, pin_value[ROW_4_OUTPUT]);
}

void test_SetupConfiguresPinsAsOutput(void) {
  signal_scheduling_task.SETUP();
    signal_scheduling_task.next_state = 0;

    signal_scheduling_task.job();

    TEST_ASSERT_EQUAL(OUTPUT, pin_mode[ROW_1_OUTPUT]);
    TEST_ASSERT_EQUAL(OUTPUT, pin_mode[ROW_2_OUTPUT]);
    TEST_ASSERT_EQUAL(OUTPUT, pin_mode[ROW_3_OUTPUT]);
    TEST_ASSERT_EQUAL(OUTPUT, pin_mode[ROW_4_OUTPUT]);
}


int main(int argc, char **argv) {
    UNITY_BEGIN();
    //unit test
    RUN_TEST(test_emergency_response);
    RUN_TEST(test_next_state_from_state1);
    RUN_TEST(test_next_state_from_state2);
    RUN_TEST(test_next_state_from_state3);
    RUN_TEST(test_next_state_from_state4);
    RUN_TEST(test_next_state_emergency);

    
    RUN_TEST(test_ROW1ActivatesOnlyROW1Output);
    RUN_TEST(test_ROW2ActivatesOnlyROW2Output);
    RUN_TEST(test_ROW3ActivatesOnlyROW3Output);
    RUN_TEST(test_ROW4ActivatesOnlyROW4Output);
    RUN_TEST(test_SetupConfiguresPinsAsOutput);

    // defect test
    RUN_TEST(test_defect_emergency_response);
    UNITY_END();
    return 0;
}
