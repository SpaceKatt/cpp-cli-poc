// Copyright 2021 Thomas Kercehval
#ifndef SRC_OPERATORS_SUBTRACT_HPP_
#define SRC_OPERATORS_SUBTRACT_HPP_
#include <iostream>
#include <vector>
#include "operator.hpp"

class Subtract;

class Subtract: public Operator {
    ~Subtract() {}
    float compute(const std::vector<float> &) override;
};

float Subtract::compute(const std::vector<float> &args) {
    float total = args[0];
    for (std::vector<float>::size_type i = 1; i < args.size(); ++i) {
        total -= args[i];
    }
    return total;
}

#endif  // SRC_OPERATORS_SUBTRACT_HPP_
