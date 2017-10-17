/**
 * @file app/main.cpp
 * @author Shaotu Jia
 * @copyright (C) 2007 Free Software Foundation, Inc.
 * @brief This main function is an example.
 * @description The example shows how to use Optimizer to get optimal solution
 * and plot the iteration result using external library matplotlib.h.
 *
 * @details GNU GENERAL PUBLIC LICENSE. Version 3, 29 June 2007
 * Everyone is permitted to copy and distribute verbatim copies
 * of this license document, but changing it is not allowed.
 *
 * @mainpage[Abstract]
 * PID controller is a kind of feedback control system
 * widely used in industry. The controller is usually operated by three gains
 * Kp, Ki, Kd for proportion, integral, and differentiation, respectively.
 * The settings of gains will determine the performance of PID controller.
 * In some industry, the PID controller still need engineers manually setup;
 * it often requires experience during tuning.
 * Simulated Annealing is a local search algorithm inspired by statistical physics
 * to appoximate the global optimum of a function.
 * This project will apply Simulated Annealing method
 * to optimize the performance of a PID controller.
 */
#include <matplotlibcpp.h>
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>
#include "headers/optimizer.h"
#include "headers/PID.h"

namespace plt = matplotlibcpp;

/**
 * @brief This main function is a demo about how to run this program
 */
int main() {
    auto op = std::make_unique<Optimizer>();  ///< Create an object for class Optimizer
    op ->set_T(10000, 20);  ///< Set up Tmax and Tmin
    op ->set_state(0.5, 0.5, 0);  ///< Set up the initial state
    op ->anneal();    ///< Call Simulated Annealing for computation
    std::cout << "The optimal kp = " << op ->final_state[0] <<"\n";
    std::cout << "The optimal ki = " << op ->final_state[1] <<"\n";
    std::cout << "The optimal kd = " << op ->final_state[2] <<"\n";
    auto v = op ->data;
    plt::named_plot("Error", v);  ///< Plot data
    plt::legend();  ///< show legend on graph
    plt::show();  ///< show the graph
}
