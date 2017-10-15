/**
 * @copyright: Copyright [2017] <SHAOTU JIA> All Right Reserved.
 */


#include <iostream>
#include <memory>
#include "PID.hpp"
#include "optimizer.hpp"

int main() {
    auto op = std::make_unique<Optimizer>();
    op ->anneal();

}
