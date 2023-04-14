/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 21:01:06 by slammari          #+#    #+#             */
/*   Updated: 2023/04/14 01:43:21 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"


int sign_operator(char sign) 
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
        if (num2 == 0){
            std::cerr << "Can't divide by zero!" << std::endl;
            exit(1);
        }
        return num1 / num2;
    }
    else {
        std::cerr << "Invalid signerator: " << sign << std::endl;
    }
    return 1;
}

int check (std::string inp){
    
    for (size_t i = 0; i < inp.size(); i++){
        if (!isdigit(inp[i]))
            if (inp[i] != '+')
                if (inp[i] != '-')
                    if (inp[i] != '*')
                        if (inp[i] != '/')
                            if (inp[i] != ' ')
                                return (1);
    }
    return (0);
}

int main(int arc, char **av) 
{
    int cnt = 0;
    if (arc != 2)
        std::cerr << "need more param" << std::endl;   
    else{
        if (check(av[1]) == 1){
            std::cerr << "error1" << std::endl;
            return (1);
        }
        std::stack<int> _stack;
        std::string value = av[1];
        
        for (int i = 0; value[i] != '\0' ; ++i)
        {
            char value_input = value[i];
            if (value_input == ' ')
                continue;
            cnt++;
            if (sign_operator(value_input))
            {
                int a, b;
                if (_stack.size() < 2)
                {
                    std::cerr << "Error2" << std::endl;
                    return (1);
                }
                a = _stack.top(); _stack.pop();
                b = _stack.top(); _stack.pop();
                _stack.push(calc_operation(b,a, value_input));
            }
            else 
                _stack.push(value_input - '0');
        }
        if (_stack.size() != 1 || cnt <= 1){
            std::cerr << "Error3" << std::endl;
            return (1);
        }
        std::cout << _stack.top() << std::endl;
        }
}
