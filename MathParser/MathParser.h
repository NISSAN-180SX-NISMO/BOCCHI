#pragma once
#include <string>
#include <iomanip>
#include "PostfixNotationComputer.h"
#include "PostfixNotationConverter.h"

namespace MathParser {
    long double eval(const std::string& equation);

    class Function {
    private:
        std::string function;
        std::string replacex(long double x) {
            std::stringstream stream;
            stream << std::fixed << std::setprecision(15) << x;
            std::string x_str = stream.str();
            std::string expression;
            for (char ch : function)
                expression += ch == 'x' ? x_str : std::string(1,ch);
            return expression;
        }
    public:
        Function(std::string function) {
            this->function = function;
        }
        long double operator()(long double x) {
            std::fixed(std::cout);
            std::string expression = replacex(x);
            return eval(expression);
        }
        long double df(long double x){
            long double h = 0.00000001;
            return (this->operator()(x + h) - this->operator()(x - h)) / (2 * h);
        }
    };

    long double eval(const std::string& equation){
        PostfixNotationComputer computer(equation);
        return computer.Calc();
    }

}
