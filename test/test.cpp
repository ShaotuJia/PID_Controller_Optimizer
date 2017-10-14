#include <gtest/gtest.h>
#include <memory>

#include "optimizer.hpp"


TEST(optimizerTest, int_rand) {
  auto p = std::make_unique<Optimizer>();
  int rand_var = p->int_rand(1, 6);
  EXPECT_EQ(1, rand_var);
}

