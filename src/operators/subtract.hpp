// Copyright 2021 Thomas Kercehval
#ifndef SRC_OPERATORS_SUBTRACT_HPP_
#define SRC_OPERATORS_SUBTRACT_HPP_
#include <iostream>
#include <vector>
#include "operator.hpp"

class Subtract;

class Subtract: public Operator {
    ~Subtract() {}
    void compute(const std::vector<float> &) override;
};

void Subtract::compute(const std::vector<float> &args) {
    float total = args[0];
    for (std::vector<float>::size_type i = 1; i < args.size(); ++i) {
        total -= args[i];
    }
    std::cout << total << std::endl;
}

#endif  // SRC_OPERATORS_SUBTRACT_HPP_
