// Copyright 2021 Thomas Kercehval
#ifndef SRC_OPERATORS_ADD_HPP_
#define SRC_OPERATORS_ADD_HPP_
#include <iostream>
#include "operator.hpp"

class Add;

class Add: public Operator {
    ~Add() {}
    void compute() override;
};

void Add::compute() {
    std::cout << "In add" << std::endl;
}

#endif  // SRC_OPERATORS_ADD_HPP_
