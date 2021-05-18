// Copyright 2021 Thomas Kercehval
#include <tclap/CmdLine.h>
#include <string>
#include "operators/operator.hpp"

int main(int argc, char** argv) {
    try {
        TCLAP::CmdLine cmd("Command description message");

        // std::vector<std::string> operators = Operator::getOperatorNames();
        TCLAP::ValueArg<std::string> addArg(
            "a",
            "add",
            "adds numbers together, a + b + ... + n\n",
            false,
            "add",
            "add");

        TCLAP::ValueArg<std::string> subtractArg(
            "s",
            "subtract",
            "subtracts two numbers, a - b - ... - n",
            false,
            "subtract",
            "subtract");

        TCLAP::OneOf xorArgs;
        xorArgs.add(addArg).add(subtractArg);
        cmd.add(xorArgs);

        cmd.parse(argc, argv);

        // find active command and process it
        for (auto& arg : xorArgs) {
            if (arg->isSet()) {
                std::string opName  = static_cast<
                    TCLAP::ValueArg<std::string>*
                >(arg)->getValue();
                auto operatorType = nameToOperatorTypeMap.find(opName)->second;
                Operator* op = Operator::create(operatorType);

                op->compute();
                delete op;
                break;
            }
        }

        return 0;
    } catch (TCLAP::ArgException &e) {
        std::cerr << "error: " << e.error()
                  << " for arg " << e.argId() << std::endl;
    }
}
