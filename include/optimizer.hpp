/**
 * @brief: This is the header file for optimizer class which
 * applies Simuluated Annealing
 * @file PID.hpp
 * @author: Shaotu Jia
 * @copyright: Copyright [2017] <SHAOTU JIA> All right reserved.
 */

 #ifndef _OPTIMIZER_HPP
 #define _OPTIMIZER_HPP

#include <vector>
#include <memory>
#include "PID.hpp"

class Optimizer {
 private:
     double kp = 0;
     double ki = 0;
     double kd = 0;
     double step = 0.01;
     double Tmax = 1000;
     double Tmin = 20;
     double Ec = 0;       // The energy in current point
     double En = 0;       // The energy in next point
     double deltaE = Ec - En; // The energy difference between current state and next state
     std::vector<double> state{kp, ki, kd};

     void move_state();
     std::vector<double> anneal();
 public:
     // initialize the std::vector<double> state
     //Optimizer(){};
     void initial_state(const double& kp, const double& ki, const double& kd);
     void set_step(const double& length);
     void set_T(const double& max, const double& min);
     int int_rand(int low, int up);

     //auto controller = std::make_unique<PID>(6);        // Create object for PID class

     //~Optimizer();

};




 #endif
