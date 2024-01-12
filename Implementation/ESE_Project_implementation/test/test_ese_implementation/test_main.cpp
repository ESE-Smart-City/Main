
#include <unity.h>
#include "obj.h"


void setUp(void){}

void tearDown(void){}

void test_signal_ROW_1_OUTPUT(){
  TEST_ASSERT_EQUAL(20, signal_scheduling_task.ROW_1_OUTPUT);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();
    RUN_TEST(test_signal_ROW_1_OUTPUT);
    UNITY_END();
    return 0;
}
