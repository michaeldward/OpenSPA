#include <unity.h>

#ifdef UNIT_TEST

#include "spa_communicator.hpp"
#include "routing_table.hpp"

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }

void test_test(void) {
    TEST_ASSERT_EQUAL(0,0);
}

int main(int argc, char **argv) {
  UNITY_BEGIN(); // Important! Must appear before any tests run!
  RUN_TEST(test_test);
  RUN_TEST(test_test_another);

  // Routing Table Specs
  RUN_TEST(routing_table_insert);
  RUN_TEST(routing_table_exists);
  RUN_TEST(routing_table_get_physical_address);

  // RUN_TEST(spa_communicator_isLocal);

  UNITY_END(); // Important! Must occur at end of test file

  return 0;
};

#endif
