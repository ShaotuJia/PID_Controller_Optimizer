/**
 * @file main.cpp
 * @brief: This is the main function of unit testing
 * @copyright, Shaotu Jia, All rights reserved
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
