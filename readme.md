# PID_Controller_Optimizer
[![Build Status](https://travis-ci.org/ShaotuJia/PID_Controller_Optimizer.svg?branch=master)](https://travis-ci.org/ShaotuJia/PID_Controller_Optimizer)
[![Coverage Status](https://coveralls.io/repos/github/ShaotuJia/PID_Controller_Optimizer/badge.svg?branch=master)](https://coveralls.io/github/ShaotuJia/PID_Controller_Optimizer?branch=master)
---

# Enacting and Measuring SIP
The product log, time log, and defect log are written in google sheet. [click_here](https://docs.google.com/spreadsheets/d/1u9WEmkIhlhbIRRlmwj4HqYvlbm0llhUNIEqe1h8LvHQ/edit?usp=sharing)


## Third-party package
This project uses external library 'matplotlib-cpp' to plot figure. [matplotlib-cpp](https://github.com/lava/matplotlib-cpp)
'matplotlib-cpp' requires python and its packages matplotlib, numpy, python-dev. On ubunut:
```
sudo apt-get install python-matplotlib python-numpy python2.7-dev
```

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

 Simulated annealing is a local search algorithm inspired by statistical physics to appoximate the global optimum of a function. 
 - ### Pseudocode(from 'Artificial Intelligence: A Modern Approach', Third Edition, page 126)
 ```
 function SIMULATED-ANNEALING(problem, schedule) returns a solution state
  inputs: problem, a problem
  schedule, a mapping from time to “temperature”
  current ← MAKE-NODE(problem.INITIAL-STATE)
  for t = 1 to ∞ do
   T ← schedule(t)
   if T = 0 then return current
   next ← a randomly selected successor of current
   ΔE ← next.VALUE – current.VALUE
   if ΔE > 0 then current ← next
   else current ← next only with probability exp(ΔE)/T
```
<img src="https://upload.wikimedia.org/wikipedia/commons/d/d5/Hill_Climbing_with_Simulated_Annealing.gif" width=800 height=400>

- ### Reason to Choose Simulated Annealing
PID equation is not a linear equation and it always fluctuate during tunning process. Thus, gradient descent method always stop at the local optimum and cannto find the global optimum. Thus, simulated annealing is a better choice to find global optimum.

- ### Reminder
Simuated Annealing is a probablistic technique. Thus, it usually requires more computing resource. Also, since it is probablistic the results will be different in everytime running. 

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
- [x] Implement the core optimizer using Gradient Descent. 
- [x] Apply google test to verify the implementation.
- [x] Apply this optimizer to polynomials (from first order to higher order)
- [x] Visualize output data using python 3 and Matplotlib library. 
- [x] Apply the optimizer to PID controller implemented in Week 4 assignment. 
- [x] Use matplotlib-cpp library to visualize the iteration process

## Final Deliverables:
- [x] Implementation of Optimization class
- [x] Sample PID controller gains optimization and iteration error figure
- [x] The Unit Testing using google test
- [x] Github README with TravisCI and Coverage of Coveralls
- [ ] Doxygen Documentation
