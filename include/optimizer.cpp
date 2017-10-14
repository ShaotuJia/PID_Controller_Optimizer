/**
 * @brief: This is the source file for optimizer class which
 * applies Simuluated Annealing
 * @file PID.hpp
 * @author: Shaotu Jia
 * @copyright: Copyright [2017] <SHAOTU JIA>, All right reserved.
 */

#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include "optimizer.hpp"


/**
 * @brief: this function is to generate integer number in range(low_bound, up_bound)
 * for example, int_rand(1,6) is to generate integer 1 ~ 6
 * @param low This is the lower bound of random number
 * @param up This is the upper bound of random number
 * @return A random integer within the range
 */
int Optimizer::int_rand(int low, int up) {
  std::srand(time(NULL));         // set the random seed as current time
  int d = std::abs(up - low) + 1;   // the difference to % in next step
  return (std::rand() % d + 1);
}

void Optimizer::move_state() {
  int number = int_rand(1, 6);
}

void initial_state(const double& kp, const double& ki, const double& kd) {

}

void set_step(const double& length) {

}

void set_T(const double& max, const double& min) {

}


std::vector<double> anneal() {

}
