/**
 * @brief: This is the source file for optimizer class which
 * applies Simuluated Annealing
 * @file PID.hpp
 * @author: Shaotu Jia
 * @copyright: Copyright [2017] <SHAOTU JIA>, All right reserved.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <memory>
#include "optimizer.hpp"


/**
 * @brief: this function is to generate integer number in range(low_bound, up_bound)
 * for example, int_rand(1,8) is to generate integer 1 ~ 8
 * @param low This is the lower bound of random number
 * @param up This is the upper bound of random number
 * @return A random integer within the range
 */
int Optimizer::int_rand(int low, int up) {
  std::srand(time(NULL));         // set the random seed as current time
  int d = std::abs(up - low) + 1;   // the difference to % in next step
  return (std::rand() % d + 1);
}
/**
 * @brief: This function is to change the gain kp, ki, kd during optimization
 * @param number This is an integer (1, 8)
 */
void Optimizer::move_state(const int& number) {
  if (number >=1 && number <=8) {
    switch (number) {
      case 1: kp -= step, ki -= step, kd -= step;
      case 2: kp += step, ki -= step, kd -= step;
      case 3: kp -= step, ki += step, kd -= step;
      case 4: kp -= step, ki -= step, kd += step;
      case 5: kp += step, ki += step, kd -= step;
      case 6: kp -= step, ki += step, kd += step;
      case 7: kp += step, ki -= step, kd += step;
      case 8: kp += step, ki += step, kd += step;
    }
  } else {
    std::cout << "number for move_state must be >=1 && <=8 \n";
  }
  state.clear();
  state = {kp, ki, kd};       // Assign kp, ki, kd to state
}

std::vector<double> Optimizer::get_state() {
  return (state);
}

void Optimizer::initial_state(const double Kp, \
                              const double Ki, const double Kd) {
  kp = Kp;
  ki = Ki;
  kd = Kd;
  state.clear();
  state = {kp, ki, kd};
}

void Optimizer::set_step(const double length) {
  step = length;
}

void Optimizer::set_T(const int& max, const int& min) {
  Tmax = max;
  Tmin = min;
}


void Optimizer::anneal() {
  int setpoint = 6;
  auto p = std::make_unique<PID>(setpoint);
  p ->tuning(0.1, 0.1, 0);
  p ->compute();
  Ec = p ->output;
}
