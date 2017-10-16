/**
 * @file main.cpp
 * @author: Shaotu Jia
 * @copyright: Copyright [2017] <SHAOTU JIA> All Right Reserved.
 * @brief This main function is an example
 * @description The example shows how to use Optimizer to get optimal solution
 * and plot the iteration result using external library matplotlib.h
 */

#include <matplotlibcpp.h>
#include <optimizer.h>
#include <PID.h>
#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>



namespace plt = matplotlibcpp;

int main() {
    auto op = std::make_unique<Optimizer>();
    op ->set_T(10000, 20);
    op ->set_state(0.5, 0.5, 0);
    op ->anneal();
    std::cout << "The optimal kp = " << op ->final_state[0] <<"\n";
    std::cout << "The optimal ki = " << op ->final_state[1] <<"\n";
    std::cout << "The optimal kd = " << op ->final_state[2] <<"\n";
    auto v = op ->data;
    plt::named_plot("Error", v);
    plt::legend();
    plt::show();
}
