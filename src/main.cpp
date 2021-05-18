// Copyright 2021 Thomas Kercehval
#include <tclap/CmdLine.h>
#include <string>
#include "operators/operator.hpp"

int main(int argc, char** argv) {
    try {
        // NOLINTNEXTLINE
        TCLAP::CmdLine cmd("Simple proof of concept to demonstrate a command-line interface in C++.");

        // std::vector<std::string> operators = Operator::getOperatorNames();
        TCLAP::SwitchArg addArg(
            "a",
            "add",
            "finds the sum of a series, a + b + ... + n\n",
            false,
            NULL);

        TCLAP::SwitchArg subtractArg(
            "s",
            "subtract",
            "subtracts a series of numbers, a - b - ... - n",
            false,
            NULL);
        TCLAP::SwitchArg multiplyArg(
            "m",
            "multiply",
            "multiplies a series of numbers, a * b * ... * n",
            false,
            NULL);

        TCLAP::OneOf xorArgs;
        xorArgs.add(addArg).add(subtractArg).add(multiplyArg);
        cmd.add(xorArgs);

        TCLAP::UnlabeledMultiArg<float> numsArg(
            "arguments",
            "Numbers to operate upon.",
            true,
            "args");

        cmd.add(numsArg);

        cmd.parse(argc, argv);

        std::vector<float> args = numsArg.getValue();
        // find active command and process it
        for (auto& arg : xorArgs) {
            if (arg->isSet()) {
                TCLAP::SwitchArg* opArg = static_cast<TCLAP::SwitchArg*>(arg);
                std::string opName = opArg->getName();
                auto operatorType = nameToOperatorTypeMap.find(opName)->second;
                Operator* op = Operator::create(operatorType);

                std::cout << op->compute(args) << std::endl;
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
