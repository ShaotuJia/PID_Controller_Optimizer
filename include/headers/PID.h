/**
 * @file PID.h
 * @brief This is the header file for PID class.
 * @author Shaotu Jia
 * @copyright Copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */
#ifndef INCLUDE_HEADERS_PID_H_
#define INCLUDE_HEADERS_PID_H_

#include <iostream>
#include <cmath>

/**
 * @brief This class is for PID controller; All computation will be done
 * in discrete time and the control will be processed in 10 seconds.
 */
class PID {
 private:
     double setpoint = 0;    ///< The setpoint in controller
     double run_time = 10;   ///< The total run time of PID controller
     double time_interval = 0.001;  ///< The time interval for computation 1ms
     double Kp = 0;     ///< The proportional gain, a tuning paremeter
     double Ki = 0;     ///< The integral gain, a tuning paremeter
     double Kd = 0;     ///< The derivative gain, a tuning paremeter
     double process_variable = 0;    ///< The output in current loop
     double e_c = 0;    ///< THe error in current time
     double e_l = 0;    ///< The error in last time
     double e_total = 0;    ///< The total error during computation
     double tolerance = 0.1;    ///< The tolerance for error

 public:
    double time_to_stable = 0;    ///< time to stabilized
    double final_error = 0;       ///< error at the final
    double output = 0;                ///< final output after computation
    explicit PID(double);
    void tuning(double Kp_input, double Ki_input, double Kd_input);
    void get_error(const double& process_variable);
    double proportion(const double&);
    double integrate(const double&);
    double differentiate(const double&, const double&);
    void compute();
};

#endif  // INCLUDE_HEADERS_PID_H_

