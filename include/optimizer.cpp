/**
 * @brief: This is the source file for optimizer class which
 * applies Simuluated Annealing
 * @file PID.hpp
 * @author: Shaotu Jia
 * @copyright: Copyright [2017] <SHAOTU JIA>, All right reserved.
 */
#include <math.h>
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
int Optimizer::int_rand(int low, int up, int seed) {
  std::srand(time(NULL) + seed);         // set the random seed as current time
  int d = std::abs(up - low) + 1;   // the difference to % in next step
  return (std::rand() % d + 1);
}

/**
 * @brief: This function is to generate decimal number from 0 to 1
 * return decimal number
 */
double Optimizer::decimal_rand(int seed) {
  std::srand(time(NULL) + seed);
  return (std::rand()/RAND_MAX);
}
/**
 * @brief: This function is to change the gain kp, ki, kd during optimization
 * @param number This is an integer (1, 8)
 */
void Optimizer::move_state(const int& number) {
  if (number >=1 && number <=8) {
    switch (number) {
      case 1:
        kp -= step, ki -= step, kd -= step;
        break;
      case 2:
        kp += step, ki -= step, kd -= step;
        break;
      case 3:
        kp -= step, ki += step, kd -= step;
        break;
      case 4:
        kp -= step, ki -= step, kd += step;
        break;
      case 5:
        kp += step, ki += step, kd -= step;
        break;
      case 6:
        kp -= step, ki += step, kd += step;
        break;
      case 7:
        kp += step, ki -= step, kd += step;
        break;
      case 8:
        kp += step, ki += step, kd += step;
        break;
    }
  } else {
    std::cout << "number for move_state must be >=1 && <=8 \n";
  }
  if (kp < 0) kp = 0;
  if (ki < 0) ki = 0;
  if (kd < 0) kd = 0;
  state.clear();
  state = {kp, ki, kd};       // Assign kp, ki, kd to state
}

std::vector<double> Optimizer::get_state() {
  return (state);
}

void Optimizer::set_state(const double Kp, \
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

void Optimizer::set_amplifier(const int& a) {
  amplifier = a;
}

int Optimizer::get_amplifier() {
  return amplifier;
}


void Optimizer::anneal() {
  int setpoint = 6;
  auto p = std::make_unique<PID>(setpoint);

  for (int i = Tmax; i >= Tmin; i--) {
    // get current energy
    auto current_state = get_state();
    p ->tuning(state[0], state[1], state[2]);
    p ->compute();
    Ec = fabs(p ->final_error);      // get error for current energy

    // get next energy
    int rand_var = int_rand(1, 8, i);
    move_state(rand_var);
    p ->tuning(state[0], state[1], state[2]);
    p ->compute();
    En = fabs(p ->final_error);      // get error of next energy

    deltaE = Ec - En; // difference between current energy to next energy
    auto rand_deci = decimal_rand(i);

    if (deltaE > 0) {
      data.push_back(En);

    } else if (exp(deltaE*2000) < rand_deci) {
      // Once next energy is not applicable;
      // We set back the state to current state,
      // and regenerate random move_state
      set_state(current_state[0], current_state[1], current_state[2]);
    }
    final_state = get_state();

  }
}
