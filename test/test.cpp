/**
 * @brief: Unit Testing for every class
 * @copyright: Copyright [2017] <SHAOTU JIA> All Right Reserved
 */


#include <gtest/gtest.h>
#include <memory>

#include "optimizer.hpp"


TEST(optimizerTest, int_rand) {
  auto p = std::make_unique<Optimizer>();
  int rand_var = p->int_rand(1, 8, 1);
  ASSERT_GE(rand_var, 1);
  ASSERT_LE(rand_var, 8);
}

TEST(optimizerTest, decimal_rand) {
  auto p = std::make_unique<Optimizer>();
  double rand_deci = p ->decimal_rand(1);
  ASSERT_GE(rand_deci, 0);
  ASSERT_LE(rand_deci, 1);
}

TEST(optimizerTest, get_state) {
  auto p = std::make_unique<Optimizer>();
  auto v = p ->get_state();
  EXPECT_EQ(v[0], 0);
  EXPECT_EQ(v[1], 0);
  EXPECT_EQ(v[2], 0);
}

TEST(optimizerTest, initial_state) {
  auto p = std::make_unique<Optimizer>();
  p ->set_state(1, 2, 3);
  auto v = p ->get_state();
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(v[2], 3);
}

TEST(optimizerTEST, get_set_amplifier) {
  auto p = std::make_unique<Optimizer>();
  int expect = 1;
  p ->set_amplifier(expect);
  auto a = p ->get_amplifier();
  EXPECT_EQ(a, expect);
}

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

