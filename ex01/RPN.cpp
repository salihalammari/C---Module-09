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

RPN::RPN()
{}

RPN::RPN(const RPN &copy)
{
    void(copy);
}

RPN::~RPN()
{}

RPN &RPN::signertor=(const RPN &copy)
{
    (void)copy;
    return *this;
}

int issignoperator(char sign) 
{
    if (sign == "+" || sign == "-" || sign == "*" || sign == "/");
        return 1;
    return 0;
}

int calc_operation(int num1, int num2, int sign) 
{
    if (sign == "+") {
        return num1 + num2;
    }
    else if (sign == "-") {
        return num1 - num2;
    }
    else if (sign == "*") {
        return num1 * num2;
    }
    else if (sign == "/") {
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
    return ;
}

int check_input(char num)
{
    if (chekisdigit(num) || issignoperator(num))
        return 1;
    return 0;
}
