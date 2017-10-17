/**
 * @file main.cpp
 * @brief: This is the main function of unit testing
 * @copyright (C) 2007 Free Software Foundation, Inc.
 */

#include <gtest/gtest.h>

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
