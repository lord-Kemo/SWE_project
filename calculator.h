//
// Created by abo-k on 11/22/2024.
//

#ifndef CALCULATOR_CALCULATOR_H
#define CALCULATOR_CALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>
#include <cmath>

class Calculator {
private:
    std::string expression;
    size_t currentPos;

    // Custom exception class for calculator errors
    class CalculatorError : public std::runtime_error {
    public:
        explicit CalculatorError(const std::string& message) : std::runtime_error(message) {}
    };

    // Helper functions for parsing
    double parseExpression();
    double parseTerm();
    double parseFactor();
    double parseFunction();
    double parseNumber();
    void skipWhitespace();
    bool isFunction(const std::string& str) const;

    // Function to evaluate mathematical functions
    double evaluateFunction(const std::string& funcName, double value);

public:
    Calculator();
    double evaluate(const std::string& expr);
};



#endif //CALCULATOR_CALCULATOR_H
