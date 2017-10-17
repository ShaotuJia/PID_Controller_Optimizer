/**
 * @file test.cpp
 * @brief Unit Testing for every class.
 * @copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */
#include <gtest/gtest.h>
#include <memory>
#include <vector>
#include "headers/optimizer.h"
#include "headers/PID.h"



/**
 * @brief The following test is to test the final output of the function
 */
TEST(PIDTest, ComputationTest) {
  double input = 1;   ///< Input value for setpoint
  auto p = std::make_unique<PID>(input);

  //!!! change the tuning parameter to pass the last test !!
  p->tuning(0.1, 0.1, 0.1);
  p->compute();
  EXPECT_LT(std::abs(p->output - input), 0.1);
}


/**
 * @brief test function int_rand in class Optimizer
 */
TEST(optimizerTest, int_rand) {
  auto p = std::make_unique<Optimizer>();
  int rand_var = p->int_rand(1, 8, 1);
  ASSERT_GE(rand_var, 1);
  ASSERT_LE(rand_var, 8);
}

/**
 * @brief test function decimal_rand in class Optimizer
 */
TEST(optimizerTest, decimal_rand) {
  auto p = std::make_unique<Optimizer>();
  double rand_deci = p ->decimal_rand(1);
  ASSERT_GE(rand_deci, 0);
  ASSERT_LE(rand_deci, 1);
}

/**
 * @brief test function get_state in class Optimizer
 */
TEST(optimizerTest, get_initial_state) {
  auto p = std::make_unique<Optimizer>();
  auto v = p ->get_state();
  EXPECT_EQ(v[0], 0);
  EXPECT_EQ(v[1], 0);
  EXPECT_EQ(v[2], 0);
}

/**
 * @brief test function set_state in class Optimizer
 */
TEST(optimizerTest, set_state) {
  auto p = std::make_unique<Optimizer>();
  std::vector<int> e = {1, 2, 3};
  p ->set_state(e[0], e[1], e[2]);
  auto v = p ->get_state();
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

/**
 * @brief test function get_amplifier and set_amplifer in class Optimizer
 */
TEST(optimizerTEST, get_set_amplifier) {
  auto p = std::make_unique<Optimizer>();
  int expect = 1;
  p ->set_amplifier(expect);
  auto a = p ->get_amplifier();
  EXPECT_EQ(a, expect);
}

/**
 * @brief test function set_T and get_intervalT
 */
TEST(optimizerTEST, get_set_T) {
  auto p = std::make_unique<Optimizer>();
  int expect_Tmax = 1000;
  int expect_Tmin = 0;
  p ->set_T(expect_Tmax, expect_Tmin);
  auto intervalT = p ->get_intervalT();
  EXPECT_EQ(intervalT, expect_Tmax - expect_Tmin);
}


/**
 * @brief test function set_step and get_step in class Optimizer
 */
TEST(optimizerTEST, get_set_step) {
  auto p = std::make_unique<Optimizer>();
  int expect = 1;
  p ->set_step(expect);
  auto s = p ->get_step();
  EXPECT_EQ(s, expect);
}
/**
 * @brief test function move_state in class Optimizer
 */
TEST(optimizerTest, move_state) {
  auto p = std::make_unique<Optimizer>();
  auto step = 0.01;

  // test for case 1
  p ->set_state(1, 2, 3);
  p ->move_state(1);
  auto a = p ->get_state();
  EXPECT_EQ(a[0], 1 - step);
  EXPECT_EQ(a[1], 2 - step);
  EXPECT_EQ(a[2], 3 - step);

  // test for case 2
  p ->set_state(1, 2, 3);
  p ->move_state(2);
  auto b = p ->get_state();
  EXPECT_EQ(b[0], 1 + step);
  EXPECT_EQ(b[1], 2 - step);
  EXPECT_EQ(b[2], 3 - step);

  // test for case 3
  p ->set_state(1, 2, 3);
  p ->move_state(3);
  auto c = p ->get_state();
  EXPECT_EQ(c[0], 1 - step);
  EXPECT_EQ(c[1], 2 + step);
  EXPECT_EQ(c[2], 3 - step);

  // test for case 4
  p ->set_state(1, 2, 3);
  p ->move_state(4);
  auto d = p ->get_state();
  EXPECT_EQ(d[0], 1 - step);
  EXPECT_EQ(d[1], 2 - step);
  EXPECT_EQ(d[2], 3 + step);

  // test for case 5
  p ->set_state(1, 2, 3);
  p ->move_state(5);
  auto e = p ->get_state();
  EXPECT_EQ(e[0], 1 + step);
  EXPECT_EQ(e[1], 2 + step);
  EXPECT_EQ(e[2], 3 - step);

  // test for case 6
  p ->set_state(1, 2, 3);
  p ->move_state(6);
  auto f = p ->get_state();
  EXPECT_EQ(f[0], 1 - step);
  EXPECT_EQ(f[1], 2 + step);
  EXPECT_EQ(f[2], 3 + step);

  // test for case 7
  p ->set_state(1, 2, 3);
  p ->move_state(7);
  auto g = p ->get_state();
  EXPECT_EQ(g[0], 1 + step);
  EXPECT_EQ(g[1], 2 - step);
  EXPECT_EQ(g[2], 3 + step);

  // test for case 8
  p ->set_state(1, 2, 3);
  p ->move_state(8);
  auto h = p ->get_state();
  EXPECT_EQ(h[0], 1 + step);
  EXPECT_EQ(h[1], 2 + step);
  EXPECT_EQ(h[2], 3 + step);
}

/**
 * @brief This is test whether the optimal solution using function
 * anneal() is acceptable
 */
TEST(optimizerTEST, anneal) {
  auto p = std::make_unique<Optimizer>();
  int max_error = 1;
  p ->set_T(10000, 20);
  p ->set_state(0.5, 0.5, 0);
  p ->anneal();
  auto v = p ->data;
  ASSERT_LE(v.back(), max_error);
}

