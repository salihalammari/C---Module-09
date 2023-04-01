/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:01:35 by slammari          #+#    #+#             */
/*   Updated: 2023/04/01 02:05:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

bool isOperator(const std::string   &token) 
{
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double performOperation(double num1, double num2, const std::string &op) 
{
    if (op == "+") {
        return num1 + num2;
    }
    else if (op == "-") {
        return num1 - num2;
    }
    else if (op == "*") {
        return num1 * num2;
    }
    else if (op == "/") {
        if (num2 == 0) throw std::runtime_error("Can't divide by zero!");
        return num1 / num2;
    }
    else {
        throw std::runtime_error("Invalid operator: " + op);
    }
}

double calculateRPN(const std::string& expression) 
{
    std::stack<double> operands;

    size_t i = 0;
    while (i < expression.size()) {
        // check for whitespace
        if (std::isspace(expression[i])) {
            i++;
            continue;
        }

        // read next token
        size_t j = i + 1;
        while (j < expression.size() && !std::isspace(expression[j])) {
            j++;
        }
        std::string token = expression.substr(i, j - i);

        // evaluate token
        if (isOperator(token)) 
        {
            if (operands.size() < 2) throw std::runtime_error("Not enough operands for operator: " + token);

            double num2 = operands.top();
            operands.pop();

            double num1 = operands.top();
            operands.pop();

            double result = performOperation(num1, num2, token);
            operands.push(result);
        }
        else 
        {
            double operand = std::strtod(token.c_str(), NULL);
            if (errno == ERANGE) throw std::runtime_error("Operand out of range!");

            operands.push(operand);
        }

        i = j;
    }

    if (operands.size() != 1) throw std::runtime_error("Invalid expression!");
    return operands.top();
}
