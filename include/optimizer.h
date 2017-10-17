/**
 * @file optimizer.hpp
 * @brief: This is the header file for optimizer class which
 * applies Simuluated Annealing
 * @author: Shaotu Jia
 * @copyright (C) 2007 Free Software Foundation, Inc.
 */

#ifndef INCLUDE_OPTIMIZER_H_
#define INCLUDE_OPTIMIZER_H_

#include <PID.h>
#include <vector>
#include <memory>

/**
 * @brief: This class is the PID Optimizer using Simulated Annealing Algorithm
 */
class Optimizer {
 private:
     double kp = 0;       ///> The gain for proportional part
     double ki = 0;       ///> The gain for integral part
     double kd = 0;       ///> The gain for differential part
     double step = 0.01;  ///> The step length in every time change
     int Tmax = 10000;    ///> The maximum temperature
     int Tmin = 20;       ///> The minimum temperature
     double Ec = 0;       ///> The energy in current point
     double En = 0;       ///> The energy in next point
     double deltaE = Ec - En;  ///> The energy difference between current state and next state
     int amplifier = 2000;    ///> Amplifier for probability comparison
     std::vector<double> state{kp, ki, kd};   ///> The state of all gains in PID


 public:
     std::vector<double> data;      ///> The error in every iteration
     std::vector<double> final_state;     ///> The state at the final
     void move_state(const int& number);
     std::vector<double> get_state();
     void set_state(const double, const double, const double);
     void set_step(const double length);
     void set_T(const int& max, const int& min);
     void set_amplifier(const int&);
     int get_amplifier();
     double get_step();
     int get_intervalT();
     int int_rand(int low, int up, int seed);
     double decimal_rand(int seed);
     void anneal();
};




#endif  // INCLUDE_OPTIMIZER_H_
