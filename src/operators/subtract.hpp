// Copyright 2021 Thomas Kercehval
#ifndef SRC_OPERATORS_SUBTRACT_HPP_
#define SRC_OPERATORS_SUBTRACT_HPP_
#include <iostream>
#include "operator.hpp"

class Subtract;

class Subtract: public Operator {
    ~Subtract() {}
    void compute() override;
};

void Subtract::compute() {
    std::cout << "In sub" << std::endl;
}

#endif  // SRC_OPERATORS_SUBTRACT_HPP_
