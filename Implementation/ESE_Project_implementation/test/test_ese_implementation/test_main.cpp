
#include <unity.h>
#include "obj.h"


void setUp(void){
  emergency_triger = 0;
  signal_scheduling_task = signal_sch(period_signal,&signal_state_duration, &current_signal_state, &emergency_triger);
  emergency_listener_task = emergency_l(period_emergency ,&emergency_triger);
  bus_listener_task = bus_l(period_bus, &current_signal_state, &signal_state_duration);
}

void tearDown(void){}


void test_emergency_response(){
  emergency_triger = 1;
  signal_scheduling_task.job();
  TEST_ASSERT_EQUAL(true, signal_scheduling_task.emergency_state);
}

void test_defect_emergency_response(){
  emergency_triger = 12;
  signal_scheduling_task.job();
  TEST_ASSERT_EQUAL(false, signal_scheduling_task.emergency_state);
}


int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_emergency_response);
    RUN_TEST(test_defect_emergency_response);
    UNITY_END();
    return 0;
}
