// Copyright 2021 Thomas Kercehval
#ifndef SRC_OPERATORS_OPERATOR_HPP_
#define SRC_OPERATORS_OPERATOR_HPP_
#include <map>
#include <string>
#include <vector>

enum OperatorType {
    ADD,
    SUBTRACT,
    MULTIPLY,
};
std::vector<OperatorType> allOperatorTypes = {
    ADD,
    SUBTRACT,
    MULTIPLY
};
std::map<OperatorType, std::string> operatorTypeToNameMap = {
    {ADD, "add"},
    {SUBTRACT, "subtract"},
    {MULTIPLY, "multiply"},
};
std::map<std::string, OperatorType> nameToOperatorTypeMap = {
    {"add", ADD},
    {"subtract", SUBTRACT},
    {"multiply", MULTIPLY},
};

class Operator;
class Operator {
 public:
    virtual ~Operator() = 0;
    virtual float compute(const std::vector<float> &) = 0;

    static std::vector<std::string> getOperatorNames();
    static Operator* create(OperatorType type);
};

#include "add.hpp"
#include "subtract.hpp"
#include "multiply.hpp"

std::vector<std::string> Operator::getOperatorNames() {
    std::vector<std::string> vec = {};
    for (std::map<
        std::string,
        OperatorType
      >::iterator it = nameToOperatorTypeMap.begin();
      it != nameToOperatorTypeMap.end();
      ++it) {
        vec.push_back(it->first);
    }
    return vec;
}

Operator::~Operator() {}

Operator* Operator::create(OperatorType type) {
    switch (type) {
    case OperatorType::ADD:
        return new Add();
    case OperatorType::SUBTRACT:
        return new Subtract();
    case OperatorType::MULTIPLY:
        return new Multiply();
    default:
        return NULL;
    }
}

#endif  // SRC_OPERATORS_OPERATOR_HPP_
