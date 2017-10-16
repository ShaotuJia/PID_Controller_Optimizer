# PID_Controller_Optimizer
[![Build Status](https://travis-ci.org/ShaotuJia/PID_Controller_Optimizer.svg?branch=master)](https://github.com/ShaotuJia/PID_Controller_Optimizer.git)
[![Coverage Status](https://coveralls.io/repos/github/ShaotuJia/PID_Controller_Optimizer/badge.svg?branch=master)](https://coveralls.io/github/ShaotuJia/PID_Controller_Optimizer?branch=master)
---

# Enacting and Measuring SIP
The product log, time log, and defect log are written in google sheet. [click_here](https://docs.google.com/spreadsheets/d/1u9WEmkIhlhbIRRlmwj4HqYvlbm0llhUNIEqe1h8LvHQ/edit?usp=sharing)


## Standard install via command-line
```
git clone --recursive https://github.com/ShaotuJia/PID_Controller_Optimizer.git
cd <path to repository>
mkdir build
cd build
cmake ..
make
Run tests: ./test/optimizer-test
Run program: ./app/pid_optimizer
```

## Motivation

PID controller is a kind of feedback control system widely used in industry. The controller is usually operated by three gains Kp, Ki, Kd for proportion, integral, and differentiation, respectively. The settings of gains will determine the performance of PID controller. In some industry, the PID controller still need engineers manually setup; it often requires experience during tuning. This project will apply Gradient Descent method to optimize the performance of a PID controller. 

## Algorithm Description

Gradient descent is a machine learning algorithm using first-order iterative optimization. This algorithm has been proved to be a practical way to find the minima of a function or its maxima (usually called gradient ascent when finding maxima).

To explain the algorithm, here we use the Figure 1 to illustrate the process of gradient descent. The blue circle is the value of function F(x) represented by level set; its value gradually decreases from out layer to the center. The red arrow shows the optimization process. The variable x starts from x0. In this case, the variable x goes to the steepest direction and reach the next position x1. The program will iterate this step until finding the local minima or reach the boundary value of x.  

<img src="https://upload.wikimedia.org/wikipedia/commons/f/ff/Gradient_descent.svg" width=400 height=400>

## Design Outline
This project can be separated into two parts, optimization, and visualization. The optimization is the core part that computes the function minima. The visualization will draw a 2D graph to check whether the function value trends to smaller.
* ### Optimization Part Requirements:
  * Programming Language: C++ with C++ 14 Features
  * Build System: CMake 3.2.1 Above
  * Compiler: GCC
  * Unit Testing: googletest
* ### Visualization Part Requirements:
  * External Library: matplotlib-cpp 

## Development Process
- [ ] Implement the core optimizer using Gradient Descent. 
- [ ] Apply google test to verify the implementation.
- [ ] Apply this optimizer to polynomials (from first order to higher order)
- [ ] Visualize output data using python 3 and Matplotlib library. 
- [ ] Apply the optimizer to PID controller implemented in Week 4 assignment. 
- [ ] Use matplotlib-cpp library to visualize the iteration process

## Final Deliverables:
- [ ] Implementation of Optimization class
- [ ] Sample polynomial functions and Sample PID controller for Unit Testing
- [ ] The Unit Testing using google test
- [ ] Github README with TravisCI and Coverage of Coveralls
- [ ] Doxygen Documentation
