#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "spa_communicator_test.hpp"
#include "routing_table_test.hpp"
#include "network_communicator_test.hpp"

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
