// Copyright 2021 Thomas Kercehval
#include <tclap/CmdLine.h>
#include "operators/operator.hpp"

int main(int argc, char** argv) {
    try {
        TCLAP::CmdLine cmd("Command description message");

        std::vector<std::string> operators = Operator::getOperatorNames();
        TCLAP::ValuesConstraint<std::string> allowedOperators(operators);
        TCLAP::UnlabeledValueArg<std::string> operatorArg(
            "operator",
            "Operator\n"
            "\tadd\t\tadds two numbers, a + b\n"
            "\tsubtract\tsubtracts two numbers, a - b\n",
            true,
            "add",
            &allowedOperators);

        cmd.add(operatorArg);

        cmd.parse(argc, argv);

        std::string op = operatorArg.getValue();

        return 0;
    } catch (TCLAP::ArgException &e) {
        std::cerr << "error: " << e.error()
                  << " for arg " << e.argId() << std::endl;
    }
}
