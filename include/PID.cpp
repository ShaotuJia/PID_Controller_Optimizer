/**
 * @file PID.cpp
 * @brief This is the source file for PID class.
 * @copyright (C) 2007 Free Software Foundation, Inc.
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 */
#include "headers/PID.h"


/**
 * @brief The constructor set up the setpoint
 * @param input Set up the setpoint
 */
PID::PID(double input):setpoint(input) {}


/**
 * @brief This function is to configure the parameters in PID equation
 * @param Kp_input A double as the parameter of proportional term
 * @param Ki_input A double as the parameter of integration term
 * @param Kd_input A double as the parameter of differential term
 */
void PID::tuning(double Kp_input, double Ki_input, double Kd_input) {
    Kp = Kp_input;
    Ki = Ki_input;
    Kd = Kd_input;
}

/**
 * @brief This function is to set up the value of current error e_c
 * @param process_variable The output during PID looping
 */
void PID::get_error(const double& process_variable) {
    e_c = setpoint - process_variable;
}

/**
 * @brief This function is to compute the proportional term
 * @param e_c The error in current feedback loop
 * @return the value of proportional term
 */
double PID::proportion(const double& e_c) {
    return (e_c * Kp);
}

/**
 * @brief This function is to compute the integration term
 * @param e_c The error in current feedback loop
 * @return the value of integration term
 */
double PID::integrate(const double& e_c) {
    e_total += e_c;
    return (e_total * Ki);
}

/**
 * @brief This function is to compute the proportional term
 * @param e_c The error in current feedback loop
 * @param e_l The error in last time feedback loop
 * @return the value of differential term
 */
double PID::differentiate(const double& e_c, const double& e_l) {
    return ((e_c - e_l) * Kd);
}

/**
 * @brief This function is to compute the PID controll loop
 */
void PID::compute() {
    for (int t = 0; t <= run_time/time_interval; t++) {
        get_error(process_variable);
        process_variable = proportion(e_c) + integrate(e_c)\
            + differentiate(e_c, e_l);
        e_l = e_c;    ///< pass current error to last time error
        if (std::abs(e_c) < tolerance) {
            time_to_stable = t * time_interval;
            output = setpoint - e_c;
            break;
        } else {
          output = setpoint - e_c;
        }
    }
    final_error = e_c;
}

