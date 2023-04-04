/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:01:06 by slammari          #+#    #+#             */
/*   Updated: 2023/03/31 20:10:09 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int issignoperator(char sign) 
{
    if (sign == '+' || sign == '-' || sign == '*' || sign == '/')
        return 1;
    return 0;
}

int calc_operation(int num1, int num2, int sign) 
{
    if (sign == '+') {
        return num1 + num2;
    }
    else if (sign == '-') {
        return num1 - num2;
    }
    else if (sign == '*') {
        return num1 * num2;
    }
    else if (sign == '/') {
        if (num2 == 0) throw std::runtime_error("Can't divide by zero!");
        return num1 / num2;
    }
    else {
        throw std::runtime_error("Invalid signerator: " + sign);
    }
}

int chekisdigit(char num)
{
    if (num >= 0 && num <= 9)
        return 1;
    return 0;
}

int check_input(char num)
{
    if (chekisdigit(num) || issignoperator(num))
        return 1;
    return 0;
}

int main(int arc, char **arv) 
{
    if (arc != 2)
        std::cerr << "need more param" << std::endl;
    std::stack<int> _stack;
    std::string value = arv[1];
    for (int i = 0; value[i] != '\0' ; ++i)
    {
        char value_input = value[i];
        if (value_input == ' ')
            continue;
        if (check_input(value_input))
            std::cerr <<"Error" << std::endl;
        if (issignoperator(value_input))
        {
            int a, b;
            if (_stack.size() < 2)
                std::cerr << "Error" << std::endl;
            a = _stack.top(); _stack.pop();
            b = _stack.top(); _stack.pop();
            _stack.push(calc_operation(b,a, value_input));
        }
        else 
            _stack.push(value_input - '0');
    }
    if (_stack.size() != 1)
        std::cerr << "Error" << std::endl;
    std::cout << _stack.top() << std::endl;
}
