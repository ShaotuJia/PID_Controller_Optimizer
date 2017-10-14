/**
 * @breif: This file is to implement the PID class
 * @copyright, Shaotu Jia, All rights reserved
 */

 #ifndef PID_HPP_
 #define PID_HPP_

#include <iostream>
#include <cmath>

/**
 * @breif This class is for PID controller; All computation will be done
 * in discrete time and the controll will be processed in 10 seconds.
 * @constructor Initialize the setpoint
 * @func tunning This function is to set up Kp, Ki, Kd
 * @func get_error This function is to get the real time error of system
 * @func proportion This function is to compute the proportional term in PID
 * @func integrate This function is to compute the integration term in PID
 * @func differentiate This function is to compute the differential term in PID
 * @func compute This function is to compute the output for PID controller
 * @destructor print computation results
 */

class PID {
 private:
     double setpoint = 0;    ///< The setpoint in controller
     double run_time = 10;   ///< The total run time of PID controller
     double time_interval = 0.001; ///< The time interval for computation 1ms
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
    double output = 0;                ///< final output after computation
    PID(double input):setpoint(input){};
    void tuning(double Kp_input, double Ki_input, double Kd_input);
    void get_error(const double& process_variable);
    double proportion(const double&);
    double integrate(const double&);
    double differentiate(const double&, const double&);
    void compute();
    ~PID();
};



 #endif /*PID_HPP_ */
