// Copyright 2021 Thomas Kercehval
#ifndef SRC_OPERATORS_MULTIPLY_HPP_
#define SRC_OPERATORS_MULTIPLY_HPP_
#include <iostream>
#include <vector>
#include "operator.hpp"

class Multiply;

class Multiply: public Operator {
    ~Multiply() {}
    void compute(const std::vector<float> &) override;
};

void Multiply::compute(const std::vector<float> &args) {
    float total = args[0];
    for (std::vector<float>::size_type i = 1; i < args.size(); ++i) {
        total *= args[i];
    }
    std::cout << total << std::endl;
}

#endif  // SRC_OPERATORS_MULTIPLY_HPP_

