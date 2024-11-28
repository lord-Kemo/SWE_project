#include "Calculator.h"
#include <algorithm>
#include <cctype>
#include <sstream>
#include <cmath>

Calculator::Calculator() : currentPos(0) {}

double Calculator::evaluate(const std::string& expr) {
    expression = expr;
    currentPos = 0;
    return parseExpression();
}

void Calculator::skipWhitespace() {
    while (currentPos < expression.length() && std::isspace(expression[currentPos])) {
        currentPos++;
    }
}

double Calculator::parseExpression() {
    double result = parseTerm();

    while (currentPos < expression.length()) {
        skipWhitespace();
        char op = expression[currentPos];

        if (op != '+' && op != '-') break;

        currentPos++;
        double term = parseTerm();

        if (op == '+') result += term;
        else result -= term;
    }

    return result;
}

double Calculator::parseTerm() {
    double result = parseFactor();

    while (currentPos < expression.length()) {
        skipWhitespace();
        char op = expression[currentPos];

        if (op != '*' && op != '/' && op != '%') break;

        currentPos++;
        double factor = parseFactor();

        if (op == '*') result *= factor;
        else if (op == '/') {
            if (factor == 0) throw CalculatorError("Division by zero");
            result /= factor;
        }
        else if (op == '%') {
            if (factor == 0) throw CalculatorError("Modulo by zero");
            result = fmod(result, factor);
        }
    }

    return result;
}

double Calculator::parseFactor() {
    skipWhitespace();

    double result;

    if (currentPos >= expression.length()) {
        throw CalculatorError("Unexpected end of expression");
    }

    // Handle negative numbers
    if (expression[currentPos] == '-') {
        currentPos++;
        result = -parseFactor();
    }
        // Handle parentheses
    else if (expression[currentPos] == '(') {
        currentPos++;
        result = parseExpression();
        skipWhitespace();

        if (currentPos >= expression.length() || expression[currentPos] != ')') {
            throw CalculatorError("Missing closing parenthesis");
        }
        currentPos++;
    }
        // Handle functions
    else if (std::isalpha(expression[currentPos])) {
        result = parseFunction();
    }
        // Handle numbers
    else if (std::isdigit(expression[currentPos]) || expression[currentPos] == '.') {
        result = parseNumber();
    }
    else {
        throw CalculatorError("Invalid expression");
    }

    // Handle power operator
    skipWhitespace();
    if (currentPos < expression.length() && (expression[currentPos] == '^' ||
                                             (expression[currentPos] == '*' && currentPos + 1 < expression.length() && expression[currentPos + 1] == '*'))) {
        if (expression[currentPos] == '*') currentPos += 2;
        else currentPos++;
        result = pow(result, parseFactor());
    }

    return result;
}

double Calculator::parseNumber() {
    std::string numStr;

    // Parse integer part
    while (currentPos < expression.length() && std::isdigit(expression[currentPos])) {
        numStr += expression[currentPos++];
    }

    // Parse decimal part
    if (currentPos < expression.length() && expression[currentPos] == '.') {
        numStr += expression[currentPos++];
        while (currentPos < expression.length() && std::isdigit(expression[currentPos])) {
            numStr += expression[currentPos++];
        }
    }

    if (numStr.empty() || numStr == ".") {
        throw CalculatorError("Invalid number format");
    }

    return std::stod(numStr);
}

double Calculator::parseFunction() {
    std::string funcName;
    while (currentPos < expression.length() && std::isalpha(expression[currentPos])) {
        funcName += expression[currentPos++];
    }

    skipWhitespace();
    if (currentPos >= expression.length() || expression[currentPos] != '(') {
        throw CalculatorError("Missing opening parenthesis after function");
    }

    currentPos++; // Skip '('
    double argument = parseExpression();

    skipWhitespace();
    if (currentPos >= expression.length() || expression[currentPos] != ')') {
        throw CalculatorError("Missing closing parenthesis after function argument");
    }

    currentPos++; // Skip ')'
    return evaluateFunction(funcName, argument);
}

double Calculator::evaluateFunction(const std::string& funcName, double value) {
    if (funcName == "sin") return std::sin(value);
    if (funcName == "cos") return std::cos(value);
    if (funcName == "tan") return std::tan(value);
    if (funcName == "abs") return std::abs(value);
    if (funcName == "sqrt") {
        if (value < 0) throw CalculatorError("Square root of negative number");
        return std::sqrt(value);
    }
    if (funcName == "exp") return std::exp(value);
    if (funcName == "ln") {
        if (value <= 0) throw CalculatorError("Natural logarithm of non-positive number");
        return std::log(value);
    }
    if (funcName == "log10") {
        if (value <= 0) throw CalculatorError("Logarithm of non-positive number");
        return std::log10(value);
    }

    throw CalculatorError("Unknown function: " + funcName);
}