/**
 * @breif: This is the header file for optimizer class which
 * applies Simuluated Annealing
 * @author: Shaotu Jia
 * @copyright: SHAOTU JIA. All right reserved.
 */

 #ifndef OPTIMIZER_HPP
 #define OPTIMIZER_HPP

#include <vector>
#include "PID.hpp"

class Optimizer: public PID {
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
     void initial_state(const double& kp, const double& ki, const double& kd);
     void set_step(const double& length);
     void set_T(const double& max, const double& min);
     ~Optimizer();

};







 #endif
