// Copyright 2021 Thomas Kercehval
#ifndef SRC_OPERATORS_OPERATOR_HPP_
#define SRC_OPERATORS_OPERATOR_HPP_
#include <map>
#include <vector>
#include <string>

enum OperatorType {
    ADD,
    SUBTRACT,
};
std::vector<OperatorType> allOperatorTypes = {
    ADD,
    SUBTRACT
};
std::map<OperatorType, std::string> operatorTypeToNameMap = {
    {ADD, "add"},
    {SUBTRACT, "subtract"},
};
std::map<std::string, OperatorType> nameToOperatorTypeMap = {
    {"add", ADD},
    {"subtract", SUBTRACT},
};

class Operator;
class Operator {
 public:
    virtual ~Operator() = 0;
    virtual void compute() = 0;

    static std::vector<std::string> getOperatorNames();
    static Operator* create(OperatorType type);
};

#include "add.hpp"
#include "subtract.hpp"

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
    default:
        return NULL;
    }
}

#endif  // SRC_OPERATORS_OPERATOR_HPP_
